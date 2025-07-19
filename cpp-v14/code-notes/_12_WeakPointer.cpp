/*
 * _12_WeakPointer.cpp
 *
 *  Created on: Apr 30, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>

/* Module Description:-
 * ---------------------
 * Weak Pointer
 *
 *  - Always initialized with shared_ptr
 *  - it will internally point to shared_ptr control block, has information about reference count of shared_ptr.
 *  - if reference count is set to [0] the shared pointer will not be destroyed.
 *  - same shared_ptr can have multiple weak pointer.
 *  - WeakPointer advantage:
 *     it checks if shared_ptr exists or not by: .expired() method.
 *
 * 	The .lock() function in std::weak_ptr:-
 * 	-------------------------------------------
 * 	 is used to safely obtain a std::shared_ptr from a weak pointer.
 * 	Since std::weak_ptr does not affect the reference count of the resource it points to,
 * 	calling .lock() allows you to temporarily promote the weak pointer
 * 	to a std::shared_ptr only if the resource is still valid.
 *
 */

class printer {
	std::weak_ptr<int> m_pValue {};

public:
	void setValue(std::weak_ptr<int> l_pValue) {
		m_pValue = l_pValue;
	}
	void printValue() {
		if(m_pValue.expired()) {	// no shared_ptr valid, so it is null
			std::cout<< "Resource is no longer valid!!" << std::endl;
			return;
		}
		auto shPtrLock = m_pValue.lock();	// i can not use the weak pointer directly .. instead i am creating a temp sharedPtr by .lock()
		// to access the shared_ptr used with weak_ptr then it will be released.
		std::cout << "m_pValue= " << *shPtrLock << std::endl;
		std::cout << "RefCount: " << shPtrLock.use_count() << std::endl;

	}
};

void _12_WeakPointer() {
	int myValue {2};
	printer myPrinter;
	std::shared_ptr<int> pValue {new int {myValue}};
	myPrinter.setValue(pValue);

	if( *pValue>10 ) {
		pValue = nullptr;
	}
	myPrinter.printValue();
	std::cout << "RefCount: " << pValue.use_count() << std::endl;
}



