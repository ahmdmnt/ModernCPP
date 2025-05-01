/*
 * _15_makeFunction.cpp
 *
 *  Created on: May 1, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>

/* Module Description:-
 * ---------------------
 *  - Make Function
 *
 */

class coordinates {
	int x;
	int y;
public:
	coordinates(int l_x, int l_y): x(l_x), y(l_y){}
};


void makeUnique();
void makeShared();

void _15_makeFunction(void) {

	/* Normal Smart Pointer Constructor */
	std::unique_ptr<int> pInt {new int {5}};

	/* Make Unique and Make Shared:
	 * Behaves like a factory function "function template Viadic", it creates an instance of a class
	 * NO CUSTOM DELETERS */
	makeUnique();
	makeShared();
}

void makeUnique() {
	/* Allocate Memory.
	 * Deallocate Memory.
	 * no control block in Unique Ptr
	 */
	auto pInt_2 = std::make_unique<int>(5);		// Will Automatically create a heap location and init it with 5.
	auto pInt_3 = std::make_unique<coordinates>(5, 7);
	auto pArray = std::make_unique<int[]>(5);		// Init is not possible here
	pArray[0] = 0; pArray[1] = 1;
}

void makeShared() {
	/* Allocate Memory and control block: manage internal of ptr.
	 * Deallocate Memory and control block: manage internal of ptr.
	 *
	 * Difference between using new and make_shared?
	 * 	- make_shared: Use one new call and one delete call for both memory block and control block. "more efficient"
	 * 	- however new() do two calls to perform both memory block and control block.
	 */
	auto pInt_2 = std::make_shared<int>(5);		// Will Automatically create a heap location and init it with 5.
	auto pInt_3 = std::make_shared<coordinates>(5, 7);
}
