/*
 * _62_HighLevelConcurrency_PromisExample.cpp
 *
 *  Created on: Jun 9, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <thread>
#include <future>

/* std::promise:
* --------------
* - Provide way to store a value or an exception.
* - This is called the shared state.
* - The state can be accessed later by another thread through a future object.
* - Promise/Future are two end-points of communication channel.
* - One operation store the value in a promise, and another operation will retrieve it through a future asynchronously.
* - These OPERATIONS ARE SYNC. >>> they are thread safe.
* - Promise object can be used only one.
*/

int operationTask_passPromise(std::promise<int>& countData) {
	int sum {0};
	std::cout<< "Operation Thread() is started!" << std::endl;
	auto futureCountData = countData.get_future();		// Wait for Promise Data to be ready and receive it in Future Object.
	std::cout<< "... Waiting for Count Data" << std::endl;
	auto intCount = futureCountData.get();				// Get Future Object Data value -- CAN ONLY BE GET ONCE
	std::cout<< "... Acquired Count Data" << std::endl;

	for(int itr{}; itr<intCount; ++itr) {
		sum += itr;
		std::cout<< '.';
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

	return sum;
}
int operationTask_passFuture(std::future<int>& countData) {
	int sum {0};
	auto intCount = countData.get();
	for(int itr{}; itr<intCount; ++itr) {
		sum += itr;
		std::cout<< '.';
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

	return sum;
}


void _62_HighLevelConcurrency_PromiseExample() {

	/** Main Thread:
	 * I need to move a data for a thread, the thread after being created will be waiting for the neeeded data until it is being set,
	 * then it can be able to use it.
	 */
	std::cout<< "Main Thread() is started!" << std::endl;
	std::promise<int> promiseData;
	std::future<int> threadResult = std::async(std::launch::async, operationTask_passPromise, std::ref(promiseData));

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	// Main Here Set the Promise Data -- CAN ONLY BE SET ONCE
	promiseData.set_value(10);

	if(threadResult.valid()) {
		auto sum = threadResult.get();
		std::cout<< "OperationTask Sum = " << sum << std::endl;
	}


	/******************************************************** Future Example:: Same as Promise but here
	 * handling of Promise in the Main Thread */
//	std::cout<< "Main Thread() is started!" << std::endl;
//	std::promise<int> promiseData;
//	std::future<int> futureData = promiseData.get_future();
//	std::future<int> threadResult = std::async(std::launch::async, operationTask_passFuture, std::ref(futureData));
//
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//
//	// Main Here Set the Promise Data -- CAN ONLY BE SET ONCE
//	promiseData.set_value(10);
//
//	if(threadResult.valid()) {
//		auto sum = threadResult.get();
//		std::cout<< "OperationTask Sum = " << sum << std::endl;
//	}

}

//int main() {_62_HighLevelConcurrency_PromiseExample();}

