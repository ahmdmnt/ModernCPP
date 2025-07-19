/*
 * _50_decltype.cpp
 *
 *  Created on: May 24, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* DECLTYPE Description:-
 * ---------------------
 * decltype is a keyword used to query the type of an expression at compile time.
 * It's especially useful when dealing with templates or complex types where the type might not be obvious.
 *
 */


template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) {			// Usage: Type deduction in templates:
	return a + b;
}



void _50_decltype() {
	int x = 5;
	decltype(x) y = 10;				// y is of type int, declares a variable with the same type as the expression.
	std::cout << typeid(y).name() << std::endl;

	const double pi = 3.14;
	decltype(pi) radius = 2.0;		// radius is of type const double, declares a variable with the same type as the expression.
	std::cout << typeid(radius).name() << std::endl;

	std::cout << add(10, 10) << std::endl;
	std::cout << add(10.5, 11.2f) << std::endl;
}

