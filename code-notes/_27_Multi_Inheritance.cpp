/*
 * _27_Multi_Inheritance.cpp
 *
 *  Created on: May 13, 2025
 *      Author: AhmedMontasser
 */

// NOT COMPLETED SESSION

#include <iostream>

/* Multiple Inheritance:-
 * ---------------------
 * 	- C++ allows inheritance from more than one class at simultaneously.
 * 	- Allows a Class, to reuse/override behavior of multiple parent classes.
 * 	- Multiple Inheritance can led to Diamond Inheritance.
 * 	  In diamond inheritance, the classes from which,
 * 	  the child class inherits from which themselves
 * 	  inherit from a common base class and when
 * 	  such inheritance hierarchies represented
 * 	  through a diagram, it forms the shape of a diamond.
 *
 * 	  DIAMAND PROBLEM:
 * 	  The ambiguity arises because the derived class has multiple paths
 * 	  to access members or methods inherited from the common ancestor,
 * 	  leading to confusion during method resolution and member access.
 *
 * 	  TO SOLVE:
 * 	  USE: Virtual Inheritance:
 * 	  -------------------------
 * 	  used to solve the "diamond problem" in multiple inheritance.It ensures that,
 * 	  only one instance of a base class is shared among all derived classes,
 * 	  even if it's inherited multiple times through different paths.
 * 	  	- Use virtual when inheriting from a common base class in multiple inheritance.
 * 	  	- The base class is constructed only once, even if inherited multiple times.
 * 	  	- The most derived class;; is responsible for constructing the virtual base class. (LINE #86)
 *
 */


class stream {
	std::string mStream;
public:
	stream(const std::string& l_stream) : mStream(l_stream) {
		std::cout << "stream()" << std::endl;
	}

	const std::string& getStream() const {
		std::cout<< "  >> Stream: " << mStream << std::endl;
		return mStream;
	}

	~stream() {
		std::cout << "~stream()" << std::endl;
	}
};

class ostream : virtual public stream {			// Virtual Inheritance
public:
	ostream(const std::string& l_stream) : stream(l_stream) {
		std::cout << "ostream()" << std::endl;
	}
	void osFunction() {
		std::cout << "  >> osFunction()" << std::endl;
	}
	~ostream() {
		std::cout << "~ostream()" << std::endl;
	}
};

class istream : virtual public stream {			// Virtual Inheritance
public:
	istream(const std::string& l_stream) : stream(l_stream) {
		std::cout << "istream()" << std::endl;
	}
	void isFunction() {
		std::cout << "  >> isFunction()" << std::endl;
	}
	~istream() {
		std::cout << "~istream()" << std::endl;
	}
};

/**************************************************/
class iostream : public istream, public ostream {
public:
	iostream(const std::string& l_stream) : stream(l_stream), istream(l_stream), ostream(l_stream) {
		std::cout << "iostream()" << std::endl;
	}
	void iosFunction() {
		std::cout << "  >> iosFunction()" << std::endl;
	}
	~iostream() {
		std::cout << "~iostream()" << std::endl;
	}
};


void _27_Multi_Inheritance(void) {

	iostream myIOStream("Ahmed");

	myIOStream.isFunction();
	myIOStream.osFunction();
	myIOStream.iosFunction();

//	myIOStream.getStream();			// ERROR: request for member 'getStream' is ambiguous
	// BECAUSE THERE ARE TWO INSTANCE FROM STREAM OBJECT, and TWO WAYS TO REACH IT, BECAUSE IT IS INHERITED TWICE.

	// After Using Virtual Inheritance, we can normally use Base Class Method.
	myIOStream.getStream();
}

