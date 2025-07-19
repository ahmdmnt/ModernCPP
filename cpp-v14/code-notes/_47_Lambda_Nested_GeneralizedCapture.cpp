/*
 * _47_Lambda_Nested_GeneralizedCapture.cpp
 *
 *  Created on: May 22, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>

/* Module Description:-
 * ---------------------
 * 	- NESTED LAMBDA EXPRESSION.
 *	- Use of Lambda Expression as Callback.
 *	- Lambda Expression composition as FunctionPointer.
 *	Lambda will be decomposed as functionPointer because it has empty capture list.
 *
 *	NOTE::::
 *	:::::::: IMPORTANT
 *  So, when you use a lambda inside an expression that requires a function pointer, the type conversion
 *  operator of the lambda expression automatically converts the lambda into a function pointer.
 *  So, this is how it works.
 *  >>> expression should not have any capture list.
 *  >>> If it has a capture list, then the type conversion operator is not provided.
 *
 *	- [C++14]: Generalized Capture:
 *		1. Feature allow creation of new variables in capture clause.
 *		2. The type is deduced from the type produced by the expression.
 *		3. these variables must always be initialized.
 *		4. the new variable can have different or similar name.
 *		5. to create a reference, you have to use & before variable name.
 *		SYNTAX EMAPLES:
 *			[newVariable = existingVariale]() {...}
 *			[newVariable = expression]() {...}
 *			[&newVariable = existingVariale]() {...}
 */





void _47_Lambda_Nested_GeneralizedCapture() {

	/* atexit:
	 * Function call that execute automatically before function exit. it takes a callback function with NO ARGs */
	atexit([]() {		// Lambda will be decomposed as functionPointer because it has empty capture list.
		std::cout<< std::endl << std::endl << "Program is Exiting! Goodbye..." << std::endl;
	});


	/* NESTED Lambda Expression */
	[](int number) {
		number*=2;
		[](int num) {
			num *=2;
			[num]() {
				std::cout<< "NESTED LAMBDA EXPRESSION: Number = " << num << std::endl;
			}();
		}(number);
	}(100);


	/* [C++14]: Generalized Capture: */
	int number {10};
	auto fn = [&l_num=number](int arg) {				// [&newVariable = existingVariale]() {...}
		return l_num*arg;
	};
	std::cout << fn(5) << std::endl;


	std::unique_ptr<int> uPtr {std::make_unique<int>(number)};
	auto pointerfn = [l_ptr=std::move(uPtr)]() {		// [newVariable = existingVariale]() {...}
		return *l_ptr;		// The uPtr will be moved,, because it is desired to be used here only, and not used else where.
	};
	std::cout << pointerfn() << std::endl;


	auto expfn = [lvalue=new int(5)]() {				// [newVariable = expression]() {...}
		auto value = *lvalue;
		delete lvalue;
		return value;
	};
	std::cout << expfn() << std::endl;
}
