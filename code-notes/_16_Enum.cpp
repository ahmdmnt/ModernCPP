/*
 * _16_Enum.cpp
 *
 *  Created on: May 2, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/*
 * Enum Type:-
 * ------------
 * 	- More readable way for representing values.
 * 	- Created to restrict range of values, through symbolic constant.
 * 	- Enum are internally represented as undefined integral type.
 * 	- 1st enum value is by default: 0, but it is configurable.
 */

/* C-Style Enum:-
 * --------------
 * 	- Can implicitly convert to int, but not the opposite.
 * 	- It has a global scope with Enum values only, example: ENUM_VALUE.
 * 		> Can not redefine same values in different enum "duplication".
 */
enum bkgrdColors {RED, GREEN, BLUE};
//enum frgrdColors {RED, GREEN, BLUE};		// ERROR: conflicts with a previous declaration

/* C++ Enum [C++11]:-
 * -------------------
 * 	- Can NOT implicitly convert to int, but not the opposite.
 * 	- It has scoped enum values, through enum type name, example: ENUM_TYPE::ENUM_VALUE.
 * 		> Can be redefine same values in different enum.
 */
enum class motorState   : char {NOK='M', OK};		// Specifying type of Enum is Optional and by default it is int	// OK='N'
enum class batteryState : long {NOK=100, OK=120};		// Specifying first/each value is optional and by default it is 0.

void fillColor(bkgrdColors l_color) {
	if(RED == l_color) {
		std::cout << "red color." << std::endl;
	}
	else if(GREEN == l_color) {
		std::cout << "green color." << std::endl;
	}
	else {
		std::cout << "other color." << std::endl;
	}
}

void checkMotor(motorState l_state) {
	if(motorState::OK == l_state) {
		std::cout << "Motor is OK." << std::endl;
	}
	else if (motorState::NOK == l_state){
		std::cout << "Motor is Not OK." << std::endl;
	}
}

void _16_Enum(void) {

	/* C-Style Enum */
	bkgrdColors myColor {GREEN};
	myColor = RED;
	//myColor = 0;			// ERROR: invalid conversion from 'int' to 'bkgrdColors'
	//fillColor(0);			// ERROR: invalid conversion from 'int' to 'bkgrdColors'
	fillColor(myColor);
	fillColor(static_cast<bkgrdColors>(1));

	int colorValue = RED;	// Can implicitly convert to int
	std::cout<< "colorValue= " << colorValue <<std::endl;
	/********************************************************************************/

	/* C++ Enum */
	motorState motor_1 {motorState::OK};
	checkMotor(motor_1);
	checkMotor(motorState::NOK);
	//checkMotor(1);						// ERROR: cannot convert 'int' to 'motorState'
	checkMotor(static_cast<motorState>(1));

	//int motor_2 = motorState::OK;			// ERROR: cannot convert 'motorState' to 'int' in initialization
	int motor_2 = static_cast<int>(motorState::OK);
	std::cout<< "motor_2= " << motor_2 <<std::endl;
}

