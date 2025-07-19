/*
 * _42_StaticAssert.cpp
 *
 *  Created on: May 21, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Static Assertion:
 * ------------------
 * 	Introduced in C++, used for evaluating expression.
 *  - Used in testing an expressions in compile time.
 *  - If expression return false, Compiler will display the message and compilation fails.
 */

template<typename numeratorType__, typename denominatorsType__>
denominatorsType__ divideFu(numeratorType__ n1, denominatorsType__ n2) {

	/* Static Assert with Type traits */
	static_assert( (std::is_floating_point<denominatorsType__>::value), "ERROR: Using of floating Point denominator is a must!" );
	return n1/n2;
}

void _42_StaticAssert() {
	/* Static Assert, to make sure code is only compiled in 32-bit mode, if not code won't compile */
	static_assert( (sizeof(void*)==8),"Error: Compilation is allowed in 64-bit ONLY!" );

	/* Static Assert with Type traits */
	//std::cout<< "Division: " << divideFu(1,2) << std::endl;
	std::cout<< "Division: " << divideFu(3,2.0) << std::endl;
}

