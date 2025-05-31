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
	intData(intData&& rrefObj)	 noexcept;
	/* Destructor */
	~intData();

	/* Assignment Operator Overloading */
	intData operator=(const intData &otherObj);			// Copy Assignment
	intData operator=(intData &&otherObj) noexcept;		// Move Assignment

	/* Operator Overloading */
	intData operator+(const intData &otherObj) const;	// Addition (self+Object)
	intData& operator++();								// Pre-Increment
	intData operator++(int);							// Post-Increment
	bool operator==(const intData &otherObj) const;		// Check Equality
	bool operator>(const intData &otherObj) const;		// Check Greater Than
	bool operator<(const intData &otherObj) const;		// Check Less Than
	void operator()();									// Function Call
	explicit operator int();							// [int] Type Conversion,, only used explicitly by user, implicit cast disabled.

	/*Normal Class Methods*/
	int fetchValue(void) const;
	int getValue(void) const;
	void setValue(int value);

	/* Friend Classes and Functions */
	friend std::istream& operator>>(std::istream &in, intData &Obj);
	friend std::ostream& operator<<(std::ostream &out, const intData &Obj);
	friend class printer;
};

#endif /* INTDATA_HPP_ */
