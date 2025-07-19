/*
 * _61_HighLevelConcurrency_TaskBased.cpp
 *
 *  Created on: Jun 1, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <list>
#include <thread>
#include <future>

/* Module Description:-
 * ---------------------
 * 	1.
 *
 */

void download(const int SIZE) {
	for(int itr{0}; itr<SIZE; ++itr) {
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	std::cout << std::endl;
	std::cout<< "[" <<  std::this_thread::get_id() <<"] Child {download} Thread, finished successfully!" << std::endl;
}
int computeOperations(const int NUMBER) {

	int sum {0};
	for(int itr{0}; itr<NUMBER; ++itr) {
		sum += itr;
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	std::cout << std::endl;
	std::cout<< "[" <<  std::this_thread::get_id() <<"] Child {computeOperations} Thread, finished successfully!" << std::endl;
	return sum;
}


void _61_HighLevelConcurrency_getExample() {
	std::future<void> downloadTask = std::async(download, 10);				// A Task will be run in a thread.
	downloadTask.get();			// Force main to wait for task until it finishes execution:: same like .join()


	std::future<int> computeOperationsTask = std::async(std::launch::async, computeOperations, 30);		// A Task will be run in a thread.
	if(computeOperationsTask.valid()) {									// To make sure that the shared state is valid, not destroyed.
		auto result = computeOperationsTask.get();						// Once you call .get() the shared state is destroyed and u can not get it again.
		std::cout<< "result= " << result << std::endl;
	}
}void _61_HighLevelConcurrency_waitExample() {
	std::future<int> computeOperationsTask = std::async(std::launch::async, computeOperations, 30);		// A Task will be run in a thread.
	if(computeOperationsTask.valid()) {									// To make sure that the shared state is valid, not destroyed.
		computeOperationsTask.wait();									// Will have same behavior of wait, except it doesn't return the shared state value.
	}
}
void _61_HighLevelConcurrency_waitForUntilExample() {
	std::future<int> computeOperationsTask2 = std::async(std::launch::async, computeOperations, 30);
	if(computeOperationsTask2.valid()) {

		/* using wait_for(duration) */
		auto taskStatus = computeOperationsTask2.wait_for(std::chrono::milliseconds(10));		// Below Code describe different result behavior and it is good in while loop

		/* using wait_until(time point) */
		//		auto timePoint = std::chrono::system_clock::now() + std::chrono::milliseconds(10);
		//		auto taskStatus = computeOperationsTask2.wait_until(timePoint);

		switch(taskStatus) {
		case std::future_status::deferred:
			std::cout<< "This Task is executing Synchronously" << std::endl;
			break;
		case std::future_status::timeout:
			std::cout<< "This Task is still running, shared state not ready!" << std::endl;
			break;
		case std::future_status::ready:
			std::cout<< "This Task is finished, shared state is ready!" << std::endl;
			break;
		}
	}
}

void _61_HighLevelConcurrency_TaskBased() {

	/**
	 * std::async():
	 * -------------
	 * Function used to execute a function as a task instead of a thread. and it is declared in header file: future.
	 * - it is a callable function that accept function pointer with it arguments.
	 * - std::async() returns an object, that will be saved in a future object.
	 * - type of future is decalared as return type of function.
	 * -  You can pass argument, by value or by reference use std::ref()
	 */

	/**
	 * std::future():
	 * --------------
	 * Used for communication between threads,
	 * - Has a shared state that can be accessed in different threads.
	 * - Created through std::promise object.
	 * 		- created by std::async, that directly return std::future object.
	 * 		- std::promise is an input channel.
	 * 		- std::future is an output channel.
	 * - The thread that reads shared state will wait until the future is ready (future where the shared state is shared with).
	 * - Promise/Future pairs allow safe data sharing without requiring explicit synchronization.
	 *
	 * Launch Policy:
	 * ---------------
	 * It decide the behavior of async function..
	 * - deferred: Task will be executed synchronously.
	 * - async   : Task will be executed asynchronously.
	 *
	 * IMPORTANT:
	 * If you call std::async without a launch policy, this might not always create a new thread "Compiler Dependent".
	 * - You have to explicity add LaunchPolicy to force thread creation.
	 * - If no thread can not be created, system_error exception will be thrown.
	 *
	 *
	 * Some Future Methods:-
	 * ----------------------
	 * - .get()  : wait for the child process to finish execution and get the shared state value.
	 * - .wait() : Only wait for the child process to finish execution.
	 * Both get()/wait() Block the calling thread until shared state is computed.
	 * what if i want only to periodically check if shared state is computed, without blocking calling thread:
	 * - wait_for()   : accept a duration,, then return the state of wait .. good in loop checking
	 * - wait_until() : accept a actual time point,,
	 */


	_61_HighLevelConcurrency_getExample();
	_61_HighLevelConcurrency_waitExample();
	_61_HighLevelConcurrency_waitForUntilExample();

	std::cout<< "[" <<  std::this_thread::get_id() <<"] Main Thread, finished successfully!" << std::endl;
}

//int main() {_61_HighLevelConcurrency_TaskBased();}
