/*
 * _59_Concurrency_Mutex_LockGuard.cpp
 *
 *  Created on: Jun 1, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <thread>
#include <list>
#include <mutex>

/**
 *  std::mutex():
 * --------------
 * Mutex is resource guard that prevent using a certain process, until it make sure it is not used by another process.
 * by the mechanism of Lock/Unlock.
 *
 * NOTE:
 * I NEED TO MAKE SURE MUTEX HAS BE UNLOCK BEFORE THE PROCESS FINISH EXECUTION.
 */

/**
 * std::lock_guard()
 * -----------------
 * Lock Guard uses the Feature: RAII: Resource Acquisition is Initialization.
 * by creating the lock_guard ,,, resource will be acquired, and be end of code, it will be destoryed automatically.
 */

/**
 * The Drawback here,
 * The thread will be waiting if the mutex is locked,
 * even if the CPU is idle and no process is running, but the mutex is locked,
 * the process that needs that Mutex will be in sleep state until this mutex is released.
 *
 * Conclusion: this might not be good practice for CPU Utilization.
 */
std::mutex gDownloadMutex;
void download(std::list<int>& filename, const int SIZE) {
	for(int itr{0}; itr<SIZE; ++itr) {
		gDownloadMutex.lock();
		filename.push_back(itr*2);
		gDownloadMutex.unlock();
	}
	std::cout<< "[" <<  std::this_thread::get_id() <<"] Child Thread, finished successfully!" << std::endl;
}

void download_lockGuard(std::list<int>& filename, const int SIZE) {
	/**
	 * Lock Guard will be automatically destroyed at end of code, even if i didn't call it explicitly. */
	for(int itr{0}; itr<SIZE; ++itr) {
		std::lock_guard<std::mutex> mtx(gDownloadMutex);		// be defining the Mutex Lock Guard, it will lock that mutex, and by default it will be destroyed.
		filename.push_back(itr*2);
	}
	std::cout<< "[" <<  std::this_thread::get_id() <<"] Child Thread, finished successfully!" << std::endl;
}

void _59_Concurrency_Mutex() {

	const int fileTotalSize {20'000};
	const int fileSize 		{fileTotalSize/2};
	std::list<int> file;

	// Two Created, thread to speed up download process, what might occur here, race condition
	// the file is not downloaded correctly --> HERE I MIGHT FACE ISSUE: Mutex was not unlock before process finish execution
	std::thread th1_DownloaderFile(download, std::ref(file), std::cref(fileSize));
	std::thread th2_DownloaderFile(download, std::ref(file), std::cref(fileSize));

	if(th1_DownloaderFile.joinable()) {
		th1_DownloaderFile.join();
	}
	if(th2_DownloaderFile.joinable()) {
		th2_DownloaderFile.join();
	}

	if(file.size() == fileTotalSize) {
		std::cout<< "File downloaded Successfully! Total Size: " << file.size() << std::endl;
	}
}


void _59_Concurrency_LockGuard() {

	const int fileTotalSize {20'000};
	const int fileSize 		{fileTotalSize/2};
	std::list<int> file;

	// Lock Guard will make sure mutex is destoryed by end of function/thread execution.
	std::thread th1_DownloaderFile(download_lockGuard, std::ref(file), std::cref(fileSize));
	std::thread th2_DownloaderFile(download_lockGuard, std::ref(file), std::cref(fileSize));

	if(th1_DownloaderFile.joinable()) {
		th1_DownloaderFile.join();
	}
	if(th2_DownloaderFile.joinable()) {
		th2_DownloaderFile.join();
	}

	if(file.size() == fileTotalSize) {
		std::cout<< "File downloaded Successfully! Total Size: " << file.size() << std::endl;
	}
}

void _59_Concurrency_Mutex_LockGuard() {

	_59_Concurrency_Mutex();
	_59_Concurrency_LockGuard();

	std::cout<< "[" <<  std::this_thread::get_id() <<"] Main Thread, finished successfully!" << std::endl;
}
