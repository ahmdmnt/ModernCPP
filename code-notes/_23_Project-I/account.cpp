/*
 * account.cpp
 *
 *  Created on: May 9, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <iomanip>
#include "account.hpp"

/* Initiate the Static Member Variable */
int account::sAccountNumIterator {0};

account::account(const std::string& l_name, const std::string& l_type, const float& l_amount):
		mName(l_name), mAccType(l_type), mBalance(l_amount) {

	std::cout<< "account()" << std::endl;

	mBaseAccNumber = ++sAccountNumIterator+sAccountNumBase;

	std::cout << "New Account is created successfully!" << std::endl;
	std::cout << "Name    : " << mName << std::endl;
	std::cout << "Type    : " << mAccType << std::endl;
	std::cout << std::fixed << std::setprecision(0) << "Balance : " << mBalance << " EGP" << std::endl;
	if(l_type == "Base") {
		std::cout << "BaseID #" << mBaseAccNumber << std::endl;
	}
}
account::~account() {
	std::cout<< "~account()" << std::endl;
}

/* Getter Methods */
int account::getAccountNumber() const {
	return mBaseAccNumber;
}
const std::string& account::getName() const {
	return mName;
}
const std::string& account::getType() const {
	return mAccType;
}
float account::getBalance() const {
	return mBalance;
}
float account::getInterestRate() const {
	return 0.0f;
}

/* Operation Methods */
void account::accumulateInterest() {
	/* EMPTY: Implementation according to different account types. */
}
void account::withdrawCash(float l_amount) {
	if(l_amount == 0) {
		return;		// Do Nothing
	}

	if(l_amount < 0) {
		std::cout<< "ERROR: Invalid Amount!" << std::endl;
		return;
	}

	if(l_amount < mBalance) {
		mBalance -= l_amount;
	}
	else {
		std::cout << "ERROR: Insufficient balance!" << std::endl;
	}
}
void account::depositCash(float l_amount) {
	if(l_amount == 0) {
		return;		// Do Nothing
	}
	if(l_amount < 0) {
		std::cout<< "ERROR: Invalid Amount!" << std::endl;
		return;
	}
	mBalance += l_amount;
}
