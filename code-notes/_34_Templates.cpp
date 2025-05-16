/*
 * _34_Templates.cpp
 *
 *  Created on: May 16, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Templates:-
 * ------------
 *
 *
 *	template<typename T>
 *	starting withe keyword template,,, means it is a template function.
 *		<typename T> or <class T> .. this is the placeholder that will receive the changing data type. [diff. in Advanced Template Programming TBD.].
 *
 *
 */


//int maxNumber(int n1, int n2) {
//	return n1>n2 ? n1:n2;
//}
//float maxNumber(float n1, float n2) {
//	return n1>n2 ? n1:n2;
//}
// Instead of writing multiple function overloading with same code,, it is Better to use template..

template<typename T>
T maxNumber(T n1, T n2) {
	const std::type_info &ti = typeid(T);
	std::cout<< "Calling typeid()= " << ti.name() << std::endl;
	return n1>n2 ? n1:n2;
}

void _34_Templates(void) {

	/* IN COMPILE TIME:
	 * Compiler will check function arguments,,
	 * and create the corresponding functions from the desired datatypes.
	 */

	auto maxInt {maxNumber(3, 8)};
	std::cout << "maxInt= " << maxInt << std::endl << std::endl;

	auto maxFloat {maxNumber(3.1f, 8.0f)};
	std::cout << "maxFloat= " << maxFloat << std::endl << std::endl;

	auto maxDouble {maxNumber(3.1, 8.0)};
	std::cout << "maxDouble= " << maxDouble << std::endl << std::endl;
}
