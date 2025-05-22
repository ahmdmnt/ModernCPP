/*
 * _36_FunctionTemplates_P3.cpp
 *
 *  Created on: May 17, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "intData.hpp"


/* Perfect Forwarding:-
 * ---------------------
 *	TO CHECK MORE .
 *******************************************************************************/

/* ---- Perfect Forwarding ---- */
class ftEmployee {
	std::string mName;
	intData mID;

public:
//	ftEmployee(const std::string& name, const intData& id) : mName{name}, mID{id} {
//		std::cout << "ftEmployee(const std::string& name, const intData& id) -- Parameterized COPY." << std::endl;
//	}
//	ftEmployee(std::string&& name, intData&& id) : mName{name}, mID{id} {		// Adding std::move in id,, will force move of value in passed variable in line #42
//			std::cout << "ftEmployee(std::string&& name, intData&& id) -- Parameterized MOVE." << std::endl;
//	}

// WHAT IF I NEED TO MAKE SURE TO USE MOVE INSTEAD OF COPY >>>
//	INSTEAD OF ADDING MANY VERSION OF Constructors.... Better to Use Template.
	template<typename strType__, typename intType__>
	ftEmployee(strType__ &&name, intType__ &&id) :
	mName { std::move<strType__>(name) },		// mName { std::forward<strType__>(name) },
	mID { std::move<intType__>(id) }  {			// mID { std::forward<intType__>(id) }
		std::cout << "ftEmployee(strType__ &&name, intType__ &&id) -- Parameterized TemplateMOVE." << std::endl;
	}
};
/**********************************************************************************************************************/


void _36_FunctionTemplates_P3() {

	/* THE RULE BELOW:
	 * If i have a Constructor with R-Value References:
	 * 	- If L-Values are passed as arguments, it would remain L-Value References.
	 * 	- If R-Values are passed as arguments, it will become R-Value References.
	 * 	- THIS HAPPENS ONLY IF: FunctionTemplate accepts it as R-Value References.
	 * 	- OTHERWISE, Reference Collapsing rules will not apply. */
	std::string name {"Mohamed"};
	intData id {200};
//	ftEmployee myEmp {"Ahmed", 100};		// Parameterized MOVE
	ftEmployee myEmp {"Ahmed", id};			// Parameterized COPY
//	ftEmployee myEmp {name, id};			// Parameterized COPY
//	ftEmployee myEmp {name, 100};			// Parameterized COPY


}
