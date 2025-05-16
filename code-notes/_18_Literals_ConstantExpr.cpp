/*
 * _18_Literals_ConstantExpr.cpp
 *
 *  Created on: May 5, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>

/* Literals:-
 * ----------
 * is a fixed value that appear directly in the code.
 * for example, value for int, floating point, characters, etc..
 *
 * - Some of these values can be modified by literal suffixes or prefixes.
 * 		14u		: unsigned int
 * 		620l	: long
 * 		10ul	: unsigned long
 * 		9.2f	: float
 *
 * User-Defined Literals:
 * -----------------------
 * User-defined suffixes that can be added to literals.
 * 	- Provide syntactic shortcuts.
 * 	- increase the type safety.
 * 	- user-defined literals starts by underscore "_LITERAL_NAME".
 * 	[SYNTAX]:
 * 	<RETURN_TYPE> operator""_<LITERAL_NAME>(<ARGUMENTS>)
 *		- Literal Operator function, ONLY global functions.
 *		- <RETURN_TYPE> : any type including void.
 *		- <ARGUMENTS>   : can be any primitive type available.
 */

class Distance {
	long double m_kilometers;

public:
	Distance(long double l_km) : m_kilometers{l_km} {}
	long double getKM() const {
		return m_kilometers;
	}
	void setKM(const long double& l_km) {
		m_kilometers = l_km;
	}
};

Distance operator""_km(long double l_value) {
	return Distance{static_cast<long double>(l_value)};
}
Distance operator""_m(long double l_value) {
	return Distance{l_value/1000};
}
Distance operator""_mile(long double l_value) {
	return Distance{l_value*1.6};
}

int getNumber() {
	return 42;
}
constexpr int getConstNumber() {
	return 42;
}

constexpr int addConstNumber(int n1, int n2) {
	return n1+n2;
}

void _18_Literals_ConstantExpr(void) {

	Distance dist1 {10.5_km};		// @suppress("Invalid arguments")
	std::cout<< "getKM() = " << dist1.getKM() << " km" << std::endl;

	Distance dist2 {2000.2_m};		// @suppress("Invalid arguments")
	std::cout<< "getKM() = " << dist2.getKM() << " km" << std::endl;

	Distance dist3 {10.4_mile};		// @suppress("Invalid arguments")
	std::cout<< "getKM() = " << dist3.getKM() << " km" << std::endl;


	/* keyword: constexpr
	 * -------------------
	 * 	- represent a constant variable/value.
	 * 	- evaluated in compile time, instead of run-time.
	 * 	- Increase code efficiency as it is computed in compile time.
	 * 	- can be applied to variable or function declaration.
	 *
	 * -Difference between const and constexpr?
	 * 	 - Increase code efficiency as it is computed in compile time.
	 *
	 * -What kind of Function can be constexpr?
	 * 	A function that can be computed in compile time.
	 * 	Which must accept and return only literal types.
	 * 	LIMITATION::: it can only have one return statement. [until C++14], implicitly inline.
	 *
	 */
	constexpr int c_value1 {10};
	//constexpr int c_value {getNumber()};			// ERROR: call to non-'constexpr' function 'int getNumber()'

	// HOWEVER BELOW IS OK -> becaus it is constexpr FUNCTION
	constexpr int c_value2 {getConstNumber()};	// OK

	const int c_value3 {10};						// OK : Compile time
	const int c_value4 {getConstNumber()};		// OK : Compile time
	const int c_value5 {getNumber()};				// OK : Run time -- At this situation we can't use this constant with compile time constants.

	int array[c_value1] {};							// can be used with expression that expect compile time constants.

	constexpr int sum = addConstNumber(1, 2);
	std::cout << "sum = " << sum << std::endl;

	/***********************************************************************************************************/
}

