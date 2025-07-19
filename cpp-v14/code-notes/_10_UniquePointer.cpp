/*
 * _10_UniquePointer.cpp
 *
 *  Created on: Apr 30, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>
#include "intData.hpp"

/* Module Description:-
 * ---------------------
 * Unique Pointer:-
 * Main Advantage, the Resource hold under this pointer is unique for this pointer only.
 * can not be re assigned to another point, copy semantics is not possible but move semantics is.
 * and to reallocate that point u need to use .reset() method.
 * 	1. Unique Pointer Use case:
 * 		Conclusion here, Unique or Smart Pointer Generally simplifiy use of pointers.
 * 		you don't have to handle memory managment explicit. smart pointer class is doing it by default.
 * 		so no need to make sure that you delete every pointer you use, just be aware with smart pointer features.
 */

intData* getPointer(int l_value) {
	intData *l_pData = new intData {l_value};
	return l_pData;
}
void storePointer(std::unique_ptr<intData> &l_pData) {
	std::cout << "Storing Pointer value ... " << l_pData->fetchValue() << std::endl;
}
void displayPointer(intData *l_pData) {
	if( nullptr == l_pData ) {
		return;
	}
	l_pData->getValue();
	return;
}
void operatePointer(int l_value) {
	std::unique_ptr<intData> l_pData {getPointer(l_value)};
	if( nullptr == l_pData ) {
		/* Because this is a unique ptr, we can't reassign value in it, instead use reset()
		 * 	1- Delete previous resource (if it is available).
		 * 	2- take ownership of new pointer */
		l_pData.reset(new intData {l_value});
	}

	l_pData->setValue(100100);
	displayPointer(l_pData.get());	// either use direct access to underlying pointer

	//delete l_pData;				// not needed in smart pointer
	//l_pData = nullptr;			// it deletes the underlying pointer and assigning null to it.

	//l_pData = new intData {};		// not needed in smart pointer instead use reset()
	l_pData.reset(new intData {l_value});	// because we used reset() so old resource will be released automatically. no need then for line 43 also.

	*l_pData = __LINE__;
	displayPointer(l_pData.get());	// either use direct access to underlying pointer
	//delete l_pData;				// not needed

	storePointer(l_pData);			// Either Pass by Reference, OR, move variable is no longer needed in that scope.
}

void _10_UniquePointer() {

	operatePointer(660);
}
