/*
 * _08_Friend_SmartPointer.cpp
 *
 *  Created on: Apr 27, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>			// STD Pointers
#include "intData.hpp"		// Class


/* Module Description:-
 * ---------------------
 * 	1. Importance of Deleting Resources after Allocation.
 * 	2. Resource Acquisition is Initialization.
 * 	3. Concept of Smart Pointer "simple implementation".
 * 	4. Arrow [->] Operator Overloading
 *
 * Main Methods:
 * --------------
 *  - .reset() 	   -> delete old resource and re assign
 *  - if(PtrName)  -> check if null
 *  - .use_count() -> return count of copies for shared ptr
 */


/* Function That Create intObject in Heap -- [TO SHOW RELEASE RESOURCE ISSUE] */
void createIntObject_1() {
	intData *pIntObj {new intData};
	pIntObj->setValue(123);
	std::cout<< "pIntObj= " << pIntObj->fetchValue() << std::endl;

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
	/* Dereference [*] Operator Overloading is used */
	intData& operator*() {
		return *pData;
	}
};
void createIntObject_2() {
	intPtr pIntObj {new intData}; // @suppress("Invalid arguments")

	/*	by default we can not use these methods because not part of intPtr Class,
	 * 	- So Operator overloading for arrow "->" is used.
	 * 	- Or Operator overloading for dereference "*" is used.
	 */
	pIntObj->setValue(456);											// Arrow
	std::cout<< "pIntObj= " << (*pIntObj).fetchValue() << std::endl;	// Dereferenece

	/* [BECAUSE]: Pointer is part of Class,
	 * When the local class is destroyed, destructor call will properly release the resource. */
}
/*********************************************************/

void uniquePtr_process(std::unique_ptr<intData> l_ptr) {
	l_ptr->setValue(6600);
	std::cout<< std::endl << "l_ptr=" << l_ptr->fetchValue() << std::endl << std::endl;
}
void sharedPtr_process(std::shared_ptr<intData> l_ptr) {
	l_ptr->setValue(3310);
	std::cout<< "Count of shared_ptr:" << l_ptr.use_count() << " [sharedPtr_process() Context]" << std::endl;
	std::cout<< std::endl << "l_ptr=" << l_ptr->fetchValue() << std::endl << std::endl;
}

void _08_SmartPointer() {

	/* Using normal Pointer */
	/* Destructor Not Called, Not Properly Destroyed. */
	//	createIntObject_1();

	/* Using Object */
	/* Destructor Called, Properly Destroyed and resources are released. */
	//	createIntObject_2();

	/* Types of STD Smart Pointers:-
	 * 	1. Unique Pointers.
	 * 	2. Shared Pointers.
	 */

	/* Unique Pointer:-
	 * -----------------
	 * 	Class template that requires the type of memory you want to manage.
	 * 	 - Copy Semantics is not available, Copy Constructor is deleted.
	 * 		> Underlying resource can not be shared, can not be reassigned to another pointer.
	 * 	 - Move Semantics is available.
	 */
	std::unique_ptr<intData> uniPtrData {new intData};
	//auto pDataCopy (uniPtrData);				// ERROR:[use of deleted function]
	uniquePtr_process(std::move(uniPtrData));	// Note: pData CANNOT BE USED because it is moved. "Re-init is needed".

	/* Shared Pointer:-
	 * -----------------
	 * 	Class template that requires the type of memory you want to manage.
	 * 	 - Move Semantics is available.
	 * 	 - Copy Semantics is available.
	 * 		> Used when you want to share resource to different part in code.
	 * 	 - I has internal reference count,
	 * 	 	- incremented each time reference shared pointer is created.
	 * 	 	- decremented each time reference shared pointer is destroyed.
	 * 	 	- if equals to "0", it releases the underlying resources.
	 */
	std::shared_ptr<intData> shaPtrData {new intData};
	std::cout<< "Count of shared_ptr:" << shaPtrData.use_count() << " [main() Context]" << std::endl;
	auto pDataCopy (shaPtrData);				// ERROR:[use of deleted function]
	std::cout<< "Count of shared_ptr:" << shaPtrData.use_count() << " [main() Context]" << std::endl;
	sharedPtr_process(shaPtrData);	// Note: pData CANNOT BE USED because it is moved. "Re-init is needed".


	/* Smart Pointer:-
	 * ----------------
	 *	it behaves like a pointer but, it automatically frees the memory without need of freeing it by yourself.
	 *	- C++ std library provide smart pointers can be used with any type of pointers.
	 */

}

