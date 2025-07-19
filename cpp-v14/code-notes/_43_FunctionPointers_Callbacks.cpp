/*
 * _43_FunctionObjectsPointers_Callbacks.cpp
 *
 *  Created on: May 21, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "intData.hpp"

/* Module Description:-
 * ---------------------
 * 	Function Template with dynamic sorting behavior using Type Alias: Template Pointer to Function.
 * 	which point to desired template comparator functions.
 *
 * 	Disadvantage of using Function Pointers:
 * 	-----------------------------------------
 * 	 - Can NOT be optimized by the Compiler.
 * 	 - The Point to Global Function, Global Fu can NOT have state.
 * 	   for example, what if i want to know how many comparison has been made for each sort function.
 * 	   it will only be done by global variable, and it will be shared between different sort function invokation.
 *
 * 	   SOLUTION: Function Object.
 */

/* Prototype of Comparison function pointer */
template<typename arrayType__>
using cmpTypePtr = bool (*)(arrayType__, arrayType__);

template<typename arrayType__, int SIZE>
void sortArray(arrayType__ (&arrVariable)[SIZE], cmpTypePtr<arrayType__> cmpFunction) {
	for( auto mainItr{0}; mainItr<SIZE-1; ++mainItr ) {
		for( auto cmpItr{0}; cmpItr<SIZE-1; ++cmpItr ) {
			if( cmpFunction(arrVariable[cmpItr], arrVariable[cmpItr+1]) ) {		// Here is a callback occurs to the Function Pointer.
				arrayType__ tempElement = std::move(arrVariable[cmpItr]);
				arrVariable[cmpItr]     = std::move(arrVariable[cmpItr+1]);
				arrVariable[cmpItr+1]   = std::move(tempElement);
			}
		}
	}
}

/* Define the Desired --FUNCTION-- Comparator function */
template<typename arrayType__>
bool ascendingComparatorFu(arrayType__ n1, arrayType__ n2) {
	return n1>n2;
}
template<typename arrayType__>
bool descendingComparatorFu(arrayType__ n1, arrayType__ n2) {
	return n1<n2;
}

void _43_FunctionPointers_Callbacks() {

	// Normally, Above template functions can compare and sort any data type except string
	// in ascending order.
	// by using function pointer i can specify the type of cmp either ascending or descending.

	/* My Array */
	int intArray[10]  { 10, 4, 2, 3, 5, 8, 1000, -1, 23, 98};
	/* Check Array */
	for(const auto& element: intArray)
		std::cout << element << " ";
	std::cout << std::endl;
	/* Set My Comparator function in cmpTypePtr pfn */
	cmpTypePtr<int> cmpIntFuPtr = ascendingComparatorFu<int>;				// ASCENDING
	/* Call Sort Function */
	sortArray<int>(intArray, cmpIntFuPtr);
	/* Check Sorted Array */
	for(const auto& element: intArray)
		std::cout << element << " ";
	std::cout << std::endl;

	/* My Array */
	char charArray[5] { 'Z','E','F','C','K' };
	/* Check Array */
	for(const auto& element: charArray)
		std::cout << element << " ";
	std::cout << std::endl;
	/* Set My Comparator function in cmpTypePtr pfn */
	cmpTypePtr<char> cmpCharFuPtr = descendingComparatorFu<char>;			// DESCENDING
	/* Call Sort Function */
	sortArray<char>(charArray, cmpCharFuPtr);
	/* Check Sorted Array */
	for(const auto& element: charArray)
		std::cout << element << " ";
	std::cout << std::endl;

	/* My Array */
	intData intDataArray[3];
	intDataArray[0].setValue(30);
	intDataArray[1].setValue(20);
	intDataArray[2].setValue(10);

	/* Check Array */
	for(const auto& element: intDataArray)
		std::cout << element << " ";
	std::cout << std::endl;
	/* Set My Comparator function in cmpTypePtr pfn */
	cmpTypePtr<intData> cmpIntDataFuPtr = ascendingComparatorFu<intData>;	// ASCENDING
	/* Call Sort Function */
	sortArray<intData>(intDataArray, cmpIntDataFuPtr);
	/* Check Sorted Array */
	for(const auto& element: intDataArray)
		std::cout << element << " ";
	std::cout << std::endl;
}

