/*
 * _06_OOP_RuleOf5.cpp
 *
 *  Created on: Apr 23, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>
#include "intData.hpp"

/* RULE OF 5:-
 * ------------
 * If a class has ownership semantics, You must provide user-defined:
 * 	- Copy Constructor
 * 	- Move Constructor
 * 	- Copy assignment Operator
 * 	- Move assignment Operator
 * 	- Destructor
 *	This is IMPORTANT, to ensure, Proper handling of underlying resources.
 *
 * Ownership Semantics: Resources such as Pointer, File Handle, Socket, etc..
 * that needs constructor for allocation, and may be it is copied or moved,
 * and needs also, destructor for deallocation to avoid memory leak.
 */

/* RULE OF 0:-
 * ------------
 * If a class DOESN'T have ownership semantics, then it doesn't provide user-defined
 * functions for rule of 5.
 *
 * [[IMPORTAN]]:: The Compiler will auto generate the necessary functions for the class.
 * BUT,, if we provide some user-defined implementation, COMPILER WILL NOT provide rest of functions.
 */

class heapData {
public:
	intData numData {};
	/******************************************************************************** RULE OF 0 */
	heapData() {};
	heapData(int l_value) : numData{l_value} {};		// will call Parameterized Constructor of iData class.

	/************************************************************************* END OF RULE OF 0 */
	/* Since i didn't defined any function here the compiler will auto-generate the functions
	 * automatically, but because this class is having a member that have user-defined function.
	 * it will use by default the user-defined function within the iData Class instead */
};

heapData addData(const heapData &n1, heapData &n2) {
	heapData l_heapData;

	l_heapData.numData.setValue(n1.numData.getValue() + n2.numData.getValue());
	return l_heapData;
}

void _06_OOP_RuleOf5() {
	heapData num1 {50};						// Parameterized Constructor
	std::cout << "num1 = " << num1.numData.getValue() << std::endl << std::endl;

	heapData num2 {num1};					// Copy Constructor // @suppress("Invalid arguments")
	std::cout << "num2 = " << num2.numData.getValue() << std::endl << std::endl;

	heapData num3;							// Default Constructor
	num3 = addData(num1,num2);				// Move Constructor to get Object return to R-Value here, then Copy Assign Operator to num3
	std::cout << "num3 = " << num3.numData.getValue() << std::endl << std::endl;

	heapData num4 {addData(num1,num2)};		// Move Constructor // @suppress("Invalid arguments")
	std::cout << "num4 = " << num4.numData.getValue() << std::endl << std::endl;

	/******************************************************************************************************************************************/

	/* std::move() library:-
	 * ----------------------
	 * 	- always used with l-value.
	 * 	- forces the compiler to use move() instead of copy().
	 * 	- NOT used with primitive datatype, it is redundant and has no affect, it will still copy.
	 *
	 * 	What is the Advantage of using Move ??
	 * 	If i have an Object that is needed for some certain function, and after that function execution it is not needed.
	 * 	 >> so i can pass this Object to function in Argument by VALUE, then in the function calling i can use the std::move().
	 * 		AT THIS CASE: I am moving the Object to that function and the Variable is no longer available with me,
	 * 		and when this function finish the variable will be destroyed totally. -- "OLD VALUE NOT ACCESSIBLE ANY MORE!!".
	 * 		BUT THE OBJECT is still available i can do implementation to [[[RE-INITIALIZE IT]], and use it again.
	 */
	auto copyNum {num1};	// By Default the Compiler will use the Copy Semantic // @suppress("Invalid arguments")
	std::cout << "copyNum = " << copyNum.numData.getValue() << std::endl << std::endl;

	/* What if i need to move the object to another one?
	 * 1. Use the static_cast<TYPE>().
	 * 2. Use std::move() [Preferable] -- simply cause cast to RVR */
	auto staticCastNum {static_cast<heapData&&>(num4)};	// Force num1 to be RVR, so move will be used. // @suppress("Invalid arguments")
	std::cout << "staticCastNum = " << staticCastNum.numData.getValue() << std::endl << std::endl;
	auto moveNum {std::move(staticCastNum)};						// STL used to indicate that i need to move instead of Copy // @suppress("Invalid arguments")
	std::cout << "moveNum = " << moveNum.numData.getValue() << std::endl << std::endl;


}
