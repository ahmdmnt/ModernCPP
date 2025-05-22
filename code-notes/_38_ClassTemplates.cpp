/*
 * _38_ClassTemplates.cpp
 *
 *  Created on: May 19, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Class Templates:-
 * ---------------------
 * allows you to write a generic class that can work with any data type.
 * Instead of writing separate classes for int, float, std::string, etc.,
 * you can write one template that works for all of them.
 * 	- Code reuse: Write once, use with any type.
 * 	- Type safety: Compiler checks types at compile time.
 * 	-Flexibility: Works with user-defined types too.
 *
 *
 * TOPICS:
 * --------
 * 	1. Basics of Class Template.
 * 	2. with non-type template argument.
 * 	3. Define Member function outside the Class Declaration.
 * 	4. Factory Method of a Class.
 */

/* Use of Class Template, with non-type template argument: SIZE */
template<typename stackValueType__, int SIZE>
class stackType {
	stackValueType__ mBuffer[SIZE] {};
	int mStackTop {-1};
public:
	/* Default Constructor */
	stackType() = default;
	/* Copy Constructor */
	stackType(const stackType& lObj);// {				// Usage of Short hand rotation
//		std::cout << "stackType(const stackType& lObj) - Copy Constructor!" << std::endl;
//		this->mStackTop = lObj.mStackTop;
//		for(int itr{0}; itr<=mStackTop; ++itr) {
//			this->mBuffer[itr] = lObj.mBuffer[itr];
//		}
//	}
	/* Push Value inside Stack */
	void push(const stackValueType__& argValue) {
		mBuffer[++mStackTop] = argValue;
	}
	/* Pop Value from Stack */
	void pop() {
		--mStackTop;
	}
	/* Read Stack Top Vaule */
	const stackValueType__& top() const {
		return mBuffer[mStackTop];
	}
	/* Check if Stack is Empty */
	bool isEmpty();
	/* Factory Method of a Class */
	static stackType create();			// NOTE: Static only in declaration
	// Short notation "stackType without <>" only occurs instead templates, but outside u shall type the full notation
};

/* Define Member function outside the Class Declaration */
template<typename stackValueType__, int SIZE>
bool stackType<stackValueType__, SIZE>::isEmpty() {
	return (mStackTop==-1);
}
/* Factory Method of a Class:
 * Method that Create Instance of a Class. */
template<typename stackValueType__, int SIZE>
stackType<stackValueType__, SIZE> stackType<stackValueType__, SIZE>::create() {
	return stackType<stackValueType__, SIZE>{};
}
template<typename stackValueType__, int SIZE>
stackType<stackValueType__, SIZE>::stackType(const stackType<stackValueType__, SIZE>& lObj) {				// Usage of Short hand rotation
		std::cout << "stackType(const stackType& lObj) - Copy Constructor!" << std::endl;
		this->mStackTop = lObj.mStackTop;
		for(int itr{0}; itr<=mStackTop; ++itr) {
			this->mBuffer[itr] = lObj.mBuffer[itr];
		}
	}

void _38_ClassTemplates() {

	stackType<float, 10> intStack = stackType<float, 10>::create();			// method that return a created class instance. Note: Size must match.
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);

	stackType<float, 10> anotherIntStack = intStack;

	while( !anotherIntStack.isEmpty() ) {
		std::cout << anotherIntStack.top() << " ";
		anotherIntStack.pop();
	}
}
