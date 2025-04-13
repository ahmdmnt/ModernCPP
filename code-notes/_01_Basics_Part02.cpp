/*
 * _01_Basics_Part02.cpp
 *
 *  Created on: Apr 7, 2025
 *      Author: AhmedMontasser
 */

/*
 * Module Description:
 * 	1. Range-Based For Loop.
 * 	2. Function Overloading.
 * 	3. Default Function Arguments.
 * 	4. Inline Function.
 * 	5. Function Pointer.
 * 	6. namespace keyword.
 */

#include <iostream>

extern "C" int _fuOverloading_AddFunction(const int &num1, const int &num2);
float _fuOverloading_AddFunction(const float &num1, const float &num2);
std::string _fuOverloading_AddFunction(const char &char1, const char &char2);
void _fuDefaultArgument_CreateWindow(const std::string &title, const int &x=-1, const int &y=-1, const int &width=-1, const int &height=-1);
inline long long int _inlineFu_Square(int number);
void EndMessage(void);
/* Name space Topic */
namespace average {		// Name space is visible in source .cpp >> this file in that situation without using namespace.
	float calculate(float num1, float num2) {
		return ((num1+num2)/2);
	}
}
namespace sum {
	int calculate(int num1, int num2) {
		return num1+num2;
	}
}
/***********************************/


void _01_Basics_Part02(void) {

	/* [C++11] Range-Based For Loop:-
	 * --------------------------------
	 * [SYNTAX] ::
	 * 		for( variableType variableName : rangeName )
	 * 			{ .. STATEMENTS .. }
	 * It Allows Iteration on arrays and containers
	 * 	- It doesn't need index variable.
	 * 	- Each iteration return element directly.
	 * 	- Can be used with any object behave like range.
	 * 	- No way go away of Array/Range Bounds.
	 * 	- No End condition needed.
	 * 	- Lesser chances of errors.
	 * 	- Normal C For Loop, has more controlling
	 */
	int myArray[] {1, 2, 3, 4, 5, 6};
	/* BEST PRACTICE: auto for type deduce -- &ref avoid creating new variable -- const if needed */
//	for(const auto &element : myArray)	_OR_
	for(const auto &element : {1, 2, 3, 4, 5, 6})	// Pass directly Range- R-Values.
		std::cout << element << " ";
	std::cout << std::endl;

	/* START - Pesudo Code of Range-Based for loop implementation */
	auto &&arrRange = myArray;				// IMPORTANT: Forwarding Reference, to be able to Pass either RangeVariable or R-Values
	auto arrBegin = std::begin(arrRange);	// Pointer to Beginning of Array "First Element"
	auto arrEnd   =   std::end(arrRange);	// Pointer to End of Array "Last Element"
	for( ; arrBegin!=arrEnd ; ++arrBegin ){
		std::cout << *arrBegin << " ";
	}
	std::cout << std::endl;
	/* END - Pesudo Code of Range-Based for loop implementation*/

	/* Function Overloading:-
	 * -----------------------
	 * 2 or more functions have the same name with different behavior.
	 * 	- Arguments have different types or different count.
	 * 	- return type is ignored in overload.
	 * 	- Different function is chosen based on the function arguments.
	 * 	- If Argument is Reference/Pointer... Qualifier applied it will participate in overloading [IMPORTANT].
	 * 	- Member Function... Qualifier applied it will participate in overloading [IMPORTANT].
	 * 	- Function overload resolve is done in Compile time.
	 *
	 * 	How Compile know difference between functions?
	 * 	----------------------------------------------
	 * 	From Developer p.o.v. all function has the same name, for easier practice.
	 * 	Compiler differentiate between functions using "Name Mangling":
	 * 		- Unique name is created for each functions by Compiler, depending on type and number of function args.
	 * 		- To allow linker to link the call with correct overloaded function.
	 * 		- [IMPORTANT]: C++ Functions are not callable from C code.
	 *
	 * extern "C":-
	 * -------------
	 * [SYNTAX]::
	 * 		extern "C" {
	 * 			FUNCTION NAME(S)...
	 * 			VARIABLE NAME(S)...
	 * 		}
	 * Compiler directive applied on Global functions and variables.
	 * 	- Suppresses the Name Mangling from Function and Variables.
	 * 	- Can be applied to one of the functions from the Overloaded function ONLY.
	 * 	- This will allow the C++ Function callable from C and other languages.
	 * 	- extern "C", MUST be written in function definition and Declaration also, otherwise Linker Error pops up.
	 * 		> IF DECLARATION of function is not in same file of Function Definition, otherwise extern "C" only sufficient in Declaration.
	 * IF Map file is checked after code build, this function with extren "C" the Mangling is suppressed.
	 */
	int result1 = _fuOverloading_AddFunction(10, 20);
	std::cout << "Sum of Integers = " << result1 << std::endl;

	double result2 = _fuOverloading_AddFunction(10.5f, 20.2f);
	std::cout << "Sum of Floats = " << result2 << std::endl;

	std::string result3 = _fuOverloading_AddFunction('A', 'B');
	std::cout << "Sum of Chars = " << result3 << std::endl;


	/* Default Function Arguments:-
	 * -----------------------------
	 * Allow to assign default values to some/all the arguments.
	 * 	- It is assigned in the function declaration.
	 * 	- Optional for the user to pass values or not for these default arguments.
	 * 	- Simplify the function call.
	 * 	- We have to start passing default values from the left side, TILL THE END.
	 */
	_fuDefaultArgument_CreateWindow("Default Values");
	_fuDefaultArgument_CreateWindow("Passed Values",1,2,3,4);


	/* Inline Function:-
	 * ------------------
	 *	- Marked with inline keyword.
	 *	- Such function is defined in header function not CPP file.
	 *	- No function is called, instead assmebly code is generated directly.
	 *		> No Stack Memory used or context switching occurs.
	 *	- Compiler replace the function call with function body directly.
	 *	- Improve the performance of code, but increase the code size.
	 *	- Certain functions may not be inlined, compiler ignores it.
	 *		> large functions, functions have too many conditional statements, recursion, function invoked by pointer, etc..
	 *
	 *	Inline functions:							vs		Macros:
	 *	------------------									--------
	 *	- The call is replaced with function body.			- Works through Text replacement.
	 *	- Safe as it has function semantics.				- Errors can occurs because of simple text substitution.
	 *	- Simple to use with multiple code lines.			- Very difficult to use with multiple code lines.
	 *	- Can be used for member function in class.			- Can NOT be used for member function in class.
	 *	- Recommended to be used in CPP						- Not recommended.
	 */
	std::cout<< _inlineFu_Square(5+1) << std::endl;

	/* Function Pointer:-
	 * -------------------
	 * 	- Pointer that can hold address of a function.
	 * 	- Type of pointer, is the same like function signature.
	 * 	- Used to indirectly invoke a function, without knowing its name.
	 * 	- Used by algorithms and classes for customization.
	 * [SYNTAX]:
	 * 	RETURN_VALUE (*PTR_NAME)(FU_ARGUMENTS) = &FU_NAME;		// & is Optional to add or removed
	 */
	void (*fuPtr)(const std::string&, const int&, const int&, const int&, const int&) = _fuDefaultArgument_CreateWindow;
	(*fuPtr)("PointerToFunction",10,20,30,40);
	atexit(EndMessage);		// Call-back Function, that accept function pointer and execute it at End of MAIN Program.

	/* namespace keyword:-
	 * -------------------
	 * 	- Named declarative region for declaring types.
	 * 	- types are not visible outside the namespace (scope).
	 * 		> to use outside the scope you have to add namespace name before variable name separated with "::".
	 * 	- Standard library is declcared in std namespace.
	 * 	- Prevent name clashes; when to types have the same name.
	 * 	- Helps for code modularization.
	 * [SYNTAX]:
	 * 	namespace NAMESPACE_NAME {
	 * 		.. ANY C++ TYPES ..
	 * 	}
	 *
	 * For using datatypes from namespace
	 * 1. open the whole namespace
	 * 		using namespace NAMESPACE_NAME;			// opened in the scope where the line is used.
	 * 2. open namespace of specific type
	 * 		using NAMESPACE_NAME::TYPE_NAME;			// opened only the needed type.
	 * 3. write whole name qualifier
	 * 		NAMESPACE_NAME::TYPE_NAME ... ;
	 */
	using namespace average;	// average namespace will be visible in scope.
	std::cout<< "Average Calculate:  " << calculate(10,20) << std::endl;
	std::cout<< "Sum Calculate:  " << sum::calculate(10,20) << std::endl;
}
/*************************************************************************************************************************************/


/* Function Overloading Topic */
int _fuOverloading_AddFunction(const int &num1, const int &num2) {	// Mangling is suppressed from here.
	return num1 + num2;
}
float _fuOverloading_AddFunction(const float &num1, const float &num2) {
	return num1 + num2;
}
std::string _fuOverloading_AddFunction(const char &char1, const char &char2) {
	std::string newString {};

	newString+=char1;
	newString+=char2;
	return newString;
}
/***********************************/
/* Function Default Argument Topic */
void _fuDefaultArgument_CreateWindow(const std::string &title, const int &x, const int &y, const int &width, const int &height) {
	std::cout << "Title: " << title << std::endl;
	std::cout << "X Position : " << x     << " - " << "Y Position : " << y << std::endl;
	std::cout << "     Width : " << width << " - " << "    Height : " << height << std::endl << std::endl;
}
/***********************************/
/* Inline Function Topic */
inline long long int _inlineFu_Square(int number) {
	return number*number;
}
/***********************************/
void EndMessage(void) {
	std::cout<< "End of Program." << std::endl;
	return;
}
