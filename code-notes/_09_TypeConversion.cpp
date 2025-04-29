/*
 * _09_TypeConversion.cpp
 *
 *  Created on: Apr 29, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "intData.hpp"

/* Module Description:-
 * ---------------------
 * 	1. Types of Conversion.
 * 	2. C++ vs C Style Converison.
 * 	3. Basic to Basic Conversion
 * 		- static_cast
 * 		- reinterpret_cast
 * 		- const_cast
 * 	6. User defined to Basic Conversion.
 * 	7. Type Conversion Operator Overloading and explicit keyword.
 * 	8. User defined to User defined Conversion.
 */

class productData {
	intData m_Id;
public:
	productData(const intData &id): m_Id(id) {};
	const intData& getIntData() const {
		return m_Id;
	}
	explicit operator intData() {
		return m_Id;
	}
};


void _09_TypeConversion(void) {

	/* Type Conversion:-
	 * -------------------
	 * Conversion between types, performed through cast.
	 * 	- Implicit cast: Compiler.
	 * 	- Explicit cast: User.
	 * Explicit cast, uses casting operators.
	 * Conversion types:
	 * 	- basic > basic.
	 * 	- basic > user-defined.
	 * 	- user-defined > basic.
	 * 	- user-defined > user-defined.
	 *
	 * C-Style cast is not recommended in C++, because they don't check the validity of the cast.
	 * instead, C++ cast is used.
	 * Why to use C++ Style cast instead of C-Style??
	 * 	- Can cause more bugs.
	 * 	- hard to check issues related to it.
	 */

	unsigned int n1 {5}, n2 {2};

	/* static_cast<TYPE>():		[basic <> basic]:
	 * -------------------------------------------
	 * 	 1. Validation check is done, to check if casting is valid or not.
	 * 		for example, compiler won't cast int* to char*.		>> what if i need to do this??
	 */
	float result {static_cast<float>(n1)/n2};
	std::cout << "result= " << result << std::endl;
	const int value {INT_MAX};
	//char* ptr {static_cast<unsigned char*>(&value)};		// ERROR: invalid 'static_cast' from type 'int*' to type 'char*'


	/* reinterpret_cast<TYPE():	[basic <> basic]:
	 * ------------------------------------------
	 * 	 1. Allow cast between two different type, even if it is prohibited.
	 * 	 2. it will not discard source type qualifiers.
	 */
	//short* ptr {reinterpret_cast<short*>(&value)};		// ERROR: 'reinterpret_cast' from type 'const int*' to type 'short int*' casts away qualifiers
	const short* ptr1 {reinterpret_cast<const short*>(&value)};
	std::cout << std::hex << "ptr1= 0x" << *ptr1 << std::endl;

	/* const_cast<TYPE():		[basic <> basic]:
	 * ------------------------------------------
	 * 	 1. Validation check is done, to check if casting is valid or not.
	 * 	 2. it will accept casting of const variable in non-constant pointers.
	 */
	const short value2 {32767};
	short* ptr2 {const_cast<short*>(&value2)};
	std::cout << std::hex << "ptr2= 0x" << *ptr2 << std::dec << std::endl << std::endl;

	/* const_cast<TYPE():		[basic <> user-defined]:
	 * -----------------------------------------
	 * 	 1. Validation check is done, to check if casting is valid or not.
	 * 	 2. it will accept casting of const variable in non-constant pointers.
	 */
	intData myObj {5};

	std::cout<< "myObj= "<< myObj.fetchValue() << std::endl;


	/* Scenarios where the Compiler Implicit Cast:
	 * 	Primitive Type to User Defined Type. */
	intData a1 {5};		// NO CAST.
	intData a2 = 5;		// Implicit cast to use Parameterized Constructor
	a1 = 7;				// Implicit cast to use Assignment Operator
	/* [IMPORTANT]: TO DISABLE COMPILE FROM IMPLICIt CAST:
	 *   -> use explicit keyword before Constructors and Assignment Operators. */

	/* User-Defined to Basic Type Conversion
	 * Type Conversion Operator Overloading Function:
	 * 	- Function that convert from user-defined type to basic type
	 * 	- Does not has return or arguments */
	//	int num3 = a1;		// Implicit Casting will be done with type conversion operator ...
	// BEST Practice --  Use Explicit keyword. to make sure that casting is inteded by user
	int num3 = static_cast<int>(a1);
	std::cout<< "num3= "<< num3 << std::endl;


	/* User-Defined to  User-Defined Type Conversion
	 * Type Conversion Operator Overloading Function:
	 * 	- Function that convert from user-defined type to basic type
	 * 	- Does not has return or arguments */
	productData myProd {10};
	//intData myData = myProd;		// error: conversion from 'productData' to non-scalar type 'intData' requested

	/* Solutions:
	 * 	1. Function return intData variable.
	 * 	2. Type Conversion Operator */
	intData myData_1 = myProd.getIntData();
	std::cout<< "myData_1= "<< myData_1.fetchValue() << std::endl;

	intData myData_2 = static_cast<intData>(myProd);	// == intData myData_2 = myProd.operator intData();
	if(myData_2 == static_cast<intData>(myProd)) {
		std::cout<< "myData_2 = myProd " << std::endl;
	}


	/* Difference Between Initialization and Assignment
	 * Initialization									Assignment
	 * 	- Less Function Calls to set values.			 - More function calls to set values.
	 *
	 * Member-Initializer List:-
	 * ---------------------------
	 * When Initializing Object with another Object.. it is better to use Member-Init List.
	 * to avoid Assigning in Object Constructor
	 * 		# myClass(const otherClass& local): myMember(local) {}
	 */
}


