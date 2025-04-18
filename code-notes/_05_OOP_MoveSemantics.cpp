/*
 * _05_OOP_MoveSemantics.cpp
 *
 *  Created on: Apr 18, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>

/* Module Description:-
 * ---------------------
 * 	1. Copy Semantics.
 * 	2. Move Semantics.
 */

class intData {
	int* pInt;
public:
	intData(){
		std::cout << "intData() - Default Constructor Invoked" << std::endl;
		pInt = new int(0);
	}
	intData(int value) {
		std::cout << "intData() - Parameterized Constructor Invoked" << std::endl;
		pInt = new int(value);
	}

	int getValue(void) const {
		std::cout<< "intData= " << *pInt << std::endl;
		return *pInt;
	}

	void setValue(int value) {
		*pInt = value;
	}

	~intData() {
		std::cout << "~intData() - Destructor Invoked" << std::endl;
		delete pInt;
	}
};

intData addIntData(const intData &n1, const intData &n2) {
	intData tempData;
	tempData.setValue(n1.getValue()+n2.getValue());
	return tempData;
}

void _05_OOP_MoveSemantics(void) {

	/* Copy Semantics [= duplicate]:-
	 * --------------------------------
	 * 	- Resources can be handled (Deep Copy or Shallow Copy)..
	 *  - Performance Usually Potentially expensive.
	 *  - Source Object	Left Unchanged.
	 *  - Copy Constructor 	-- "Can be detected by Copy Constructor with "LVR" L-Value Reference".
	 * 	Used When:
	 * 		- You pass an object by value.
	 * 		- You copy assign one object to another.
	 * 		- You explicitly call a copy constructor.
	 *
	 *  Object_1 :      Pointer -     Variable.
	 *  Object_2 : Same Pointer - New Variable.  " Shallow Copy"
	 *  Object_2 :  New Pointer - New Variable.  " Deep Copy"
	 *
	 * Move Semantics [= take ownership]:-
	 * ------------------------------------
	 * Moving transfers ownership of the resources from one object to another — no deep copy, just handing over the data.
	 *  - Transfer ownership of Resources.
	 *  - Usually faster Performance.
	 *  - Source Object	Left in valid but "empty" state.
	 *  - Move Constructor   -- "Can be detected by Copy Constructor with "RVR" R-Value Reference".
	 *  Used When:
	 *  	- You pass an object using std::move.
	 *  	- Temporary objects (rvalues) are involved.
	 *  	- Performance matters (e.g., in vectors).
	 *
	 *  Object_1 :      Pointer -     Variable.
	 *  Object_2 : Same Pointer - New Variable.  " Shallow Copy" + Object_1.Pointer = NULL
	 *  Then, When Object_1 Destructor will be called safely for Object_1 without affecting new Object.
	 */
	intData myData1 {1};
	intData myData2 {3};
	// must disable "-fno-elide-constructors" compiler flag
	myData1.setValue( addIntData(myData1, myData2).getValue() );// I will Add two intData, return of it will be new Object, this Object gets its value. (R-Val)
	myData1.getValue();
}

