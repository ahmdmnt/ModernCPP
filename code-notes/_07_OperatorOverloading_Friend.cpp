/*
 * _07_OperatorOverloading_Part01.cpp
 *
 *  Created on: Apr 24, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>
#include "intData.hpp"

/* Module Description:-
 * ---------------------
 * 	1. Copy and Move Assignment Operator Overloading.
 * 	2. Addition Operator Overloading.
 * 	3. Subtraction Operator Overloading.
 * 	4. Increment Operator Overloading.
 * 	5. Check Equality Operator Overloading.
 * 	6. Addition Global Operator Overloading "intValue+object".
 * 	7. Input and Output Stream Operator Overloading.
 * 	8. Friend Keyword: friend.
 * 	9. RULES.
 */

/* [[IMPORTANT]] Operator Overloading Rules:-
 * --------------------------------------------
 * 	1. Basic Behavior of Operators does not change when overloading is used.
 * 		- Associativity, precedence, operand count -> doesn't changes.
 * 	2. Operator Overloading function should be [non-static]
 * 		- except for new and delete only.
 * 	3. AT LEAST one Argument should always be user-defined type, otherwise compiler will reject.
 * 	4. if first argument is primitive type, it HAS TO BE overloaded as Global Function not class method.
 * 	5. not all operators can be overloaded; dot[.], ternary[?:], pointer to member[.*], sizeof() operators.
 *	6. CAN NOT define new operators in overloading not available in C++.
 *	7. Overloaded function, shall be mimicking the basic behavior of operator in user defined types "to avoid confusion for users".
 */

/* Operator Overloading Global Function:-
 * --------------------------------------- *
 * Because this is Operator Overloading Globally, I NEED to add ALL Operands
 */
/* (-) Subtraction Operator Overloading */
intData operator-(const intData &Obj1, const intData &Obj2) {
	std::cout << "operator-() - Subtraction Operator Overloading Invoked..." << std::endl;
	intData result;
	result.setValue(Obj1.getValue() - Obj2.getValue());
	return result;
}

/* (int+Object) Addition Global Operator Overloading */
//intObj operator+(int&& num, const intObj &Obj) {			// will accept onlt R-Value
intData operator+(const int& num, const intData &Obj) {		// will accept both L-Value and R-Value
	std::cout << "operator+() - Addition: [int+object] Operator Overloading Invoked..." << std::endl;
	intData result;
	result.setValue(num + Obj.getValue());
	return result;
}
/* (<<) Output stream Operator Overloading */
std::ostream& operator<<(std::ostream &out, const intData &Obj) {
//	std::cout << "operator<<() - Output stream Operator Overloading Invoked..." << std::endl;
//	out << "Object= " << Obj.getValue();
	return out << Obj.getValue();		// return is reference because we are not returning local variable.
}
/* (>>) Input stream Operator Overloading -- [FRIEND METHOD] */
std::istream& operator>>(std::istream &in, intData &Obj) {
	std::cout << "operator>>() - Input stream Operator Overloading Invoked..." << std::endl;
	int l_value {};
	in >> l_value;
	//	Obj.setValue(l_value);
	*Obj.pInt = l_value;
	return in;
}
/*********************************************************/

class printer {		// [FRIEND CLASS]
public:
	void exe(const intData &obj) {
		std::cout<< "Printer Value = " << *obj.pInt << std::endl << std::endl;	// OK, because it is friend function to class.
	}
};


void _07_OperatorOverloading_Friend() {

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
	intData num1 {10}, num2 {30};
	std::cout<< "num1 = " << num1.getValue() << std::endl;
	std::cout<< "num2 = " << num2.getValue() << std::endl << std::endl;

	/* Addition */
	intData myResult = num1+num2;
	std::cout<< "myResult = " << myResult.getValue() << std::endl << std::endl;

	/* Subtraction */
	myResult = num2-num1;
	std::cout<< "myResult = " << myResult.getValue() << std::endl << std::endl;

	/* Pre-Incremenet */
	++num1;
	std::cout<< "num1 = " << num1.getValue() << std::endl << std::endl;

	/* Post-Increment */
	intData num3 = num1++;	// num3 will have original value of num1 -- and num1 then will be ++
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


	/* Friend Keyword:-
	 * ----------------
	 * If I need in some specific scenarios to access PRIVATE member of a Class.
	 * This is the situation where i need to use friend keyword.
	 * NOT COMMONLY USED: because it can cause bugs and issues. */
	intData myNum;
	std::cout << "Enter Object Value: "; std::cin >> myNum;
	std::cout << myNum;
	printer myPrinter;
	myPrinter.exe(myNum);
}
