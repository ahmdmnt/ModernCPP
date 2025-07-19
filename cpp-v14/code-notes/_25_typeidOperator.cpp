/*
 * _25_typeidOperator.cpp
 *
 *  Created on: May 12, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <typeinfo>
#include "_23_Project-I/checkingAccount.hpp"
#include "_23_Project-I/savingsAccount.hpp"

/* Module Description:-
 * ---------------------
 * 	1. Type Info Class:-
 * 	Class the contain multiple functions, which is created through keyword: typeid().
 * 		- Print Name.
 * 		- Check and Compare types.
 *
 * [IMPORTANT]::
 *	- For Non-polymorphic types:
 *		typeid() will work in compile time.
 *
 *	- For Polymorphic types:
 *		typeid() will work in run time.
 *
 */


void _25_typeidOperator() {


	//	int number;
	//	const std::type_info &ti = typeid(number);		// Create TypeInfo class.

	/* Create TypeInfo Class:
	 */
	checkingAccount chkAccount {"Aser", "Checking", 105'500};
	account* pAccount = &chkAccount;
	//const std::type_info &ti = typeid(pAccount);		// Check Pointer type
	const std::type_info &ti = typeid(*pAccount);		// Check type of what pointer is pointing at.


	/* Check Name of type:
	 */
	std::cout<< "Type Name: " << ti.name() << std::endl;

	/* Compare to specific type:
	 */
	if(ti == typeid(checkingAccount)) {
		std::cout << std::endl << "Type is checkingAccount." << std::endl << std::endl;
	}
	else {
		std::cout << std::endl << "ANY OTHER TYPE" << std::endl << std::endl;
	}

}


