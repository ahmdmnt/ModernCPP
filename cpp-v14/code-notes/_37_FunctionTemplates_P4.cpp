/*
 * _37_FunctionTemplates_P4.cpp
 *
 *  Created on: May 18, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "intData.hpp"


/* Variadic Template:-
 * --------------------
 * Template function that can accept any type of data and any number of data.
 *
 * For Example Handling of Variadic Template function call: print(1,2,"ahmed",3,'s')
 * 	1. print(1,2,"ahmed",3,'s');
 * 	2. print(2,"ahmed",3,'s');
 * 	3. print("ahmed",3,'s');
 * 	4. print(3,'s');
 * 	5. print('s');
 * 	6. print();		<< Stop Recursion.
 *******************************************************************************/


/* ---- Variadic Templates ---- */
void print() {				// HAVE TO BE ABOVE VARIADIC TEMPLATE
	std::cout<< std::endl << "BaseCase: RecursionTerminated!" << std::endl;
}
template<typename firstArg__, typename...parameters>				// parameters: (type pack) alias of list of type name: can accept any type and number of args.
void print(firstArg__&& arg, parameters&&... args) {				// Pass Args by constant reference or &&, to AVOID MULTIPLE COPIES.
	/* TO ACCESS, Passed Argument,
	 * you can use recursion, each time use an arg; from left hand side.
	 * and each time the number of args decreased by one, until all arguments are used.
	 * >> Recursion Termination is needed (Base Case). */
	std::cout << arg;
	if( sizeof...(args) ) {
		std::cout<< ", ";
	}
	print(std::forward<parameters>(args)...);			// When (args...) is empty; Base Case Function is called.
	// Appropriate Forwarding either, L-Value or R-Value to print recursion function.
}

/**********************************************************************************************************************/

void _37_FunctionTemplates_P4() {

	print(1);
	print(1,2,3);
	print(1,2,3,'z');
	print(1,2,"ahmed",3,'s');
	print(1,2,"ahmed",3,'s', static_cast<intData>(50));

}

