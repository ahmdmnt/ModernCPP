/*
 * _48_FunctionWrapper_stdfunction.cpp
 *
 *  Created on: May 23, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <functional>

/* std::function
 * ---------------
 * - General Purpose Function Wrapper.
 * - can store, invoke and target that can be invoked with operator() syntax,
 * 	 e.g. FunctionPointer & FunctionObject.
 * - Stored object is called the target.
 * - This target can be invoked with the same syntax through std::function object.
 * - Invocation without a target throws std::bad_function_call exception.
 * - include <functional>
 *
 * [SYNTAX]:
 * 	std::function<FUNCTION_SIGNATURE> object = {CALLABLE};
 *		<FUNCTION_SIGNATURE>:  RET_TYPE(ARGS_TYPES)
 *
 * [EXAMPLE]:
 *
 */

// >>> FUNCTION
int sqFunction(int num) {
	return num*num;
}
// >>> FUNCTION OBJECT
struct maxClass {
	int operator()(int num1, int num2) const {
		return num1>num2 ? num1:num2;
	}
};

// >> FUNCTIONS
int addFunction(int num1, int num2) {
	return num1+num2;
}
class subClass {
public:
	int operator()(int num1, int num2) {
		return num1-num2;
	}
};
int operation(int n1, int n2, std::function<int(int, int)> callbackFu) {
	return callbackFu(n1, n2);
}

void _48_FunctionWrapper_stdfunction() {

	try {

		/* Example 01 - Function */
		//		std::function<int(int)> sqFu;
		std::function<int(int)> sqFu = sqFunction;

		if(sqFu) {   // If std::function() has function
			std::cout << "sqFu(8)= " << sqFu(8) << std::endl;		// IMPLEMENTATION
		}
		else {		// If std::function() empty
			std::cout << "ERROR: NO TARGET INVOKED." << std::endl;
		}
		/*****************************************************************************/


		/* Example 02 - Function Object */
		maxClass maxInstance {};
		std::function<int(int,int)> maxFuObj = maxInstance;

		if(maxFuObj) {
			std::cout << "maxFuObj(8, 1000)= " << maxFuObj(8, 1000) << std::endl;
		}
		else {
			std::cout << "ERROR: NO TARGET INVOKED." << std::endl;
		}
		/*****************************************************************************/


		/* Example 03 - Lambda Expression */
		int modulus {2};

		std::function<bool(int)> moduloFu = [&modulus](int number) -> bool {
			return (number%modulus==0);
		};
		std::cout << std::boolalpha << "isEven? " << moduloFu(28) << std::endl;

		/*****************************************************************************/

		/* Example 04 - std::function can be used as generic argument for a function, instead of using template
		 * and it can be used as functionPointer, functionObject and lambdaExpression */
		std::cout << "Result = " << operation(10, 20, addFunction) << std::endl;							// Result = 30
		subClass subFuObj;
		std::cout << "Result = " << operation(200, 10, subFuObj) << std::endl;								// Result = 190
		std::cout << "Result = " << operation(3, 20, [](int n1, int n2) {return n1*n2;}) << std::endl;		// Result = 60
	}
	catch(const std::exception& ex) {
		// sqFu(8)= Exception: bad_function_call "If Function not init"
		std::cout << "Exception: " << ex.what() << std::endl;
	}
}

/* 🔹 1. Function Pointers:
 * ------------------------
 *   Use when:
 *     - You need simple, lightweight, and non-capturing callbacks.
 *     - Performance is critical and you want zero overhead.
 *   Pros:
 *     - Very fast and minimal memory usage.
 *     - Easy to use for static or free functions.
 *   Cons:
 *     - Cannot capture state (no closures).
 *     - Not type-safe for overloaded or template functions.
 *
 *
 * 🔹 2. Function Objects (Functors):
 * ----------------------------------
 *   Use when:
 *     - You need to encapsulate state or behavior.
 *     - You want to define reusable, customizable logic.
 *   Pros:
 *     - Can hold state.
 *     - Can be inlined and optimized by the compiler.
 *     - No dynamic memory allocation.
 *   Cons:
 *     - Slightly more verbose.
 *     - Less flexible than std::function for generic code.
 *
 *
 * 🔹 3. std::function
 * -------------------
 *   Use when:
 *     - You need maximum flexibility (can store lambdas, function pointers, functors, etc.).
 *     - You want to pass callbacks around generically.
 *   Pros:
 *     - Very flexible and type-safe.
 *     - Can store anything callable with a matching signature.
 *     - Great for APIs and generic programming.
 *   Cons:
 *     - Slightly slower due to type erasure and possible heap allocation.
 *     - Larger memory footprint.
 *
  * 🔹 4. Lambda Expression
 * ------------------------
 *   Use when:
 *     - You need a quick, inline callback.
 *     - You want to capture local variables from the surrounding scope.
 *     - You're working with STL algorithms or event-driven code.
 *   Pros:
 *     - Concise and readable syntax for short functions.
 *     - Captures state from the surrounding context.
 *     - Efficient and often inlined by the compiler.
 *   Cons:
 *     - Anonymous: harder to reuse or reference.
 *     - Complex captures can reduce readability.
 *     - Limited debugging clarity due to unnamed types.
 *
 *
 * 🧠 Recommendation:
 * -------------------
 * - Use function pointers for simple, fast, stateless callbacks.
 * - Use functors when you need state and performance.
 * - Use std::function when you need flexibility, especially in modern C++ APIs or generic code.
 * - Lambda: Use for concise, inline callbacks—especially with std::function.
 *
 *
 * Callable Type		Template-Friendly		Notes
 * --------------		-----------------		--------------------------------------------------------------------------------
 * Function Pointer		✅ Yes					Works well with templates, but limited to stateless functions.
 * --------------		-----------------		--------------------------------------------------------------------------------
 * Functor				✅ Yes					Ideal for templates; compiler can inline and optimize.
 * --------------		-----------------		--------------------------------------------------------------------------------
 * Lambda Expression	✅ Yes					Fully supported; type is deduced with auto or passed to templates.
 * --------------		-----------------		--------------------------------------------------------------------------------
 * std::function		⚠️ Partially				Usable in templates, but incurs type erasure and runtime overhead.
 * 												Requires specifying the exact signature (e.g., std::function<int(int, int)>).
 * --------------		-----------------		--------------------------------------------------------------------------------
 */
