/*
 * accTransaction.cpp
 *
 *  Created on: May 11, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <iomanip>
#include "account.hpp"
#include "checkingAccount.hpp"

/* Module Description:-
 * ---------------------
 * 	1. Keyword: virtual,
 * 	   for multiple different parent or child(s) classes, handling.
 * 	2. RTTI Concept,
 * 	   for Special Child handling.
 */

/* HERE USE OF PARENT CLASS DATA TYPE:
 * give us the ability to use any Parent or Child Class Objects, becasue it can access any.
 * virtual keyword:
 * -----------------
 * before function declaration, give us the ability to point correct method implementation according to passed function argument.
 *
 * a Polymorphism Concept:
 * ------------------------
 * The ability to send a message of an object that can represent different objects.
 * and then the message will automatically go to the correct Object.
 */
void accTransact(account* pAccount, const int& l_amountDeposit, const int& l_amountWithdraw) {
	std::cout << "------------------------------------" << std::endl;
	std::cout << "  Transaction processing started ..." << std::endl;
	std::cout << "  Initial Balance [" << pAccount->getAccountNumber() << "] : " << pAccount->getBalance() << " EGP." << std::endl;
	pAccount->depositCash(l_amountDeposit);
	pAccount->accumulateInterest();

	/************************************************************************************************************************
	 *  Add Functionality of ExtraVariable for Checking Accounts ONLY: */
	//THIS CONDITION GUARD IS IMPORTANT:
	// if the pAccount is not holding Checking Account, undefined behavior will occurs.

	/*First Approach - through typeid() -- WORK WITH PTR ONLY */
	if(typeid(*pAccount) == typeid(checkingAccount)) {			// typeid() GUARD
		checkingAccount *ptrChkAccount = static_cast<checkingAccount*>(pAccount);
		std::cout<< "  -----------------------"<< std::endl;
		std::cout<< "  ExtraVariable = " << ptrChkAccount->getExtraVariable() << std::endl;
	}

	/*Second Approach - through dynamic cast -- CAN WORK WITH PTR/REF */
	checkingAccount *pChkAccount = dynamic_cast<checkingAccount*>(pAccount);
	if(nullptr != pChkAccount) {
		std::cout<< "  ExtraVariable = " << pChkAccount->getExtraVariable() << std::endl;
		std::cout<< "  -----------------------" << std::endl;
	}
	/************************************************************************************************************************/

	pAccount->withdrawCash(l_amountWithdraw);
	std::cout << std::setprecision(2) << "  Interest Rate : " << pAccount->getInterestRate() << " %." << std::setprecision(0) << std::endl;
	std::cout << "  Final Balance : " << pAccount->getBalance() << " EGP." << std::endl;
	std::cout << "  Transaction processing finished ..." << std::endl << std::endl;
}


