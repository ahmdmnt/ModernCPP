/*
 * _04_OOP_LValueRValue.cpp
 *
 *  Created on: Apr 16, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>

int& transform(int& num);
int& setValue();
int addByVal(int n1, int n2);

void printName(const std::string &name);
void printName(const std::string &&name);

/* Module Description:-
 * ---------------------
 * 	1. L-Value and R-Value.
 * 	2. L-Value Reference and R-Value Reference.
 *	3. Function Overloading with Fu-Args: LVR and RVR.
 */

void _04_OOP_LValueRValue() {

	/* L-Value and R-Values:-
	 * -----------------------
	 *		 L-Value							vs			R-Value
	 *		- Left side of "=" mark.					- Right side of "=" mark.
	 * [1]	- Has a name.								- Doesn't have a name.
	 * [2]	- All Variables are L-values.				- R-Values are Temporary values.
	 * [3]	- Can be assigned by other values.			- Can NOT be assigned by other values.
	 * [4]	- Some Expression returns L-values.			- Some Expression returns R-values.
	 * [5]	- L-value persists beyond the expression.	- L-value DOESN'T persists beyond the expression.
	 * [6]  - L-value is function return by Reference.	- R-value is function return by Value.
	 * [7]  - L-value Reference.						- R-value Reference.
	 */
	// Example [1][2][3]
	/*L-Value*/int num1   {5}   /*R-Value*/;
	/*L-Value*/int num2  {10}   /*R-Value*/;

	// Example [4][5]
	int result {(num1+num2) * 5}; /* R-Value Expression - doesn't persists after this line */
	 ++num2 = 6;				  /* L-value Expression and persists after this line */
	std::cout << "result= " << result << std::endl;
	/***************************************************************************************************************************************/


	/* L-Value Reference:-
	 * --------------------
	 * is a reference that must refer to a named object or a memory location that persists,
	 * something you can take the address of.
	 * 	- They are aliases — changing one changes the other.
	 * 	- A second name (nickname) for an existing variable — not a copy.
	 * [SYNTAX]:
	 * 		variableType & variableName = anotherVariableName;
	 *
	 * Why use l-value references?
	 * ----------------------------
	 * 	1. Alias to something mutable:
	 * 		is a second name (nickname) for an existing variable
	 * 	2. Function arguments (pass-by-reference):
	 * 		Avoid copying large objects or allow modification of arguments.
	 * 	3. Function return values by reference (advanced):
	 * 		Return a reference to allow further use or modification after returning.
	 *
	 * Rules to remember:
	 * ------------------
	 * 	- You cannot bind an l-value reference to a temporary (like 5 or a + b).
	 * 	- [EXCEPT IF] l-value reference is qualified with constant: (const int& ref = 5;). ""lifetime extension!""
	 * 		> C++ create a hidden temporary to hold 5, and make ref refer to it, and make sure it sticks around for as long as REF lives.
	 * 			Behind the scene, it is something like that.
	 * 			const int& ref = 5;		→	int __temp = 5;
	 * 										const int& ref = __temp;
	 * 		> It is very useful to pass temp value for a function with ref-arguments
	 * 		"best practice: clean, efficient code without unnecessary copies".
	 * 			double square(const double& x)  // Accept Both L-Value and R-Value.
	 * 			square(variable);				//OK
	 * 			square(10);						//OK
	 * 	- For temporaries, you need an R-Value Reference: (int&& r = 5;).
	 */
	// Example [6]
	result = addByVal(3, 5);			// R-value is function return by Value.
	int myNum = 5;
	int& myResult = transform(myNum);	// LVR; Reference to L-Value "myResult is reference to nyNum"
	std::cout << "myNum= " << myNum << "  -  myResult = " << myResult << std::endl;

	/* Another Example for Transform */
	int myNum2 = 4;
	// 1. myNum2 = 4 →  2. transform(): x=16  →  3. Then transform() = 100; assigns 100 to the ret_val (which is a ref to x); x = 100
	transform(myNum2) = 100;			// L-value is function return by Reference. "transform() is reference to nyNum2
	std::cout << "myNum2= " << myNum2 << std::endl;

	setValue() = 150;					// L-value is function return by Reference. setValue() is reference to local_num
	std::cout << "setValue()= " << setValue() << std::endl;
	/***************************************************************************************************************************************/


	/* R-Value Reference [C++11]:-
	 * ----------------------------
	 * An r-value reference is a special kind of reference that can bind to r-values (temporaries — things like 5, a+b, std::string("hello")).
	 * If we know that we are taking temp. object, so we don't have to making sure to keep it alive or copy it,
	 * we can only steal the resources for that temp object and use it in some where else. and then it is removed.
	 * 	- Reference to Temporary Values ONLY, can't bind to L-value.
	 * 	- Very useful for code and resource optimization.
	 * 	- Created with && Operator.
	 *
	 * THIS IS VERY USEFUL [VERYYYY IMPORTANT]:-
	 * 	1. Can be used to detect temporaries passed to objects.
	 * 	2. So u can use Move Semantics --> Which is a FATSER WAY to create object with taking temp resources without any unwanted copies.
	 *
	 * l-value reference (&):-			vs				r-value reference (&&):-
	 * ------------------------							--------------------------
	 * 	- Binds to named, persistent objects.			 - Binds to temporaries, unnamed objects.
	 * 	- Can't bind to r-values, if const not used.	 - Can't bind to l-values (without std::move).
	 * 	- Used for passing/mutating existing variables.	 - Used for taking over/moving resources.
	 */
	int &&num1RREF {12};				// RVR; Reference to Temporary Value
	int &&num2RREF {addByVal(1, 5)};	// RVR; Reference to Temporary Value
	// This not an Actual Variable it is only, reference to a Temporary Value.
	/***************************************************************************************************************************************/


	// TO SUMMARIZE ALL ABOVE TOPICS:-
	std::string firstName {"Ahmed"};				// L-Value {R-Value}
	std::string lastName {"Montasser"};				// L-Value {R-Value}

	std::string fullName {firstName+lastName};		// L-Value {R-Value}	 // @suppress("Invalid arguments")
	//Although firstName, lastName are l-value, but this addition is only temp. to set fullName, thats why it is R-Value.

	std::string &nameRef {fullName};				// L-Value Reference

	printName(fullName);							// Accept L-Value
	printName(nameRef);								// Accept L-Value Reference
	printName(firstName+lastName);					// When LVR: Accept R-Value; because of use of const keyword.
													// When RVR: This normal case to accept R-value reference.
	// BUT,, Although Temp value can be called with const LVR, in function overloading,
	// The Compiler will prefer to use RVR instead, only if there is no RVR, then it will use the const LVR.
	// So here instead of creating temp object to store fullName .. i can send temp value (first+last) use it at call then it vanishes.
	/***************************************************************************************************************************************/
}


/* Return L-value (By Reference):-
 * --------------------------------
 * Why return by reference?
 * --------------------------
 * Returning by reference means the caller can continue to modify the original variable through the returned reference.
 * This is useful if you want to:
 * 	1. Avoid copying large objects.
 * 	2. Allow chaining or further modifications.
 * 	3. Reflect changes back to the original argument.
 * Be careful:
 * ------------
 * 		Returning a reference to a local variable (not the case here) is undefined behavior,
 * 		but returning a reference to a parameter (like you're doing) is safe, as long as it's valid outside the function.*/
int& transform(int& num) {
	 num *= num;
	 return num;
}
int& setValue() {
	 static int local_num {0};
	 return local_num;
}

/* Return R-value (By Value) */
int addByVal(int n1, int n2) {
	return n1+n2;
}

/* L-value Reference and L-value Reference Function Overloading:-
 * --------------------------------------------------------------- */
void printName(const std::string &name) {					// fu Argument: L-Value Reference
	std::cout << name << "  -- LVR" << std::endl;
}

void printName(const std::string &&name) {					// fu Argument: R-Value Reference
	std::cout << name << "  -- RVR" << std::endl;
}
