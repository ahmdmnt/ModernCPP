/*
 * _14_DynamicArrays_DeleterFu.cpp
 *
 *  Created on: May 1, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>
#include <cstdlib>

/* Module Description:-
 * ---------------------
 * 	Deleter Function:
 * 		1- Using Class Object.
 *		2- Using Function Object
 */

/* 1- Using Class Object */
struct cFree {
	void operator()(int *l_pInt) {
		free(l_pInt);
		std::cout<< "cFree() is invoked ... " << std::endl;
	}
};

/* 2- Using Function Object */
void MallocFree(int* l_ptr) {
	free(l_ptr);
	std::cout<< "MallocFree() is invoked ... " << std::endl;
}

void UniquePtr_Deleters();
void SharedPtr_Deleters();

void _14_DynamicArrays_DeleterFu(void) {
	/* Smart Pointers with Legacy Code:
	 * ---------------------------------
	 *	- By Default Smart Pointer call delete in destructor not free()
	 *	which might cause issues in that situation.
	 *
	 *	they support deleter function.. which can delete both C++/Legacy Dynamic Memory Allocation,
	 *	but by default it uses delete instead of free().
	 *	so we can specify our on deleter to make sure of behavior
	 */
	UniquePtr_Deleters();
	SharedPtr_Deleters();


	/* Dynamic Arrays:
	 * ----------------
	 * Normal syntax of Smart Pointer can work, but with limitations.
	 * 	- accessing with .get()
	 * 	- undefined behavior with deleter.
	 */
	std::unique_ptr<int> pArray_1 {new int[5] {1,2,3,4,5}};
	//pArray[0]=100;		//Error
	pArray_1.get()[0] = 100;
	// Customized Deleter is needed.

	/* A Good Solution in C++17:
	 * Partial specialization of Smart Pointers.
	 */
	std::unique_ptr<int[]> pArray_2 {new int[5] {1,2,3,4,5}};
	pArray_2[0]=100;
	// No need for customized Deleter.

	/* Ideal case for using Dynamically Array of Data.
	 * -----------------------------------------------
	 * Better to use CONTAINERS: std::vector
	 */
}

void UniquePtr_Deleters() {

	/* [Class Object]: SMART_PTR<TYPE, CLASSNAME> pInt {DYNAMIC_MEM_ALLOCATION, OBJECT{}};
	 *	_OR_
	 * [Function Object]: SMART_PTR<TYPE, Ptr_FunctionPrototype> pInt {DYNAMIC_MEM_ALLOCATION, FunctionName};
	 */
	std::unique_ptr<int, cFree> pInt_1 {(int*)malloc(sizeof(int)), cFree{}};
	*pInt_1 = 120;
	std::cout<< *pInt_1 << std::endl;

	std::unique_ptr<int, void(*)(int*)> pInt_2 {(int*)malloc(sizeof(int)), MallocFree};
	*pInt_2 = 240;
	std::cout<< *pInt_2 << std::endl;
}

void SharedPtr_Deleters() {

	/* [Class Object]: SMART_PTR<TYPE> pInt {DYNAMIC_MEM_ALLOCATION, OBJECT{}};
	 *	_OR_
	 * [Function Object]: SMART_PTR<TYPE> pInt {DYNAMIC_MEM_ALLOCATION, FunctionName};
	 */
	std::unique_ptr<int, cFree> pInt_1 {(int*)malloc(sizeof(int)), cFree{}};
	*pInt_1 = 360;
	std::cout<< *pInt_1 << std::endl;

	std::unique_ptr<int, void(*)(int*)> pInt_2 {(int*)malloc(sizeof(int)), MallocFree};
	*pInt_2 = 480;
	std::cout<< *pInt_2 << std::endl;
}
