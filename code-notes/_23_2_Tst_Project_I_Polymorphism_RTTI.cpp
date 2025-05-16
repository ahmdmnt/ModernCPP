/*
 * _23_Test_Project_I_Polymorphism.cpp
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
 * 	1. Polymorphism "Dynamic Binding".
 * 	2. Global Polymorphic Function.
 * 	3. Destructor Polymorphic Function.
 * 	4. RTTI Handling
 *
 */



void _23_Tst_Project_I_Polymorphism_RTTI(void) {

	/* Polymorphism:-
	 * ---------------
	 * 	- Different forms of function is provided.
	 * 	- The Call is resolved in compile time or run time.
	 * 	Compile time Polymorphism:
	 * 	--------------------------
	 * 		- Function Overloading.
	 * 		- Operator Overloading.
	 * 		- Templates.
	 *
	 * 	Run time Polymorphism (Dynamic Binding):
	 * 	----------------------------------------
	 * 	The function to be invoked is decided at run time.
	 * 		- Implemented through virtual mechanism.
	 * 		The compiler inserts some code so that the correct function is invoked in runtime.
	 * 		- Called Polymorphic function.
	 * 		- ONLY INVOKED, through pointer or a reference.
	 *
	 * 		Virtual Table and Pointer (VTable & VPtr):
	 * 		------------------------------------------
	 * 		If Class is having virtual function in its implementation.
	 * 		- Compiler will generate Virtual-Table (Array) of Function Pointers to Virtual Functions.
	 * 		- Non-Virtual function doesn't appear in Virtual-Table.
	 * 		- Virtual-Pointer: Starting Address of the Virtual Table.
	 * 		- It is stored in special member variable in class "automatically added by compiler".
	 * 		- IF WE CREATED, Child Class, Virtual-Ptr will be inherited also.
	 * 		  and it will be init with address of the table of Child Class, same will occur in anyother child class.
	 */
	/* Create Account */
	savingsAccount mySavAccount {"Mohamed", "Savings", 1'000, 0.5f};
	/* Operation on User */
	accTransact(&mySavAccount, 200, 380);		// Global Polymorphic Function.


	/* Create Account */
	checkingAccount myChkAccount {"Aser", "Checking", 105'500};
	/* Operation on User */
	myChkAccount.setExtraVariable(120);
	accTransact(&myChkAccount, 0, 50'000);		// Global Polymorphic Function.
	std::cout<< "****************************************************************" << std::endl<< std::endl;

	/*
	 * 	[[IMPORTANT NOTE]]:
	 * 	- Pointer to Parent can point to either its class or Child Class.
	 *
	 * 	So I can Create Pointer to Base Class and Point to a object of Child Class.
	 * 	so in Constructor.. Parent then Child Constructor will be invoked,
	 * 	but in Destructor.. Only Pointer type will be invoked which is the Parent Only..
	 */
	/* Virtual Destructor Function Example */
	account *pChildClass = new savingsAccount ("Bob", "Savings", 100, 0.1f);

	delete pChildClass;		// WARNING: deleting object of polymorphic class type 'account' which has non-virtual destructor might cause undefined behavior
	/* TO SOLVE THIS ISSUE, Virtual Destructor function is needed, to invoked all needed destructors.
	 *
	 * IMPORTANT NOTE:
	 * Base class should have virtual class destructor
	 */
}


