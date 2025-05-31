/*
 * _58_ConcurrencyBasics.cpp
 *
 *  Created on: May 31, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <list>

/**
 *  C++ Concurrency:-
 * ------------------
 * When multiple operations are executing simultaneously.
 *  - Required for Large applications, have multiple components
 *  - Some component may need to be executed concurrently.
 *  - Achieved by creating multiple threads in code.
 *  - C++11 support concurrency.
 *  - Include utilities that support, starting/managing threads.
 *  - Allow Efficient usage for CPU, and Application be more responsive.
 *  - So when u have multiple tasks need to be performed, it is better to separate the code
 *    in multiple threads to have better user experience.
 *****************************************************************************************************************************************************/


/**
 * Threads in C++:
 * ----------------
 * - Accept a callable as constructor argument, callable is any kind of callback.
 * - The callable is then executed in a separated thread.
 * - The constructor function does NOT wait for the thread to start;
 *   it returns immediately, the the new thread can start.
 * - #include <thread>
 *
 * TOPICS:-
 * --------
 *  1. Joinable thread.
 *  2. Detached thread.
 *
 *  HINT:
 *  Remember a joinable thread can be made detached but once a thread is detached,
 *  it can never become joinable again.
 */

constexpr int SIZE {5'000'000};
std::list<int> gData;

void download() {
	std::cout<< "[Downloader]: Started downloading.. " << std::endl;
	for(size_t itr{0}; itr<SIZE; ++itr) {
		gData.push_back(itr*2);
	}
	std::cout<< "[Downloader]: Finished downloading.. " << std::endl;
}
void upload(std::string filename) {
	std::cout<< "[Uploader]: Started " << filename <<  " uploading.. " << std::endl;
	for(size_t itr{0}; itr<SIZE; ++itr) {
		gData.push_back(itr*2);
	}
	std::cout<< "[Uploader]: Finished " << filename <<  " uploading.. " << std::endl;
}

void _58_ConcurrencyBasics_JoinableThread() {
	std::cout<< "[Main] JoinableThread is started..." << std::endl;
	std::thread thDownloader(download);			// download() will be executed in another thread.

	if(thDownloader.joinable()) {					// Check if the thread is joinable or not.
		thDownloader.join();						// used to make sure, Main Thread doesn't terminate "blocked" before/until download thread is finished.
		// if not adding join(), the code might terminate before downloader() function is finished.
	}
	std::cout<< "[Main] JoinableThread is finished..." << std::endl;
}

void _58_ConcurrencyBasics_DetachThread() {
	std::cout<< "[Main] DetachThread is started..." << std::endl;
	std::thread thDownloader(download);			// download() will be executed in another thread.
	thDownloader.detach();						// detached thread, does not have the ability to be use join.

	std::cout<< "[Main] DetachThread is finished..." << std::endl;
	//system("Pause");		// make sure any detached child thread, is executed to end.
}

void _58_ConcurrencyBasics_ArgumentsWithThread() {
	std::cout<< "[Main] Arguments with Thread is started..." << std::endl;

	std::string file {"Vocab.pdf"};							// normal reference
	std::thread thUploader1(upload, std::ref(file));		// std::ref(): TO INSURE, NO EXTRA Copies will be created when passing argument

	const std::string constFile {"Vocab.pdf"};				// constant reference
	std::thread thUploader2(upload, std::cref(constFile));	// std::cref(): TO INSURE, NO EXTRA Copies will be created when passing argument


	if(thUploader1.joinable() && thUploader2.joinable()) {
		thUploader1.join();
		thUploader2.join();
	}
	std::cout<< "[Main] Arguments with Thread is finished..." << std::endl;
}
/*****************************************************************************************************************************************************/

/**
 * Packaged Task in C++:
 * ----------------
 * - Wrapper for a callable, callable any pointer to function.
 * - Then u can invoke the callable by new task wrapper name created.
 * - if u need to check the ReturnValue of PackagedTask, u need to create future Object.
 *
 * Steps:
 * ------
 *  1. Wrap the Function in Packaged Task.
 *  2. Create the Future Object for Wrapped Packaged task.
 *  3. Call the Wrapped task from std::thread.
 *  4. Fetch result from future Object, will be blocking code until result is available.
 *  5. DONT FORGET: to add childTask.join() at end of Main Thread.
 *
 * [SYNTAX]:
 * 		std::packaged_task<FUNCTION_SIGNATURE> taskName {functionName};
 * 		std::future<ReturnType> futureName = taskName.get_future();
 * 		retValue == futureName.get()
 */
int addFu(int n1, int n2) {
	std::cout<< "[AddFunction] is  started! ThreadID: " << std::this_thread::get_id() << "..." << std::endl;
	std::cout<< "[AddFunction] is finished! ThreadID: " << std::this_thread::get_id() << "..." << std::endl;
	return n1+n2;
}
int computeFu(const std::vector<int>& l_vecVariable) {
	using namespace std;
	cout<< "[ComputeFunction] is started! ThreadID: " << std::this_thread::get_id() << "..." << endl;

	int sum {0};
	for(const auto& element: l_vecVariable) {
		sum += element;
		std::this_thread::sleep_for(1s);	// Only delay to make this thread take time.
		cout<< ".";
	}
	cout<< endl << "[ComputeFunction] is finished! ThreadID: " << std::this_thread::get_id() << "..." << std::endl;;
	return sum;
}

void _58_ConcurrencyBasics_ReturnValuesFromThread() {
	std::cout<< "[Main] Return Values from Thread is started! ThreadID: " << std::this_thread::get_id() << "..." << std::endl;

	std::packaged_task<int(int, int)> addTask {addFu};		// Create task from function
	std::future<int> ftAddTask = addTask.get_future();		// Object where Task Return Values can be saved.
	addTask(10, 23);										// Direct Call, no threads are created.
	std::cout << "Add Function Result = " << ftAddTask.get() << std::endl;		// fetch return value.


	std::packaged_task<int(const std::vector<int>&)> computeTask {computeFu};		// Task to create separate thread for callable.
	std::future<int> ftComputeTask = computeTask.get_future();						// Object where Task Return Values can be saved.

	std::vector<int> myVector {1,2,3,4,5,6,7,8,9,10};
	//computeTask(myVector);														// Task Direct call ,, no separate thread is created
	std::thread threadComputeTask {std::move(computeTask), myVector};
	auto result = ftComputeTask.get();												// fetch return value, WILL BE BLOCKING THE CODE, until Thread finishes executing!
	std::cout << "Compute Function Result = " << result << std::endl;

	threadComputeTask.join();
	std::cout<< "[Main] Return Values from Thread is finished! ThreadID: " << std::this_thread::get_id() << "..." << std::endl;
}

void _58_ConcurrencyBasics() {

//	_58_ConcurrencyBasics_JoinableThread();
//	_58_ConcurrencyBasics_DetachThread();
//	_58_ConcurrencyBasics_ArgumentsWithThread();
	_58_ConcurrencyBasics_ReturnValuesFromThread();

}



