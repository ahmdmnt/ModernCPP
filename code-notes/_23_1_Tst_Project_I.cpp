/*
 * _23_Project_I.cpp
 *
 *  Created on: May 9, 2025
 *      Author: AhmedMontasser
 */

/*
 * Module Descriptions:-
 * -----------------------
 * 	1. Parent/Child Classes.
 * 	2. Inheriting Constructor.
 * 	3. Overriding Parent Methods.
 * 	4.
 */

#include <vector>
#include <iostream>

#include "_23_Project-I/account.hpp"
#include "_23_Project-I/checkingAccount.hpp"
#include "_23_Project-I/savingsAccount.hpp"
#include "_23_Project-I/accTransaction.hpp"

/* This file is for Testing Project I :
 * -------------------------------------
 */

void _23_Tst_Project_I() {

	/* Test for Base Account Class */

	/* Create Account */
	account testAccount {"Ahmed", "Base", 100'000};

	/* Operation on User 11001 */
	testAccount.depositCash(20'000);
	testAccount.withdrawCash(1200);
	testAccount.withdrawCash(500);

	std::cout << "Balance of Account [" << testAccount.getAccountNumber() << "]: " << testAccount.getBalance() << " EGP." << std::endl;
	std::cout << std::endl << std::endl;
	/***************************************************************************************************************************/

	std::vector<savingsAccount> bankSavAccounts;

	/* Insert Account */
	bankSavAccounts.push_back({"Mohamed", "Savings", 1'000, 0.5f});
	/* Operation on User */
//	accTransact(bankSavAccounts.at(0), 200, 380);
	bankSavAccounts.at(0).depositCash(200);
	bankSavAccounts.at(0).accumulateInterest();				// Polymorphic Function
	bankSavAccounts.at(0).withdrawCash(380);
	std::cout << "Balance of Account [" << bankSavAccounts.at(0).getAccountNumber() << "]: ";
	std::cout << bankSavAccounts.at(0).getBalance() << " EGP." << std::endl << std::endl;

	/* Insert Account */
	bankSavAccounts.push_back({"Kareem", "Savings", 5'300, 0.5f});
	/* Operation on User */
//	accTransact(bankSavAccounts.at(1), 500, 180);			// Polymorphic Function
	bankSavAccounts.at(1).depositCash(500);
	bankSavAccounts.at(1).accumulateInterest();
	bankSavAccounts.at(1).withdrawCash(180);
	std::cout << "Balance of Account [" << bankSavAccounts.at(1).getAccountNumber() << "]: ";
	std::cout << bankSavAccounts.at(1).getBalance() << " EGP." << std::endl << std::endl;
	/***************************************************************************************************************************/

	std::vector<checkingAccount> bankChkAccounts;

	/* Insert Account */
	bankChkAccounts.push_back({"Aser", "Checking", 105'500});
	/* Operation on User */
//	accTransact(bankChkAccounts.at(0), 0, 50'000);			// Polymorphic Function
	bankChkAccounts.at(0).withdrawCash(50'000);
	std::cout << "Balance of Account [" << bankChkAccounts.at(0).getAccountNumber() << "]: ";
	std::cout << bankChkAccounts.at(0).getBalance() << " EGP." << std::endl << std::endl;

	/* Insert Account */
	bankChkAccounts.push_back({"Adam", "Checking", 50'300'000});
	/* Operation on User */
//	accTransact(bankChkAccounts.at(1), 0, 1'000'000);		// Polymorphic Function
	bankChkAccounts.at(1).withdrawCash(1'000'000);
	std::cout << "Balance of Account [" << bankChkAccounts.at(1).getAccountNumber() << "]: ";
	std::cout << bankChkAccounts.at(1).getBalance() << " EGP." << std::endl << std::endl;


}
