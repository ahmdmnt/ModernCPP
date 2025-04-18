/*
 * _03.2_CLASS_HeapInteger.cpp
 *
 *  Created on: Apr 15, 2025
 *      Author: AhmedMontasser
 */

#include "_03.2_CLASS_HeapInteger.hpp"

#include <iostream>

/* RULE OF 3:-
 * ------------
 * ALL SHOULD BE DEFINED IF: User implemented any of below
 * 	1. Destructor.
 * 	2. Copy Constructor.
 * 	3. Copy Assignment Operator.
 * WHY??
 * 	This will be due to allocation of some resources in a constructor.
 * 	- Destructor will be used to free/release these resources.
 * 	- Copy Constructor will perform DEEP Copy.
 * 	-  Copy Assignment Operator will perform DEEP Copy.
 * IF NOT
 */

/* Delegating Constructor:-
 * ---------------------------
 * 	- Allow a constructor to invoke another Constructor.
 * 	- Replacement for Common initialization parts, to reduce code duplication in multiple constructors.
 *
 *	Execution Criteria:
 *		- It will keep delegating until it reach the Primary Constructor,
 *		then it will implement it and keep implementing back the delegating constructor afterwards in opposite order.
 *
 * 	Example:
 * 	In below Class, the Default Constructor is delegating to Parameterized Constructor.
 * 	So, it it is called, it will automatically call the Parameterized with default value=0.
 * 		> by this way ... I only add code in one common constructor, instead of Duplication.
 */

HeapInteger::HeapInteger() : HeapInteger(0) {		// Delegating to Parameterized
	std::cout << "HeapInteger () - Default Constructor is invoked!" << std::endl;
	/* Skip the Implementation here, and delegate to Parameterized Constructor */
	std::cout << "Delegating to Parameterized Constructor ... " << std::endl;
}

/* Member Initialization List [FEATURE in Constructors]:-
 * -------------------------------------------------------
 * Allows you to initialize class members directly as part of the constructor's definition, before the body of the constructor is executed.
 * - [[MANDATORY]] For Certain Members:
 * 		- Constant members:
 * 	  	  Must be initialized as part of the member initialization list (Init in time of construction).
 * 		- Reference members:
 * 	 	  Must also be initialized this way because they cannot be re-assigned (Init in time of construction).
 * - Advantage:
 * 		- Provides better performance by initializing members directly instead of default initialization followed by assignment.
 *
 * [SYNATX]: A member initialization list is written after the constructor's parameter list and uses a colon (:),
 * followed by the member names and their initial values in parentheses or braces
 * 		> CLASSNAME::CONSTRUCOT (int VALUE): CLASS_VARIABLE(VALUE)) { }
 */
HeapInteger::HeapInteger(int value): pInt(new int(value)) {		// Member Initialization List
	std::cout << "HeapInteger() - Parameterized Constructor is invoked!" << std::endl;
//	pInt = new int(value);										// Normal Assignation is commented
}

/* Copy Constructor:-
 * --------------------
 * 	- A constructor that creates a new object as a copy of an existing object.
 * 	- Used in object cloning or when an object is passed by value.
 * 	- If user didn't implement copy constructor, compiler will generate one automatically.
 * 		> Compiler simply copy value from other object. which is not correct in some cases, for e.g. Pointer Members.
 *
 * 	- Copy Constructor USAGE EXAMPLE:
 * 		1. Create/Assign new Object with existing object
 * 		2. When Fu pass the Object by Value; will create new copy of Object.
 * 		3. When Fu return of Object by value.
 *
 * Copy Concepts:-
 * -----------------
 * 	- Shallow Copy:
 * 	---------------
 * 		ptr2 = ptr1;
 * 		If i have two Pointer variables, shallow copy means to copy address of other pointer to desired pointer.
 * 		--> Both Pointer will have same value, Because they are both pointing to same Memory Location.
 * 	- Deep Copy:
 * 	------------
 * 		ptr2 = new int(*ptr1);
 * 		If i have two Pointer variables, deep copy means to create new address to desired pointer and copy value in ptr1 in new ptr2.
 * 		--> Both Pointer will have same value, BUT both have two different Memory Locations.
 *
 * 	When COMPILER auto-generates Copy Constructor Shallow Copy will occurs, Which is not DESIRED.
 * 		>> Thats why user-defined COPY Constructor is needed.
 */
HeapInteger::HeapInteger(const HeapInteger &refObj) {
	// [MANDATORY]: To Pass by Reference, otherwise this will have endless loop of copying constructors.
	std::cout << "HeapInteger() - Copy Constructor is invoked!" << std::endl;
  /*pInt = new int;			// New Resource Allocation -- we don't have problem with this because destructor will release these allocations.
   *pInt = *refObj.pInt;	// Copy Value from Passed Object in new Allocation */
	pInt = new int(*refObj.pInt);
}
/***********************************************************************************************************************************/

HeapInteger::~HeapInteger() {
	std::cout << "~HeapInteger() - Destructor  is invoked!" << std::endl;
	/* [MANDATORY]: Because in user-defined Member/Constructors, Resources are allocation,
	 * Destructor implementation is needed to deallocate these resources. */
	delete pInt;		/* [MANDATORY]: to avoid Memory Leak. */
	pInt = nullptr;		/* [OPTIONAL]:  to avoid dangling pointer */
	/* Setting a [[pInt = nullptr]] at that point isn't strictly necessary,
	 * as the pointer will cease to exist along with the object. This makes setting it to nullptr redundant in most cases, Except:
	 * 	- Complex Destructor:
	 * 		If your destructor contains complex logic or calls other functions that might accidentally
	 * 		reference the deleted pointer, setting it to nullptr can guard against such issues.
	 * 	- Debugging:
	 * 		During debugging, setting the pointer to nullptr can make it easier to identify that the memory has been deallocated. */
}

/* Copy Assignment Operator:-
 * ---------------------------
 * User-defined Implementation invoked when, HeapIntegerVariable = HeapIntegerAnotherVariable (to avoid Shallow Copy).
 *
 * Key Points in the Implementation:
 * ----------------------------------
 * 	1. Self-assignment Check.
 * 	2. Resource Cleanup.
 * 	3. Perform Deep Copy.
 */
HeapInteger& HeapInteger::operator=(const HeapInteger& refObj) {
	std::cout << "HeapInteger::operator=() - Copy Assignment Operator Invoked!" << std::endl;
    if (this != &refObj) {		/* Handle self-assignment */
    	delete this->pInt;					// Clean up existing resources, if available. (Avoid Memory Leak).
    	this->pInt = nullptr;				// In this case: Redundant, not required (Avoid dangling pointer).
    	this->pInt = new int(*refObj.pInt);	// Perform a Deep Copy.
    }
    return *this;
}
/***********************************************************************************************************************************/

int HeapInteger::getValue() const {
	return *pInt;
}

void HeapInteger::setValue(int value) {
	*pInt = value;
}

