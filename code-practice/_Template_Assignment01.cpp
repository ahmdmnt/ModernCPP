/*
 * _Template_Assignment01.cpp
 *
 *  Created on: May 23, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* TOPICS:-
 * --------
 * 	Convert the following functions into templates
 * 		- int Add(int x,int y) ; //Return the sum of two elements
 * 		- int ArraySum(const int *pArr, size_t arrSize); //Returns the sum of array elements
 * 		- int Max(const int *pArr, size_t arrSize) ; //Return the largest element in the array
 * 		- std::pair<int,int> MinMax(const int *pArr, size_t arrSize) ; //Return the smallest and largest element in a pair
 *
 * 		Take care to avoid copies of user-defined objects wherever applicable.
 */

template<typename retType__, typename argType__>
retType__ addFunction(argType__ num1, argType__ num2) {
	retType__ result {num1+num2};
	return result;
}

template<typename retType__, typename arrayType__, int SIZE>
retType__ addArrayFunction(arrayType__ l_array[SIZE]) {
	retType__ result {0};
	for(const auto& element: l_array) {
		result += element;
	}
	return result;
}

template<typename elementType__, int SIZE>
elementType__ maxElementFunction(elementType__ l_array[SIZE]) {
	elementType__ result {0};
	for(const auto& element: l_array) {
		result += element;
	}
	return result;
}

