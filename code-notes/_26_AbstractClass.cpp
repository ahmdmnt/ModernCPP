/*
 * _26_AbstractClass.cpp
 *
 *  Created on: May 13, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Abstract Class
 * -----------------
 * is a class that CAN NOT be instantiated on its own and is designed to be a base class for other classes.
 *  >> It contains at least one PURE VIRTUAL FUNCTION.
 *  >> But can also have other normal members.
 *  >> Can not be instantiated.
 *  >> But can have Pointers and References for Polymorphism.
 *
 *
 *  Interface Class
 * -----------------
 * Interface class is a class that is used to define a pure interface,
 * a contract that other classes must follow. It is essentially an abstract class
 * where all member functions are pure virtual and it typically has no data members.
 *
 *
 *  Pure Virtual Function:
 *  -----------------------
 *  A Virtual function that has no any definition and assigned to Pure Specifier.
 *  >> Doesn't have an implementation or [OPTIONAL].
 *     This Impl. is only a default implementation for drived classes ONLY, and not commonly used, usually it is left without implementation.
 *     - You must still override it in derived classes.
 *     - But you can define the function body in the base class (outside the class definition).
 *     - Derived classes can call the base implementation using Base::function().
 *  >> No Entry in V-Table only in Child classes.
 *  >> Must be overridden by child classes, if not the child class will be an ABSTRACT Class as well.
 *
 *  Benefits:
 *  Make sure that any derived class from abstract class, has implemented all needed methods, for it,
 *  before instantiation. so program can behave correctly and error will be avoided.
 */

class docu {
public:
	virtual void serialize(float version) = 0;
	virtual ~docu() = default;
};
void docu::serialize(float version) {
	std::cout << "   --THIS IS A PURE VIRTUAL FUNCTION--   " << std::endl;
	std::cout << "Derived Class Implementation is mandatory" << std::endl;
}

class txt : public docu {
public:
	void serialize(float version) {
		std::cout << "   >> Parsing Text Data ----------------   " << std::endl;
	}
};

class xml : public docu {
public:
	void serialize(float version) {
		std::cout << "   >> Parsing XML Data ----------------   " << std::endl;
	}
};

class arxml : public docu {
public:
	void serialize(float version) {
		docu::serialize(1.2);
	}
};

void _26_AbstractClass() {

//	docu myDoc;			// ERROR: cannot declare variable 'myDoc' to be of abstract type 'docu'

	txt myText;
	myText.serialize(1.2);

	xml myXML;
	myXML.serialize(1.2);

	arxml myARXML;
	myARXML.serialize(1.2);
}


