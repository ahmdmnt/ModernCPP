/*
 * _41_TypeTraits_Templates.cpp
 *
 *  Created on: May 20, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <type_traits>

/* Type Traits:-
 * ---------------------
 * 	1. Find characteristics of type in compile time.
 * 	2. transform the properties of type.
 * 	3. useful in templates and template meta-programming.
 * 	4. will return either bool or type when type inspection is done.
 *	5. #include <type_traits>
 */

template<typename numeratorType__, typename denominatorsType__>
denominatorsType__ divideFu(numeratorType__ n1, denominatorsType__ n2) {
	if(std::is_floating_point<denominatorsType__>::value == false ) {
		std::cout<< "WARN: Using of floating Point denominator is a must!" << std::endl;
		return 0;
	}
	return n1/n2;
}

template<typename datatype__>
void checkAndremoveReference(datatype__&&) {
	// Check if Reference.
	std::cout<< std::boolalpha
	<< "Is Passed Value Reference? " << std::is_reference<datatype__>::value << std::endl;

	// Remove Reference and reCheck
	std::cout<< "Remove Reference and check is Reference? "
		<< std::is_reference<typename std::remove_reference<datatype__>::type>::value << std::endl;
}
void _41_TypeTraits_Templates() {

	/* Check a certain type .. is it integral or not */
	std::cout
	<< std::boolalpha
	<< "Is [int] integral?: "
	<< std::is_integral<int>::value << std::endl;

	std::cout<< divideFu(3,2) << std::endl;
	std::cout<< divideFu(3.0,2.0) << std::endl;
	std::cout<< divideFu(3,2.0) << std::endl;

	int value {5};
	checkAndremoveReference(5);
	checkAndremoveReference(value);
}


