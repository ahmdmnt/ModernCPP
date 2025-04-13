/*
 * _01_Basics_Part01.cpp
 *
 *  Created on: Apr 7, 2025
 *      Author: AhmedMontasser
 */

/*
 * Module Description:
 *	1. Initialization Types.
 *	2. Uniform Initialization.
 *	3. Null pointer.
 *	4. References vs pointers.
 *	5. keyword: auto.
 */

#include <iostream>

void _01_Basics_Part01(void) {
	/* Initialization Types:-
	 * ------------------------
	 * 	1. Copy Initialization	: Avoid with user-defined types
	 * 	2. Direct Initialization	: Avoid with primitive types, when value is left empty.
	 * 	3. Uniform Initialization: Recommended to be used.
	 */
	int a1;						// Uninitialized
	int a2 = 0;					// Copy Initialization
	int arr1[3] = {1, 2, 3};	// Aggregate Initialization
	std::string str1;			// User-defined Object -- unlike primitive types, it is initialized by default constructor
	int a3 (3);					// Direct Initialization -- not commonly used
	// int a3();				// This is function calling instead of init. (MOST VEXING PARSE)

	/*  Uniform Initialization:-
	 * --------------------------
	 * 	[SYNTAX] :: variableType variableName {VALUE}
	 * 		- Uniform Syntax for all types.
	 * 		- Avoid incompatible initialization types through compiler errors/warnings.
	 * 		- Prevent narrowing conversions.
	 */
	int num   {4};
	int arr[3] {};
	int *data_ptr = new int {};

	/* Null Pointer:-
	 * ---------------
	 *  1. NULL Macro :
	 *  2. nullptr    : type safe and better than the old Null macro.
	 *  	Can not read or write from nullptr (Access violation)
	 */
	int *ptr = nullptr;

	/* Reference Type:-
	 * -----------------
	 * Alternative name or an alias for a variable.
	 * [SYNTAX] :: variableType &variableName = referentName
	 * 	- Created with &NAME in declaration.
	 * 	- It modifies the variable value indirectly, same like pointers.
	 * 	- Unlike pointer, it is just a name, no new variable is created and no memory is used
	 * 	- ALWAYS need an initializer, called as a referent.
	 * 	- Referent is always a variable not a literal.
	 */
	int origVariable {10};
	int &refVariable {origVariable};	// Reference Type, must be INITIALIZED.
	refVariable = 300;
	std::cout << "origVariable= " << origVariable << " - refVariable= " << refVariable << std::endl;
	std::cout << "Addresses: " << &origVariable << "-" << &refVariable << std::endl;

	int newVariable {20};
	refVariable = newVariable;		// This is NOT new Referent, it is only copying value of newVariable in refVariable
	std::cout << "Addresses: " << &origVariable << "-" << &refVariable << "-" << &newVariable << std::endl;

	/* Difference between Pointers and Refernce:-
	 * -------------------------------------------
	 * Reference:											Pointer:
	 * ----------											---------
	 * - Always need an initializer.						- Initializer is optional.
	 * - Initializer should be l-value,	except with const.	- Initializer is not mandatory to be l-value.
	 * - Can't be nullptr.									- Can be nullptr.
	 * - Bound to one Referent.								- Can point to other variables.
	 * - No Memory used, only name alias.					- Has memory storage, different variable created.
	 * - Access Value: No dereference.						- Access Value: Dereference required.
	 * - Don't need to check for null.						- Need null ptr protection.
	 ******************************************************************************************/

	/* Constant Qualifier:-
	 * ----------------------
	 * [SYNTAX] :: const variableType VARIABLE_NAME {variableValue};
	 * Replacement for C Macros, because;
	 * 	- Not type safe.
	 * 	- doesn't have a scope.
	 * 	- hard to debug.
	 */
	const float PI {3.14159f};			// scoped fixed value variable.

	const float &REF_PI {3.14159f};		// Only case Reference assigned to literal, because it is const and not changable.
	/* BEST PRACTICE: Always used CONSTANT REFERENCE, when Passing function arguments:
	 * - Easier to use - Simple syntax than Pointers.
	 * - ability to easier pass l-value or simple literal
	 * - No Memory used. */

	/* [C++11] Keyword: auto:-
	 * -------------------------
	 * Allow compiler to deduce variable type from its Initializer,
	 * very useful with lambda expression and c++ templates.
	 * [SYNTAX] :: auto variableName {variableValue};
	 * 	- Initializer is important!
	 * 		- Literal.
	 * 		- Mathematical Expression.
	 * 		- Function call return value.
	 */
	//auto var0;						// Initializer is must
	auto var1 {10}, var2 {20};		// deduced as int
	auto sum {var1+var2};			// deduced as largest type of both
	std::cout << "Sum= " << sum << std::endl;

	auto &refVar = var1;		// const int &REF, Qualifier not discarded!
	auto ptrVar = &var1;		// const int *PTR, Qualifier not discarded!

	/* NOTE:: Uniform Initialization is not working with std::initializer_list */
	auto init_list = {1,2,3,4,5,6}; // = sign is needed to skip the error (Copy Initialization)
}
