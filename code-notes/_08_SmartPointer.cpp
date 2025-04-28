/*
 * _08_Friend_SmartPointer.cpp
 *
 *  Created on: Apr 27, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "intData.hpp"		// Class

/* Module Description:-
 * ---------------------
 * 	1. Importance of Deleting Resources after Allocation.
 * 	2. Resource Acquisition is Initialization.
 * 	3. Concept of Smart Pointer "simple implementation".
 * 	4. Arrow [->] Operator Overloading
 */


/* Function That Create intObject in Heap -- [TO SHOW RELEASE RESOURCE ISSUE] */
void createIntObject_1() {
	intData *pIntObj {new intData};
	pIntObj->setValue(123);
	std::cout<< "pIntObj= " << pIntObj->getValue() << std::endl;

	/* [[ISSUE]]: Here the Pointer is not deleted ...
	 * destructor for the Pointer value is not properly released, and destructor is not initiated. */
//	delete pIntObj;		// Object will be properly destroyed.
}
/*********************************************************/

/* What if you need a safe way for using pointers and data, without explicitly deleting Data ??
 *
 *	Use: Resource Acquisition is Initialization:-
 *	----------------------------------------------
 *	Life time of a resource is bound to a local object,
 *	when the local object is destroyed, in its destructor, it will AUTOMATiCALLY release the resources.
 */
/* Simple Example of */
class intPtr {
	intData *pData;
public:
	intPtr(intData *l_data): pData(l_data) {}
	~intPtr() {
		delete pData;
	}
	/* Arrow [->] Operator Overloading is used */
	intData* operator->() {
		return pData;
	}
};
void createIntObject_2() {
	intPtr pIntObj {new intData}; // @suppress("Invalid arguments")
	pIntObj->setValue(456);			// by default we cant use these methods because not part of intPtr Class,
									// So Operator overloading for arrow "->" is used.
	std::cout<< "pIntObj= " << pIntObj->getValue() << std::endl;

	/* [BECAUSE]: Pointer is part of Class,
	 * When the local class is destroyed, destructor call will properly release the resource. */
}

/*********************************************************/

void _08_SmartPointer(void) {

	/* Destructor Not Called, Not Properly Destroyed. */
	createIntObject_1();

	/* Destructor Called, Properly Destroyed and resources are released. */
	createIntObject_2();

}

