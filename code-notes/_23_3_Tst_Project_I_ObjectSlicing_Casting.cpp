/*
 * _23_Tst_Project_I_ObjectSlicing_Casting.cpp
 *
 *  Created on: May 12, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "_23_Project-I/account.hpp"
#include "_23_Project-I/checkingAccount.hpp"
#include "_23_Project-I/savingsAccount.hpp"
#include "_23_Project-I/accTransaction.hpp"

/* Module Description:-
 * ---------------------
 * 	1.
 *
 */

void _23_Tst_Project_I_ObjectSlicing_Casting(void) {

	/* Object Slicing:-
	 * -----------------
	 * 	- A Situation when Compiler remove some parts of an object.
	 * 	- This situation occurs, when child class object is assigned to base class.
	 * 	- This situation occurs, pass child class object, to function argument that accept base class object by value.
	 * 	- The size of Child Object maybe more than the base object.
	 * 	- While assigning child object to base object, memory parts maybe overwritten which might cause >> memory corruption.
	 *  - TO SOLVE THIS:
	 *  Compiler Slice the Child Object, by removing memory that contains its attributes. then copy it to Base Object.
	 */


	/* Up Casting:
	 * Ability of Parent Pointer or Reference to point on a Child Object and use its Members.
	 * 	>> AUTOMATIC CAST.
	 */
	checkingAccount chkAccount("Ahmed", "Checking", 1000);
	account* ptrAccount = &chkAccount;
	account& refAccount =  chkAccount;


	/* Down Casting:
	 * Ability of Child Pointer to point on a Base Object Pointer.
	 * 	>> MANUALLY SPECIFY THE CAST.
	 */
	checkingAccount* ptrChkAccount = static_cast<checkingAccount*>(ptrAccount);
}



