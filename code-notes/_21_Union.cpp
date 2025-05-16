/*
 * _21_Union.cpp
 *
 *  Created on: May 9, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>

/* Unions:-
 * ----------
 * 	- Gives the ability to represents all the members in the same memory.
 * 	- Save more spaces, cause all members same memory.
 * 	- Size of UNION, is Size of Largest Member only!
 * 	- [Disadvantages]:
 * 		- No way to know which type it holds at a certain time "active member".
 * 		- Nested types with non-default constructors, deletes the default constructor/destructor of the union.
 * 		  HINT: before C++11, it was illegal for union to have member contains user-defined constructors.
 * 		  from [C++11] it is legal but u have to provide constructor and destructor of union.
 * 		- Can not assign user defined objects types directly in union, have to use placement new operator.
 * 		- User-defined types are not destroyed implicitly, have to be manually done.
 *		- It can't have a base class, you can't inherit from it.
 *		- Can not derive from a union.
 */

union tstUnion {				// 8bytes only, not 13bytes
	double decmailNumber;		// 8bytes
	int    integralNumber;		// 4bytes
	char   character;			// 1byte

	tstUnion() : decmailNumber{120} {				// ONLY INITIALIZE ONE MEMBER AT CONSTRUCTOR.
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~tstUnion() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

/* Advanced Union Example */
class cT_A {
public:
	cT_A() {std::cout << __PRETTY_FUNCTION__ << std::endl;}
   ~cT_A() {std::cout << __PRETTY_FUNCTION__ << std::endl;}
	cT_A(const cT_A& other) {std::cout << __PRETTY_FUNCTION__ << std::endl;}
	cT_A(cT_A&& other) noexcept {std::cout << __PRETTY_FUNCTION__ << std::endl;}
	cT_A& operator=(const cT_A& other) {std::cout << __PRETTY_FUNCTION__ << std::endl; return *this;}
	cT_A& operator=(cT_A&& other) {std::cout << __PRETTY_FUNCTION__ << std::endl; return *this;}
};
class cT_B {
public:
	cT_B() {std::cout << __PRETTY_FUNCTION__ << std::endl;}
   ~cT_B() {std::cout << __PRETTY_FUNCTION__ << std::endl;}
	cT_B(const cT_A& other) {std::cout << __PRETTY_FUNCTION__ << std::endl;}
	cT_B(cT_A&& other) noexcept {std::cout << __PRETTY_FUNCTION__ << std::endl;}
	cT_B& operator=(const cT_B& other) {std::cout << __PRETTY_FUNCTION__ << std::endl; return *this;}
	cT_B& operator=(cT_B&& other) {std::cout << __PRETTY_FUNCTION__ << std::endl; return *this;}
};

union advUnion {		// Memory already allocated by largest member, string Variable.
	std::string uName;
	cT_A objA;
	cT_B objB;

	// MUST ADD User-defined constructor/destructor for union, else
	// error: union member 'advUnion::objB' with non-trivial 'cT_B::cT_B()' -- 'advUnion::advUnion()' is implicitly deleted.
	advUnion() {std::cout << __PRETTY_FUNCTION__ << std::endl;}		// MANDATORY
   ~advUnion() {std::cout << __PRETTY_FUNCTION__ << std::endl;}		// MANDATORY
};

void _21_Union(void) {

	tstUnion unionVariable;				// ACTIVE member is number, because it is initialized in constructor.
	std::cout<< "decmailNumber = " << unionVariable.decmailNumber << std::endl;

	unionVariable.character = 'A';		// ACTIVE member is character now.
	std::cout<< "character = " << unionVariable.character << std::endl;

	// Size of unionVariable
	std::cout << "Size of unionVariable: " << sizeof(unionVariable) << " Bytes" << std::endl << std::endl << std::endl;

	/*****************************************************************************************************************/

	/* FIRST SIMPLE WAY:-
	 *********************/
	advUnion advUninionVariable;					// HERE: still no instance of cT_A / cT_B is created.

	advUninionVariable.uName = "Advanced Union";	// HERE: I can set value to string because instance is created.
	std::cout << "advUninionVariable.uName= " << advUninionVariable.uName << std::endl;

	/* to use cT_A and cT_B in Union */
	advUninionVariable.objA = cT_A{};				// HERE: cT_A instance is created.
	advUninionVariable.objB = cT_B{};				// HERE: cT_B instance is created, and cT_A is deleted.


	/* ANOTHER WAY:-
	 ****************
	 * using members inside the Union Variable:
	 * Use placement new operator, form of new operator that only initialize the memory but doesn't allocate. */

//	new (&advUninionVariable.uName) std::string{"Advanced Union"};
//	std::cout << "advUninionVariable.uName= " << advUninionVariable.uName << std::endl;
//
//	new (&advUninionVariable.objA) cT_A{};		// cT_A instance is created.
//	advUninionVariable.objA.~cT_A();			// DESTRUCTOR IS MANDATORY, to performed implicitly.
//
//	new (&advUninionVariable.objB) cT_B{};		// cT_B instance is created.
//	advUninionVariable.objB.~cT_B();			// DESTRUCTOR IS MANDATORY, to performed implicitly.

	/* ALTHOUGH:
	 * Unions are complex and have to many constraints and user-defined codes needed to be added,
	 * to safely use it, it is still useful and used in [C++17] in std::variant Data type. */
}
