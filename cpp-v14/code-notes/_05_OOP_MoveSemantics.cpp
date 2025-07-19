/*
 * _05_OOP_MoveSemantics.cpp
 *
 *  Created on: Apr 18, 2025
 *      Author: AhmedMontasser
 */

#include <iostream>
#include "intData.hpp"

/* Module Description:-
 * ---------------------
 * 	1. Copy Semantics.
 * 	2. Move Semantics.
 */



intData addIntData(const intData &n1, const intData &n2) {
	intData tempData;	//	Default Constructor
	tempData.setValue(n1.getValue()+n2.getValue());
	return tempData;
}

void _05_OOP_MoveSemantics() {

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
	intData myData1 {1};	// Parameterize Constructor
	intData myData2 {3};	// Parameterize Constructor

	/* Description of Below Code Line [if -fno-elide-constructors is enabled]:-
	 * --------------------------------------------------------------------------
	 * 1. I will Add two intData, Create an Object - Default constructor.
	 * 2. Set its value with Sum of two passed args.
	 * 3. return this Object. -- After return a temp Object will be created by Move Constructor .
	 * 4. Fetch Value from this temp Object.
	 * 5. Set myData1 Object with the temp Object value.
	 *
	 * intData(intData&& rrefObj) being invoked (move constructor), because tempData is a local object and is about to be returned.
	 * tempData is constructed directly in the memory allocated for the result in the calling function (myData1.setValue(...)).
	 *
	 * Description of Below Code Line [if -fno-elide-constructors is disabled]:-
	 * --------------------------------------------------------------------------
	 * Move Elision will Occur .. it will skip creating the temp Object in Step 3 and 4.
	 * and Compiler will move value directly and construct the Object at destination.
	 *
	 * The compiler constructs tempData directly into the target of the assignment in the caller (myData1.setValue(...)).
	 *
	 * [[Move Elision]]:
	 * is a compiler optimization where unnecessary copy or move operations are skipped.
	 * It makes your C++ programs faster by constructing objects directly in their destination,
	 * rather than moving or copying them after construction.
	 */
	myData1.setValue( addIntData(myData1, myData2).getValue() );
	myData1.getValue();
}

