/*
 * _49_FunctionWrapper_stdbind.cpp
 *
 *  Created on: May 23, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>
#include <functional>

/* std::bind:-
 * -------------
 * Added in C++11 Very similar as std::function(),
 *  - Wrapper that can bind some arguments to a given function.
 *  - Arguments to the target function are represented using:
 *  	- Place holders "std::placeholders namespace"
 *  	- Directly bound to specific values.
 *  - #include <functional>
 *  - std::bind by default preserve the value category of orignial function.
 *  	r-value will be r-value and l-value will be l-value
 *
 */
void replaceWithLambdaExpression();
void replaceWithLambdaExpression_PreserveValueCategory();


int subFu(int n1, int n2) {
	return n1-n2;
}

class greaterThanClass {
public:
	bool operator()(int n1, int n2) const {
		return n1>n2;
	}
};
/***********************************************************************/
int operationFu(int n1, int n2, std::function<int(int, int)> cbkFu) {
	return cbkFu(n1, n2);
}
int accumulate(int n1, int n2, int n3) {
	return n1+n2+n3;
}
/***********************************************************************/

void _49_FunctionWrapper_stdbind() {
	std::cout<< std::boolalpha;


	/* std::bind --------------------------------------
	 * - can bind a function to a std::function object */
	std::function<int(int,int)> stdFuSub = std::bind(subFu, std::placeholders::_2, std::placeholders::_1);	// I CAN CHANGE ORDER OF ARGS
	std::cout << "stdFuSub= " << stdFuSub(10, 20) << std::endl;


	/* Using Simpler Format */
	using namespace std::placeholders;
	auto stdFuSub_Simple = std::bind(subFu, _1, _2);	// I CAN CHANGE ORDER OF ARGS
	std::cout << "stdFuSub_Simple= " << stdFuSub_Simple(10, 20) << std::endl;


	/* std::bind --------------------------------------
	 * - can bind a function to a std::function object with SPECIFIC ARGS */
	auto stdFuSub_fixedArg = std::bind(subFu, 100, 5);						// Either to fix ALL Args or PARTIAL Args.
	std::cout << "stdFuSub_fixedArg= " << stdFuSub_fixedArg() << std::endl;			// Callable with fixed arguments .. here i send no ARGs.


	/* std::bind --------------------------------------
	 * - can bind a functor to a std::function object w/ or wo/ SPECIFIC ARGS */
	auto stdFuGreaterThan100 = std::bind(greaterThanClass{}, _1, 100);
	std::cout << "stdFuGreaterThan100= " << stdFuGreaterThan100(5) << std::endl;


	/* std::bind -------------------------------------- [[[MAIN USAGE]]]
	 * - can bind a function to a std::function function argument with DIFFERENT number of arguments */
	//std::cout << operationFu(10, 50, accumulate);							// error: could not convert 'accumulate' from 'int (*)(int, int, int)' to 'std::function<int(int, int)>'
	auto stdFuAccumulate_2Args = std::bind(accumulate, _1, _2, 0);			// Bind it to std::function and fix an argument to discard it. as if it accepts only 2 args.
	std::cout << "operationFu= " << operationFu(10, 50, stdFuAccumulate_2Args) << std::endl;	// After binding accumulate function to std::function with 2 args only, it can work!


	/* Althought std::bind is very useful,
	 * but we can replace all the std::bind with [[Lambda Expression]]
	 ****************************************************************/
	replaceWithLambdaExpression();			///////// REPLACE ALL THE STD::BIND USAGE WITH LAMBDA EXPRESSION <<<
	replaceWithLambdaExpression_PreserveValueCategory();
}

void replaceWithLambdaExpression() {
	/**
	 * Lambda Expression: has the ability to Bind Function
	 * ----------------------------------------------------
	 * MUCH EASIER IMPLEMENTATION AND COMMONLY USED >>>>
	 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

	std::cout << "----------------------------------" << std::endl;

  //auto stdFuSub = std::bind(subFu, _2, _1);
	auto stdFuSub = [](int n1, int n2) {
		return subFu(n2, n1);						// I CAN CHANGE ORDER OF ARGS ALSO.
	};
 	std::cout << "stdFuSub= " << stdFuSub(10, 20) << std::endl;


  //auto stdFuSub_fixedArg = std::bind(subFu, 100, 5);
 	auto stdFuSub_fixedArg = []() {
 		return subFu(100, 5);
 	};
	std::cout << "stdFuSub_fixedArg= " << stdFuSub_fixedArg() << std::endl;


   //auto stdFuGreaterThan100 = std::bind(greaterThanClass{}, _1, 100);
	auto stdFuGreaterThan100 = [](int number) {
		//greaterThanClass greaterThanObject{};
		return greaterThanClass{}(number, 100);		// WOW!!!!!!!!!! Create a Temp Object and Call it.
	};
	std::cout << "stdFuGreaterThan100= " << stdFuGreaterThan100(5) << std::endl;


   //auto stdFuAccumulate_2Args = std::bind(accumulate, _1, _2, 0);
	auto stdFuAccumulate_2Args = [](int n1, int n2) {
		return accumulate(n1, n2, 0);
	};
	std::cout << "operationFu= " << operationFu(10, 50, stdFuAccumulate_2Args) << std::endl;
}

void replaceWithLambdaExpression_PreserveValueCategory() {
	/**
	 * Lambda Expression: has the ability to Bind Function
	 * ----------------------------------------------------
	 * Implmentation to preserve orignal function value category.
	 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

	std::cout << "----------------------------------" << std::endl;

	auto stdFuSub = [](auto&& n1, auto&& n2) {												// Use Forward Reference
		return subFu( std::forward<decltype(n2)>(n2) , std::forward<decltype(n2)>(n1));		// Fetch type by decltype
	};
 	std::cout << "stdFuSub= " << stdFuSub(10, 20) << std::endl;


	auto stdFuGreaterThan100 = [](auto&& number) {
		return greaterThanClass{}( std::forward<decltype(number)>(number), 100);
	};
	std::cout << "stdFuGreaterThan100= " << stdFuGreaterThan100(5) << std::endl;

	/**
	 * [[[C++20 SYNTAX]]] ... Simpler then above using lambda template
	 */
	auto stdFuAccumulate_2Args = []<typename vType__>(vType__&& n1, vType__&& n2) {
		return accumulate(std::forward<vType__>(n1), std::forward<vType__>(n2), 0);
	};
	std::cout << "operationFu= " << operationFu(10, 50, stdFuAccumulate_2Args) << std::endl;
}

