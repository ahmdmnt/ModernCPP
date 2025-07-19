/*
 * checkingAccount.cpp
 *
 *  Created on: May 11, 2025
 *      Author: AhmedMontasser
 */

#include "checkingAccount.hpp"

#include <iostream>


/* Initiate the Static Member Variable */
int checkingAccount::sCheckingAccNumIterator {0};

checkingAccount::checkingAccount(const std::string& l_name, const std::string& l_type, const float& l_amount) :
		account(l_name, l_type, l_amount) {

	std::cout<< "checkingAccount()" << std::endl;

	mCheckingAccNumber = (mBaseAccNumber*100'000) + (++sCheckingAccNumIterator+sCheckingAccNumBase);
	std::cout << "AccountID #" << mCheckingAccNumber << std::endl;
}

checkingAccount::~checkingAccount() {
	std::cout<< "~checkingAccount()" << std::endl;
}

/* Specific Operations Methods for Savings Account */
int checkingAccount::getAccountNumber() const {		// Get Account Number "Override".
	return mCheckingAccNumber;
}

void checkingAccount::withdrawCash(float l_amount) {	// Money Withdraw Operation "Override".
	if(l_amount <= 0) {
		std::cout<< "ERROR: Invalid Amount!" << std::endl;
		return;
	}
	if( (mBalance-l_amount) > sMinimumBalance ) {
		account::withdrawCash(l_amount); 	// redirect to base function
	}
	else {
		std::cout << "ERROR: Insufficient balance!" << std::endl;
	}
}

float checkingAccount::getMinimumBalance() const {
	return sMinimumBalance;
}

void checkingAccount::setExtraVariable(int l_value) {
	mExtraVariable = l_value;
}

int checkingAccount::getExtraVariable() const {
	return mExtraVariable;
}
