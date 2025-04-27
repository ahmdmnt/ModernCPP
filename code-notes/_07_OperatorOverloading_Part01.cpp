/*
 * _07_OperatorOverloading_Part01.cpp
 *
 *  Created on: Apr 24, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>

/* Module Description:-
 * ---------------------
 * 	1. Copy and Move Assignment Operator Overloading.
 * 	2. Addition Operator Overloading.
 * 	3. Subtraction Operator Overloading.
 * 	4. Increment Operator Overloading.
 * 	5. Check Equality Operator Overloading.
 * 	6. Addition Global Operator Overloading "intValue+object".
 * 	7. Input and Output Stream Operator Overloading.
 */

class intObj {
	int *pInt;
public:
	/* Constructors and Destructor */
	intObj() : pInt{new int {0}} {};						// Default Constructor
	intObj(int l_value) : pInt{new int {l_value}} {};		// Parameterized Constructor
	~intObj() {												// Destructor
		delete pInt;
	}
	intObj(const intObj &refInt) {							// Copy Constructor
		this->pInt = new int {*refInt.pInt};
	}
	intObj(intObj &&rRefInt) {								// Move Constructor
		this->pInt = rRefInt.pInt;
		rRefInt.pInt = nullptr;
	}
	/*********************************************************/
	/* Copy and Move Assignment Operators */
	/* (=) Copy/Equality Operator Overloading */
	intObj operator=(const intObj &otherObj) {
		if(this != &otherObj) {
			delete this->pInt;
			this->pInt = new int {*otherObj.pInt};
		}
		return *this;
	}
	/* (=) Move/Equality Operator Overloading */
	intObj operator=(intObj &&otherObj) {
		if(this != &otherObj) {
			delete this->pInt;
			this->pInt = otherObj.pInt;
			otherObj.pInt = nullptr;
		}
		return *this;
	}
	/*********************************************************/
	/* Normal Methods */
	int getValue() const {
		return *pInt;
	}
	void setValue(int l_value) {
		if(nullptr != pInt) {
			*pInt = l_value;
		}
	}
	/*********************************************************/
	/* Operator Overloading Methods */
	/* Because this is Operator Overloading from Object, no need to add second Operand it is accessed through calling object. */
	/* (+) Addition Operator Overloading */
	intObj operator+(const intObj &otherObj) const {	// this is a const method, NOT MODFIYING in Calling Object, using it only.
		std::cout << "operator+ invoked!" << std::endl;
		intObj result;
		*result.pInt = *this->pInt + *otherObj.pInt;
		return result;
	}
	/* (++) Pre-Increment Operator Overloading */
	intObj& operator++() {								// PREFIX Increment Operator - More Efficient
		*this->pInt = *this->pInt+1;
		return *this;
	}
	/* (++) Post-Increment Operator Overloading */
	intObj operator++(int) {							// POSTFIX Increment Operator - Less Efficient
		intObj temp {*this};// @suppress("Invalid arguments")
		*this->pInt = *this->pInt+1;	// I will increment the Object.
		return temp;					// return incremented temp.
	}
	/* (==) Check Equality Operator Overloading */
	bool operator==(const intObj &otherObj) const {		// Check Equality
		return (*this->pInt == *otherObj.pInt);
	}
	/* (()) SIMPLE Function Call Operator Overloading */
	void operator()() {
		std::cout << "SIMPLE IMPLEMENTATION OF Function Call Operator Overloading: " << std::endl;
		std::cout << *this->pInt << std::endl << std::endl;
	}
};

/* Operator Overloading Global Function:-
 * --------------------------------------- */
/* Because this is Operator Overloading Globally, I NEED to add ALL Operands */
/* (-) Subtraction Operator Overloading */
intObj operator-(const intObj &Obj1, const intObj &Obj2) {
	std::cout << "operator- invoked!" << std::endl;
	intObj result;
	result.setValue(Obj1.getValue() - Obj2.getValue());
	return result;
}

/* (int+Object) Addition Global Operator Overloading */
//intObj operator+(int&& num, const intObj &Obj) {			// will accept onlt R-Value
intObj operator+(const int& num, const intObj &Obj) {		// will accept both L-Value and R-Value
	intObj result;
	result.setValue(num + Obj.getValue());
	return result;
}
/* (<<) Output stream Operator Overloading */
std::ostream& operator<<(std::ostream &out, const intObj &Obj) {
	out << "Object= " << Obj.getValue();
	return out;		// return is reference because we are not returning local variable.
}
/* (>>) Input stream Operator Overloading */
std::istream& operator>>(std::istream &in, intObj &Obj) {
	int l_value {};
	in >> l_value;
	Obj.setValue(l_value);
	return in;
}
/*********************************************************/


void _07_OperatorOverloading_Part01(void) {

	/* Operator Overloading:-
	 * -----------------------
	 * Way of Providing Custom Implementation for primitive operators.
	 * 	- Allow to use user-defined objects, in mathematical expressions.
	 * 	- Require usage of Operator Keyword.
	 * 	- Operator are overloaded as functions, but they are written as simple expression.
	 * 	- Implemented as Object Method, or, Global function.
	 *
	 * 	[SYNTAX]:
	 * 		returnType operator<operatorSign>(functionArguments)
	 *
	 */
	intObj num1 {10}, num2 {30};
	std::cout<< "num1 = " << num1.getValue() << std::endl;
	std::cout<< "num2 = " << num2.getValue() << std::endl << std::endl;

	/* Addition */
	intObj myResult = num1+num2;
	std::cout<< "myResult = " << myResult.getValue() << std::endl << std::endl;

	/* Subtraction */
	myResult = num2-num1;
	std::cout<< "myResult = " << myResult.getValue() << std::endl << std::endl;

	/* Pre-Incremenet */
	++num1;
	std::cout<< "num1 = " << num1.getValue() << std::endl << std::endl;

	/* Post-Increment */
	intObj num3 = num1++;	// num3 will have original value of num1 -- and num1 then will be ++
	std::cout<< "num3 = " << num3.getValue() << " -- num1 = " << num1.getValue() << std::endl << std::endl;

	/* Check Equality */
	bool isEqual {num1 == num2};
	std::cout<< std::boolalpha << "isEqual = " << isEqual << std::endl << std::endl;

	/* Copy Assignment Operator */
	num3 = num2;
	std::cout<< "num3 = " << num3.getValue() << std::endl << std::endl;

	/* Addition Operator Overloading Syntax */
	myResult = num3+5;		// myResult = num3.operator+(5);	Implicit Cast occurred to integer value.
	std::cout<< "myResult = " << myResult.getValue() << std::endl << std::endl;
	myResult = 15+num3;		// myResult = num3.operator+(5); [WRONG]  --- myResult = operator+(15, num3); [CORRECT]
	std::cout<< "myResult = " << myResult.getValue() << std::endl << std::endl;

	/* Input and Output Stream Operator Overloading */
//	std::cout<< "Please Enter value for Object: ";	std::cin >> num1;
	std::cout<< num1 << std::endl << std::endl;

	/* Function Call Operator Overloading */
	myResult();
}
