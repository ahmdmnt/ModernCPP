/*
 * _60_Concurrency_ThreadFunctionsNamespace.cpp
 *
 *  Created on: Jun 1, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <thread>
#include <Windows.h>

/* Module Description:-
 * ---------------------
 * 	1.
 *
 */


void myProcess() {
	// My Empty Process...
}


void _60_Concurrency_ThreadFunctionsNamespace() {

	std::thread myThread(myProcess);

	// Returns a platform-specific handle to the thread. ((Windows: HANDLE "Windows API" -- Linux: pthread_t "POSIX Thread"))
	std::cout<< "Native_Handle: " << myThread.native_handle() << std::endl;
	// Set Thread Descriptioin using Window Library,, in Linux (pthread_setname_np) system call.
	// HANDLE myHandle = myThread.native_handle();
	// SetThreadDescription(myHandle, L"myThread");			// Only with MSVC Compiler

	// Get ID of a thread
	auto id = myThread.get_id();
	std::cout << "Thread 01 ID: " << id << std::endl;

	// Check number of cores,, Number of thread should be equal to number of cores, to maximize usage of CPU.
	auto cores = std::thread::hardware_concurrency();
	std::cout << "Number of Cores: " << cores << std::endl;

	// Check current thread information this_thread
	std::cout << "This Thread ID: " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3)); 	// can make delay with any other units

	myThread.join();
}


