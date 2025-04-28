/*
 * intData.hpp
 *
 *  Created on: Apr 28, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Module Description:-
 * ---------------------
 * 	This is the Main Class used for OOP topics.
 * 		starting from Move Semantics
 */

#ifndef INTDATA_HPP_
#define INTDATA_HPP_

class intData {
	int* pInt;
public:
	/* Default Constructor */
	intData();
	/* Parameterized Constructor */
	intData(int value);
	/* Copy Constructor */
	intData(const intData& refObj);
	/* Move Constructor */
	intData(intData&& rrefObj);
	/* Destructor */
	~intData();

	/* Assignment Operator Overloading */
	intData operator=(const intData &otherObj);			// Copy Assignment
	intData operator=(intData &&otherObj);				// Move Assignment

	/* Operator Overloading */
	intData operator+(const intData &otherObj) const;	// Addition (self+Object)
	intData& operator++();								// Pre-Increment
	intData operator++(int);							// Post-Increment
	bool operator==(const intData &otherObj) const;		// Check Equality
	void operator()();									// Function Call

	/*Normal Class Methods*/
	int getValue(void) const;
	void setValue(int value);

	/* Friend Classes and Functions */
	friend std::istream& operator>>(std::istream &in, intData &Obj);
	friend class printer;
};

#endif /* INTDATA_HPP_ */
