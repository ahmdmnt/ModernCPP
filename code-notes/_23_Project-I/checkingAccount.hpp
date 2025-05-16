/*
 * checkingAccount.hpp
 *
 *  Created on: May 11, 2025
 *      Author: AhmedMontasser
 */


/* Module Description:-
 * ---------------------
 * 	1. Sample of Inheriting Constructor.
 *	2. Parent Method Overriding.
 */

#include <iostream>

#include "../_23_Project-I/account.hpp"


#ifndef PROJECT_I_CHECKINGACCOUNT_HPP_
#define PROJECT_I_CHECKINGACCOUNT_HPP_

class checkingAccount : public account {
private:
	static int sCheckingAccNumIterator;
	static constexpr int sCheckingAccNumBase {31000};
	static constexpr float sMinimumBalance {500};
	/*----------------------------------------------*/
	int	mCheckingAccNumber;
	int	mExtraVariable;


public:
	/* Inheriting Constructor */
	// using account::account;		// if i don't need a specific constructor for myself. i can call the parent constructor.
	checkingAccount(const std::string& l_name, const std::string& l_type, const float& l_amount);
	~checkingAccount();

	/* Specific Operations Methods for Savings Account */
	int getAccountNumber() const;			// Specific handling in Savings Account.
	void withdrawCash(float l_amount);		// Specific handling in Savings Account.
	float getMinimumBalance() const;
	void setExtraVariable(int l_value);
	int getExtraVariable() const;

};


#endif /* PROJECT_I_CHECKINGACCOUNT_HPP_ */
