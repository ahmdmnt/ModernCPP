/*
 * _45_LambdaExpression.cpp
 *
 *  Created on: May 21, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Lambda Expression:-
 * ---------------------
 * - Defines an Anonymous function object (Nameless Function Object).
 * - Syntactic SHORTCUT of Function Object.
 * - Encapsulate afew line of codes.
 * - Can be passed as an Argument.
 * - Can Accept Parameters and Return Values.
 * - Behave like normal function when invoked.
 * - Can replace Function Object in many cases.
 * - You can use auto to assign Lambda Expression with a name.
 *
 * SYNTAX:
 * 	[CAPTURE_CLOSURE](ARGS)<MUTABLE><EXCP_SPECIFICATION> -> <RET_TYPE> {
 * 		..IMPLEMENTATION..
 * 	}
 */

void _45_LambdaExpression() {

	/* Simple Lambda Expression - Anonymous/Nameless Function Object */
	[]() {
		std::cout<< "This is a Lambda Expression" << std::endl;
	}();		// adding () after Lambda Expression braces, trigger the function call. can not be called again.

	/* Assigning Lambda Expression to Function Object */
	auto fuObj = [](int n1, int n2) -> int {			// explicitly mentioning return type is optional.
		std::cout<< "Sum = " << n1+n2 << std::endl;
		return n1+n2;
	};
	fuObj(10, 20);		// Call Lambda Expression
	std::cout<< typeid(fuObj).name() << std::endl;
	std::cout<< "-----------" << std::endl;

	/* [C++14]: Generic Lambda - Similar to templates */
	auto CalcProcess = [](auto num1, auto num2) {
		std::cout<< "Add = " << num1+num2 << std::endl;
		std::cout<< "Sub = " << num1-num2 << std::endl << "-----------" << std::endl;
	};
	CalcProcess(10,10);
	CalcProcess(2.5,7.9);
	CalcProcess(7.9f,1.0);
}

