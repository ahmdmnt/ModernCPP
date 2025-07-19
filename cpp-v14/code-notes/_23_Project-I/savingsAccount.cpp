/*
 * savingsAccount.cpp
 *
 *  Created on: May 9, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <iomanip>
#include "savingsAccount.hpp"

/* Initiate the Static Member Variable */
int savingsAccount::sSavingsAccNumIterator {0};

savingsAccount::savingsAccount(const std::string& l_name, const std::string& l_type, const float& l_amount, const float& l_rate):
account(l_name, l_type, l_amount),  mInRate(l_rate) {

	std::cout<< "savingsAccount()" << std::endl;

	std::cout << std::setprecision(2) << "Interest Rate : " << mInRate << " %" << std::setprecision(0) << std::endl;
	mSavingsAccNumber = (mBaseAccNumber*100'000) + (++sSavingsAccNumIterator+sSavingsAccNumBase);
	std::cout << "AccountID #" << mSavingsAccNumber << std::endl;
}
savingsAccount::~savingsAccount() {
	std::cout<< "~savingsAccount()" << std::endl;
}

int savingsAccount::getAccountNumber() const {		// Get Account Number "Override".
	return mSavingsAccNumber;
}
float savingsAccount::getInterestRate() const {
	return mInRate;
}
void savingsAccount::accumulateInterest() {
	mBalance += (mBalance*mInRate);
}
