/*
 * _28_ExceptionHandling.cpp
 *
 *  Created on: May 13, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Exception Handling:-
 * ---------------------
 * used to force the caller, to check whether the code has successfully executed for not.
 * - give the SW more robustness.
 * - Mechanism that handles errors in runtime.
 * - these errors are called as exception.
 * - Require immediate handling by program, if not sw will crash.
 * - cannot be ignored.
 *
 *	try {..}
 *	block of code where code that can cause exception in SW.
 *	> it could be statements, function calls, other try blocks.
 *	  try blocks can throw also exceptions by statement throw().
 *	 IF Exception happens, it will jump directly to catch block.
 *
 *	catch {..}
 *	catch handler responsible for catching exceptions,
 *	should appear directly below try {} block.
 *	multiple catch blocks can exists after a try {} block.
 *
 */


#define MAX_RECORDS_SIZE	40

void NOT_GOOD_PRACTICEprocessHeapRecords(long int count);
void processHeapRecords(int count) {

	// Out-of-Range Exception
	if(MAX_RECORDS_SIZE < count) {
		throw std::out_of_range("[EXCEPTION ERR]: Count is Greater than MAX_RECORDS_SIZE!");
	}

	int *pArr = (int*)malloc(count*sizeof(int));		// if [new] is used ... std::bad_alloc is thrown automatically.
	if(nullptr==pArr) {
		throw std::runtime_error("[EXCEPTION ERR]: Failed to Allocation Heap Memory!");
	}

	for(auto i=0; i<count; i++) {
		pArr[i] = i*2;
	}
	free(pArr);
}
/***************************************************************************************************/

void _28_ExceptionHandling() {

	// Handling Exception -- FORCED HANDLING OR THE CODE WILL CRASH.
	try {
		//		processHeapRecords(39);
		processHeapRecords(50);
		//		processHeapRecords(2147483648);

		std::cout<< "Heap Memory Successfully Allocated." << std::endl;
	}
	catch(std::out_of_range &l_exp) {				// CATCH OUT_OF_RANGE EXCEPTION ONLY
		std::cout<< l_exp.what() << std::endl;
	}
	catch(std::runtime_error &l_exp) {				// CATCH RUNTIME EXCEPTION ONLY
		std::cout<< l_exp.what() << std::endl;
	}
	catch(std::exception &l_exp) {					// CATCH ALL STD EXCEPTIONS
		std::cout<< l_exp.what() << std::endl;
	}
	catch(...) {									// CATCH ANY EXCEPTION WITHOUT GIVING ITS DETAILS
		std::cout<< "EXCEPTION!" << std::endl;
	}

}

/***************************************************************************************************/
void NOT_GOOD_PRACTICEprocessHeapRecords(long int count) {

	int *pArr = (int*)malloc(count*sizeof(int));

	if(nullptr==pArr) {
		std::cout << "Failed to Allocate..." << std::endl;
		return;
	}
	for(auto i=0; i<count; i++) {
		pArr[i] = i*2;
	}
	free(pArr);
}
