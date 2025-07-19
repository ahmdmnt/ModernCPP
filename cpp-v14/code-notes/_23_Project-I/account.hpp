/*
 * account.hpp
 *
 *  Created on: May 9, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

#ifndef PROJECT_I_ACCOUNT_HPP_
#define PROJECT_I_ACCOUNT_HPP_

class account {
private:
	static int  sAccountNumIterator;
	static constexpr int  sAccountNumBase {11000};
	/*-------------------------------------------*/
	std::string mName;
	std::string mAccType;

protected:
	int			mBaseAccNumber;
	float		mBalance;

public:
	account(const std::string& l_name, const std::string& l_type, const float& l_amount);
	virtual ~account();

	/* Getter Methods */
	int getAccountNumber() const;					// Get Account Number.
	virtual const std::string& getName() const;		// Get Account Name, "Method Overridden in Child Classes".
	const std::string& getType() const;				// Get Account Type.
	float getBalance() const;						// Get Current Account Balance.
	virtual float getInterestRate() const;			// Return Zero, "Method Overridden in Child Classes".

	/* Operation Methods */
	virtual void accumulateInterest();				// Empty in Base Account, "Method Overridden in Child Classes".
	virtual void withdrawCash(float l_amount);		// Money Withdraw Operation, "Method Overridden in Child Classes".
	void depositCash(float l_amount);				// Money Deposit Operation.
};



#endif /* PROJECT_I_ACCOUNT_HPP_ */
