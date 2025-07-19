/*
 * _29_ExceptionHandling_P2.cpp
 *
 *  Created on: May 15, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>

/* Module Description:-
 * ---------------------
 * 	1. Stack Unwinding:
 * 	--------------------
 *	is the process that occurs when an exception is thrown and not caught in the current function.
 *	The runtime system starts "unwinding" the call stack—meaning it begins to destroy all local objects
 *	in reverse order of their construction—until it finds a suitable catch block to handle the exception.
 *
 *	RECOMMENDATION:
 *	You should avoid manual memory management as far as possible
 *	because it needs extreme care to ensure that the memory is not leaked.
 *	But by using smart pointers we absolve ourself from the responsibility of freeing the memory ourselves.
 *	-> Bottom line is always use smart pointers.
 *
 *	2. Nested Exception:
 *	---------------------
 *	.... NOT DONE YET ....
 */


class testClass {
public:
	testClass() {
		std::cout<< "testClass() .. Resource Acquired!" << std::endl;
	}
	~testClass() {
		std::cout<< "testClass() .. Resource Released!" << std::endl;
	}
};

#define MAX_RECORDS_SIZE	5
void processClassRecords(int count) {

	// If Normal Stack Variable is used
	//testClass myTestClass;						// The Class will be acquired and successfully released when exception occurred. [OK].
													// , because of normal stack unwinding.

	// If Heap Variable is used
	//testClass* myTestClass = new testClass;		// The Class will be acquired and WILL NOT be released when exception occurred. [NOT OK].

	// If Heap Variable is used	-- By use of SmartPointers	>> it is no longer ptr, it is an OBJECT.
	std::unique_ptr<testClass> myTestClas(new testClass);	// The Class will be acquired and it will be automatically destroyed by end of scope. [OK].
															// , because of normal stack unwinding.

	// Out-of-Range Exception
	if(MAX_RECORDS_SIZE < count) {
		throw std::out_of_range("[EXCEPTION ERR]: Count is Greater than MAX_RECORDS_SIZE!");
	}

	// If Heap Variable is used
	//delete myTestClass;							// This line will not be reached.
}
/***************************************************************************************************/

void _29_ExceptionHandling_P2() {		//-------------- MAIN FUNCTION -------------- //

	// Handling Exception -- FORCED HANDLING OR THE CODE WILL CRASH.
	try {
		processClassRecords(50);
		std::cout<< "Heap Memory Successfully Allocated." << std::endl;
	}
	catch(std::out_of_range &l_exp) {				// CATCH OUT_OF_RANGE EXCEPTION ONLY
		std::cout<< l_exp.what() << std::endl;
	}
}
