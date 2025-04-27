/*
 * _08_Friend_SmartPointer.cpp
 *
 *  Created on: Apr 27, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Module Description:-
 * ---------------------
 * 	1.
 *
 */

class intObj1 {
	int *pInt;
public:
	/* Constructors and Destructor */
	intObj1() : pInt{new int {0}} {
		std::cout << "Default Constructor ()" << std::endl;
	};						// Default Constructor
	intObj1(int l_value) : pInt{new int {l_value}} {
		std::cout << "Parameterized Constructor ()" << std::endl;
	};		// Parameterized Constructor
	~intObj1() {												// Destructor
		std::cout << "Destructor ()" << std::endl;
		delete pInt;
	}
	intObj1(const intObj1 &refInt) {							// Copy Constructor
		this->pInt = new int {*refInt.pInt};
	}
	intObj1(intObj1 &&rRefInt) {								// Move Constructor
		this->pInt = rRefInt.pInt;
		rRefInt.pInt = nullptr;
	}
	/*********************************************************/
	/* Copy and Move Assignment Operators */
	/* (=) Copy/Equality Operator Overloading */
	intObj1 operator=(const intObj1 &otherObj) {
		if(this != &otherObj) {
			delete this->pInt;
			this->pInt = new int {*otherObj.pInt};
		}
		return *this;
	}
	/* (=) Move/Equality Operator Overloading */
	intObj1 operator=(intObj1 &&otherObj) {
		if(this != &otherObj) {
			delete this->pInt;
			this->pInt = otherObj.pInt;
			otherObj.pInt = nullptr;
		}
		return *this;
	}
	/*********************************************************/
	/* Normal Methods */
	int getValue() const {
		return *pInt;
	}
	void setValue(int l_value) {
		if(nullptr != pInt) {
			*pInt = l_value;
		}
	}
	/*********************************************************/
	/* Operator Overloading Methods */
	/* (+) Addition Operator Overloading */
	intObj1 operator+(const intObj1 &otherObj) const {	// this is a const method, NOT MODFIYING in Calling Object, using it only.
		std::cout << "operator+ invoked!" << std::endl;
		intObj1 result;
		*result.pInt = *this->pInt + *otherObj.pInt;
		return result;
	}

	/* Friend Keyword:-
	 * ----------------
	 * If I need in some specific scenarios to access PRIVATE member of a Class.
	 * This is the situation where i need to use friend keyword.
	 * NOT COMMONLY USED: because it can cause bugs and issues. */
	friend std::istream& operator>>(std::istream &in, intObj1 &Obj);
	friend class printer;
	/*********************************************************/
};
class printer {		// FRIEND CLASS TO intObj1
public:
	void exe(const intObj1 &obj) {
		std::cout<< "Printer Value = " << *obj.pInt << std::endl << std::endl;	// OK, because it is friend function to class.
	}
};


/* Function That Create intObject in Heap */
void createIntObject() {
	intObj1 *pIntObj {new intObj1};
	pIntObj->setValue(320);
	std::cout<< "pIntObj= " << pIntObj->getValue() << std::endl << std::endl;
}

/* Operator Overloading Global Function:-  */
/* (<<) Output stream Operator Overloading */
std::ostream& operator<<(std::ostream &out, const intObj1 &Obj) {
	//	out << "Object Int Value = " << *Obj.pInt;		// IMPOSSIBLE, Accessing Private member.
	out << "Object Int Value = " << Obj.getValue() << std::endl << std::endl;
	return out;
}
/* (>>) Input stream Operator Overloading */
std::istream& operator>>(std::istream &in, intObj1 &Obj) {	// FRIEND FUNCTION TO intObj1
	int l_value {};
	in >> l_value;
	//	Obj.setValue(l_value);
	*Obj.pInt = l_value;								// OK, because it is friend function to class.
	return in;
}
/*********************************************************/

void _08_Friend_SmartPointer(void) {
	intObj1 myNum;
	std::cout << "Enter Object Value: "; std::cin >> myNum;
	std::cout << myNum;

	printer myPrinter;
	myPrinter.exe(myNum);

	createIntObject();
}

