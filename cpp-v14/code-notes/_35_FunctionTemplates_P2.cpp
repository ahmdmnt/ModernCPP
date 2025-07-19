/*
 * _35_Templates-P2.cpp
 *
 *  Created on: May 17, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <cstring>

/* Module Description:-
 * ---------------------
 * 	1. Explicit Specialization.
 *  2. Non-Type Template Arguments.
 */

/*
 * Explicit Specialization:
 * -------------------------
 *  - Template Specialized for a particular type.
 *  - Provide correct semantic for specific Data type.
 *  - Implement an optimal algorithm for specific data type.
 *  - Explicit Specialization, must be defined in a .cpp file.
 *  - Primary template definition should occurs BEFORE Explicit Specialization.
 */

// Primary Template
template<typename T>
T maxValue(T var1, T var2) {
	return var1>var2 ? var1:var2;
}

// Explicit Instantiation
template char maxValue(char var1, char var2);

// Explicit Specialization
template<>
const char* maxValue(const char* var1, const char* var2) {
//const char* maxValue<const char*>(const char* var1, const char* var2) {		// Adding <CAST> is optional
	std::cout << "Explicit Specialization Handling: " << std::endl;
	return strcmp(var1,var2)>0 ? var1:var2;
}
/****************************************************************************************************/

/*
 * Non-Type Template Arguments:
 * -----------------------------
 *  - Expression that is computed at compile time. within a template argument list.
 *  - MUST BE constant Expression; [Integral, Enums, NullPtr, STATIC Addresses, STATIC References]. "not POINTER to variable for example but Array Name.
 *  - Part of Template Type.
 *  - In Functions:: COMMONLY USED With Arrays.
 *  - Because i can pass an array without explicitly pass size of array.
 *  - MORE COMMON WITH CLASS TEMPLATE >>>> [TBD]
 */
template<int value>
void print() {
	//value++;			// Error only used as constant.
	std::cout << value << std::endl;
}

template<typename T, int size>
T sumOfArray(T (&refArr)[size]) {
	T sumResult {};
	for(auto i{0}; i<size; i++) {
		sumResult += refArr[i];
	}
	return sumResult;
}
// IMPORTANT NOTE::
// T (&refArr)[size] "a reference to an array of T"   //&&//   T& refArr[size] "array of references, which is not allowed in C++".


/****************************************************************************************************/
void _35_FunctionTemplates_P2() {		//-------------- MAIN FUNCTION -------------- //

	const char* A {"A"};
	const char* Z {"Z"};
	auto result = maxValue(A, Z);
	std::cout << "maxValue= " << result << std::endl;

	/****************************************************************************************************/
	int i {3};
	print<3>();
	//print<i>();		// Error only accept values, because it is set in compile time.

	int arr[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << "sumOfArray = " << sumOfArray(arr) << std::endl;

}

