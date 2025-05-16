/*
 * _30_ExceptionHandling_P3.cpp
 *
 *  Created on: May 15, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>
#include <vector>

/* Module Description:-
 * ---------------------
 * 	1. Exception Handling in Constructor and Destructor:
 * 	-----------------------------------------------------
 *	Constructor:
 *		- Use try-catch blocks inside constructors if you expect exceptions.
 *		- Avoid resource leaks by using RAII (Resource Acquisition Is Initialization).
 *				RAII, resources are tied to the lifetime of objects. When an object is created,
 *				it acquires a resource (like opening a file or allocating memory).
 *				When the object goes out of scope,
 *				its destructor automatically releases the resource.
 *		- Prefer smart pointers (std::unique_ptr, std::shared_ptr) for dynamic memory.
 *	Destructor:
 *		- Destructor should never throw exceptions.
 *		- If an exception is thrown during stack unwinding (i.e., another exception is already active), it leads to std::terminate() and program crash.
 *		- Use try-catch blocks inside destructor if it is no way needed.
 *
 *
 *  2. Keyword: noexcept:
 * 	-----------------------
 *	 - Applied to both function (declaration and definition).
 *	 - Indicates that the function doesn't throw any exceptions.
 *	 - Compiler can optimize the function code. "to skip stack unwinding generation, if 100% no except".
 *	 - An exception from such function can lead to program termination.
 *	   because stack unwinding feature is disabled.
 *	 - Optionally it can accept boolean values (true= noexcept) - (false=except).
 *
 *	   [SYNTAX]:
 *	   returnType FUNCTION_NAME(args.) noexcept {}
 *	   returnType FUNCTION_NAME(args.) noexcept(true) {}
 */

class tstA {
public:
	tstA() { std::cout << "tstA() ... Acquired!" << std::endl; }
	~tstA() { std::cout << "~tstA() ... Released!" << std::endl; }
};
class tstB {
public:
	tstB() { std::cout << "tstB() ... Acquired!" << std::endl; }
	~tstB() { std::cout << "~tstB() ... Released!" << std::endl; }
};

class tstClass {
	tstA  vA{};			// Will be destroyed, a CLASS.
	//tstB* pB{};			// Will not be destroyed.
	//int*  pInt{};		// Will not be destroyed.
	//int*  pArr{};		// Will not be destroyed.
	//char* pStr{};		// Will not be destroyed.

	// SOLUTION
	std::unique_ptr<tstB> pB{};
	std::unique_ptr<int>  pInt{};
	std::vector<int>      pArr{};
	std::string           vStr{};

public:
	tstClass() { std::cout << "tstClass() ... Resource Acquired!" << std::endl;
		//pA = new tstA {};				// Any of
		//pInt = new int;				// these dynamic memory allocation
		//pArr = new int[1000];			// variables assigned by new can through any Exception,
		//pStr = new char[900];			// so that,, the destructor of this Object will not be called
		pB.reset(new tstB);

		// throw dummy exception to test
		throw std::runtime_error("[ERROR] Failed to initialize!");
	}
	~tstClass() { std::cout << "~tstClass() ... Resource Released!" << std::endl;
		//delete pA;
		//delete pInt;
		//delete pArr;
		//delete pStr;

	// AVOID USING EXCEPTION in Destructor
	// Because of the destructor is called because of stack unwinding , then the exception in the destructor might be called and terminate the program.
	// What if i need to throw exception in destructor?? >> better to handle it in destructor it self.
	}
};


/* noexcept keyword examples */
void testfunction() {
	throw 1;
	return;
}
int intSum(int n1, int n2) noexcept(true) {
	throw 3;	// What if exception is throwed here,,, Program Crash will happens.
	testfunction();  // What if exception is throwed from within a called function,,, Program might Crash also.
	// becasue in above scenarios ,,, no stack unwinding for intSum( function .

	return n1+n2;
}
int intSum2(int n1, int n2) noexcept(false) {
	throw 3;		 // What if exception is throwed here,,, NO CRASH
	testfunction();  // What if exception is throwed from within a called function,,, NO CRASH

	return n1+n2;
}
int intSum3(int n1, int n2) noexcept(noexcept(testfunction)) {	// except of this function will be set according to test function

	std::cout << "noexcept(testfunction)= " << noexcept(testfunction) << std::endl;

	testfunction();


	return n1+n2;
}

void _30_ExceptionHandling_P3(void) {
	try {
		tstClass myClass {};	// if exception is thrown here
		// constructor of this class is not fully implemented ,, so ITS destructor will not be invoked.
	}
	catch(std::runtime_error& l_exp) {
		std::cout << l_exp.what() << std::endl;
	}


//	intSum(10,20);
	intSum2(10,20);
}


/* The guideline is, the functions that are sure not to throw exceptions:-
 * ------------------------------------------------------------------------
 * should be marked with noexcept keyword and all other functions should be exception neutral because they may or may not throw.
 * 	>> If a function invokes any library function then it is dangerous to mark that with noexcept true specifier.
 *  >> User defined Move operations in a class then they should be marked with the noexcept specifier,
 *  This is important because if you store the objects of such class inside the containers such as vector
 *  or list, in certain operations these containers may have to create copies of your object but if your
 *  class supports move operations then they will prefer to use the move operations.
 *   --- However, they will use the move operations only if they have the noexcept true specifier.
 *  So, remember for user defined classes that have move operations,
 *  that is move constructor and move assignment, use the noexcept true specifier on them.
 *  This will improve the performance of your code when using your objects with standard containers.
 *
 */
