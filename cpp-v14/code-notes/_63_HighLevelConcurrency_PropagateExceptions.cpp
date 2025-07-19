/*
 * _63_HighLevelConcurrency_PropagateExceptions.cpp
 *
 *  Created on: Jun 9, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <thread>
#include <future>


int operationTask_passPromiseException(std::promise<int>& countData) {
	int sum {0};
	std::cout<< "Operation Thread() is started!" << std::endl;
	auto futureCountData = countData.get_future();		// Wait for Promise Data to be ready and receive it in Future Object.

	try {
		std::cout<< "... Waiting for Count Data" << std::endl;
		auto intCount = futureCountData.get();				// Get Future Object Data value -- CAN ONLY BE GET ONCE -- CAN CATCH EXCEPTION
		std::cout<< "... Acquired Count Data" << std::endl;

		for(int itr{}; itr<intCount; ++itr) {
			sum += itr;
			std::cout<< '.';
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
	}
	catch (std::exception &threadException) {
		std::cout<< "[Task Exception] :: " << threadException.what() << std::endl;
	}

	return sum;
}


void _63_HighLevelConcurrency_PropagateExceptions() {

	/** Main Thread:
	 * I need to move a data for a thread, the thread after being created will be waiting for the neeeded data until it is being set,
	 * then it can be able to use it.
	 */
	std::cout<< "Main Thread() is started!" << std::endl;
	std::promise<int> promiseData;
	std::future<int> threadResult = std::async(std::launch::async, operationTask_passPromiseException, std::ref(promiseData));

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	// Main Here Set the Promise Data -- And Exception will be thrown
		// For Testing Purpose
	try {
		throw std::runtime_error{"Data not available!"};
		promiseData.set_value(10);

		if(threadResult.valid()) {
			auto sum = threadResult.get();
			std::cout<< "OperationTask Sum = " << sum << std::endl;
		}
	}
	catch (std::exception &threadException) {
		promiseData.set_exception(std::make_exception_ptr(threadException));	// Accept Pointer to Exception Object.
	}
}

//int main() {_63_HighLevelConcurrency_PropagateExceptions();}

