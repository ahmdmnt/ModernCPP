/*
 * _23_4_Tst_Project_I_DynamicCast.cpp
 *
 *  Created on: May 13, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "_23_Project-I/account.hpp"
#include "_23_Project-I/checkingAccount.hpp"
#include "_23_Project-I/savingsAccount.hpp"
#include "_23_Project-I/accTransaction.hpp"

/* Dynamic Casting:-
 * ---------------------
 * 	Dynamic cast is a way to cast a type in intelligent way,
 * 	commonly used in polymorphism, if i am passing different classes.
 * 	 - WORK WITH POINTERS.
 * 	 - WORK WITH REFERENCES.
 */


void _23_Tst_Project_I_DynamicCast() {

	checkingAccount myChkAccount {"Ahmed", "Checking", 1000};
	savingsAccount mySavAccount {"Ahmed", "Checking", 1000, 0.5f};

	/* Pointer Example */
		account* pAccount = &myChkAccount;
//	account* pAccount = &mySavAccount;

	checkingAccount* pChkAcc = dynamic_cast<checkingAccount*>(pAccount);		// Here Pointer will be assigned to null, if failed
	if(nullptr != pChkAcc) {
		std::cout << std::endl << "Casting is successful- and pAccount is pointing to checkingAccount." << std::endl << std::endl;
	}
	else {
		std::cout << std::endl << "Casting Not Successful." << std::endl << std::endl;
	}

	/* Reference Example */
	account& rAccount = myChkAccount;
//	account& rAccount = mySavAccount;

	try { checkingAccount& refChkAcc = dynamic_cast<checkingAccount&>(rAccount);		// Here EXCEPTION will be thrown, if failed
		std::cout << std::endl << "Dynamic Casting is OK" << std::endl << std::endl;
	}
	catch(std::exception &ex) {
		std::cout << std::endl << "[EXCEPTION]: " << ex.what() << std::endl << std::endl;
	}


	/**
	 * BEST PRACTICE::--
	 *
	 * Ideally, we should avoid using type id in dynamic cast, because for these operators to work, the
	 * compiler had to add some extra information to the polymorphic classes.
	 *
	 * So during compile time, the compiler creates the type information of the object as a type_info object,
	 * 	- that is stored along with the class v-table at runtime.
	 *	   >> When we use type id or dynamic cast, these operators will query that information.
	 *
	 * That is why it should be avoided, especially dynamic cast, because dynamic cast will have to run through
	 * the hierarchy to check if the cast can be performed or not.
	 * 	   >> So it is slower than type id, the bottom line as far as possible.
	 *
	 * Avoid RTTI instead rely on polymorphism so that the correct behavior is invoked polymorphic without having
	 * to know the type of the object.
	 */
}

