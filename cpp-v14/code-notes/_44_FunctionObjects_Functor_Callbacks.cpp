/*
 * _44_FunctionObjects_Callbacks.cpp
 *
 *  Created on: May 21, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "intData.hpp"

/* Function Object:-
 * ------------------
 * Function Object is an object of a class/struct, that has the function call operator overloading.
 * - Can be optimized, inline the function callback.
 * - it is an object, it can have a state and other members to be stored.
 * - More Efficient that Function Pointer.
 * - Usually made by struct rather than classes.
 *
 * Function Pointer				vs			Function Object
 * -------------------------				-------------------------
 * - Invoked through Pointer.				- Invoked through Object, by OperatorOverloading.
 * - Dynamic in Nature.						- Static in Nature.
 * - Specified in Runtime.					- Specified in Compile-time.
 * - Difficult to Optimize.					- Easy to Optimize.
 * - Slow in General.						- Fast in General.
 * - Can't store state, etc..				- Can store state, etc..
 *
 */

/* NO NEED FOR FUNCTION POINTER TYPE ALIAS,
 * Because, Function Object can be represented normally with typename */

template<typename arrayType__, int SIZE, typename cmpFuObj>
void sortArray(arrayType__ (&arrVariable)[SIZE], cmpFuObj cmpFunction) {
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

/* Define the Desired --FUNCTION OBJECTS-- Comparator */
template<typename arrayType__>
class ascendingComparator {
public:
	bool operator()(arrayType__ n1, arrayType__ n2) {
		return n1>n2;
	}
};
template<typename arrayType__>
struct descendingComparator {
	bool operator()(arrayType__ n1, arrayType__ n2) {
		return n1<n2;
	}
};

void _44_FunctionObjects_Callbacks() {

	// Normally, Above template functions can compare and sort any data type except string
	// in ascending order.
	// by using function pointer i can specify the type of cmp either ascending or descending.

	/* My Array */
	int intArray[10]  { 10, 4, 2, 3, 5, 8, 1000, -1, 23, 98};
	/* Check Array */
	for(const auto& element: intArray)
		std::cout << element << " ";
	std::cout << std::endl;
	/* Create a Object for FunctionObject. */
	ascendingComparator<int> ascendComparator;
	/* Call Sort Function */
	sortArray<int>(intArray, ascendComparator);				// Use it Directly in Sort Function typename> Pointer to function
	/* Check Sorted Array */
	for(const auto& element: intArray)
		std::cout << element << " ";
	std::cout << std::endl;

	/* My Array */
	intData intDataArray[3];
	intDataArray[0].setValue(30);
	intDataArray[1].setValue(50);
	intDataArray[2].setValue(10);

	/* Check Array */
	for(const auto& element: intDataArray)
		std::cout << element << " ";
	std::cout << std::endl;
	/* Create a Object for FunctionObject. */
	descendingComparator<intData> descendComparator;
	/* Call Sort Function */
	sortArray<intData>(intDataArray, descendComparator);	// Use it Directly in Sort Function typename> Pointer to function
	/* Check Sorted Array */
	for(const auto& element: intDataArray)
		std::cout << element << " ";
	std::cout << std::endl;
}
