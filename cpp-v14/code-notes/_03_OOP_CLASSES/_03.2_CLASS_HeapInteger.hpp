/*
 * _03.2_CLASS_HeapInteger.hpp
 *
 *  Created on: Apr 15, 2025
 *      Author: AhmedMontasser
 */

#ifndef _CLASS_HeapInteger_
#define _CLASS_HeapInteger_

class HeapInteger {
private:
	int *pInt;
public:
	HeapInteger();										// Default Constructor
	HeapInteger(int value);								// Parameterized Constructor
	HeapInteger(const HeapInteger &refObj);				// Copy Constructor
	~HeapInteger();										// Destructor

	HeapInteger& operator=(const HeapInteger& refObj);	//Copy assignment operator

	int getValue() const;		// Constant Member Function
	void setValue(int value);	// Member Function
};




#endif /* _CLASS_HeapInteger_ */
