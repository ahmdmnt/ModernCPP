/*
 * _40_AliasTemplates.cpp
 *
 *  Created on: May 20, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <vector>

/* Module Description:-
 * ---------------------
 * 	1. Type Definition: typedef:
 * 	   > Doesn't introduce a new type, instead introduce a new name of existing type.
 * 	   > Useful for constructing shorter/meaningful names for existing type.
 * 	   > Useful for encapsulation of implementation details that can be changed.
 * 	   > CAN NOT BE USED WITH TEMPLATES.
 *
 *  2. Type Alias: using :
 * 	   > same as typedef.
 * 	   > much readable format.
 * 	   > CAN BE USED WITH TEMPLATES.
 */

/* Type Defintion : typedef */
typedef unsigned int uint_32;
typedef const char* (*ErrFnPtr)(int);
/********************************************/

/* Type Alias : using */
using uintt_32 = unsigned int;
using ErrFnPtrr = const char* (*)(int);
/********************************************/


/* Alias Template */
template<typename InnerMemberType__>
using vvector = std::vector<std::vector<InnerMemberType__>>;
/********************************************/

const char* getError(int code) {
	switch (code) {
	case 1:
		return "File not found";
	case 2:
		return "Access denied";
	default:
		return "Unknown error";
	}
}

void _40_AliasTemplates() {
	uint_32 myVariable1 {10};
	ErrFnPtr pErrFn1 = getError;

	uintt_32 myVariable2 {10};
	ErrFnPtrr pErrFn2 = getError;

	vvector<int> _2D_intVector   {{1,2,3},{1,2,3}};
	vvector<char> _2D_charVector {{'A','B','C'},{'A','B','C'}};
}




