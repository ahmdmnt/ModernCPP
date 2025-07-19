/*
 * savingsAccount.hpp
 *
 *  Created on: May 9, 2025
 *      Author: AhmedMontasser
 */


/* Module Description:-
 * ---------------------
 *	1. Parent Method Overriding.
 */

#include <iostream>
#include "account.hpp"

#ifndef PROJECT_I_SAVINGSACCOUNT_HPP_
#define PROJECT_I_SAVINGSACCOUNT_HPP_

class savingsAccount : public account {
	static int sSavingsAccNumIterator;
	static constexpr int sSavingsAccNumBase {21000};
	/*----------------------------------------------*/
	float mInRate;
	int	mSavingsAccNumber;

public:
	savingsAccount(const std::string& l_name, const std::string& l_type, const float& l_amount, const float& l_rate);
	~savingsAccount();

	/* Specific Operations Methods for Savings Account */
	int getAccountNumber() const;		// Specific handling in Savings Account.
	float getInterestRate() const;		// Specific handling in Savings Account.
	void accumulateInterest();			// Specific handling in Savings Account.

};

#endif /* PROJECT_I_SAVINGSACCOUNT_HPP_ */
