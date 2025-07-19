/*
 * intData.cpp
 *
 *  Created on: Apr 28, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include "intData.hpp"

/** Constructors and Destructor ************************************************************************************************************/
/* Default Constructor */
intData::intData() : pInt{new int {0}} {
	std::cout << "intData() - Default Constructor Invoked..." << std::endl;
}
/* Parameterized Constructor */
intData::intData(int l_value) : pInt{new int {l_value}} {
	std::cout << "intData() - Parameterized Constructor Invoked..." << std::endl;
}
/* Copy Constructor */
intData::intData(const intData& refObj) {
	std::cout << "intData() - Copy Constructor Invoked" << std::endl;
	this->pInt = new int{*refObj.pInt};	// Deep Copy.
}
/* Move Constructor */				//--- noexcept: guarantee to compiler, that while moving, there is no way exception will be thrown.
intData::intData(intData&& rrefObj) noexcept {		// r-valure reference CAN NOT be constant to allow moving resources
	//-- before using noexcept i have to make sure my implementation is exception safe!
	std::cout << "intData() - Move Constructor Invoked..." << std::endl;
	this->pInt = rrefObj.pInt;		// Shallow Copy.
	rrefObj.pInt = nullptr;			// Remove resource from old instance.
}
/* Destructor */
intData::~intData() {
	std::cout << "~intData() - Destructor Invoked..." << std::endl;
	delete pInt;
}
/*******************************************************************************************************************************************/
//////////////////////////////////////////////////////////
/** Copy and Move Assignment Operator Overloading ******************************************************************************************/
/* (=) Copy/Equality Operator Overloading */
intData intData::operator=(const intData &otherObj) {
	std::cout << "operator=() - Copy/Equality Operator Overloading Invoked..." << std::endl;
	if(this != &otherObj) {	// Handle Self-Assignment
		delete this->pInt;						// Cleanup existing resources.
		this->pInt = new int {*otherObj.pInt};	// Perform Deep Copy
	}
	return *this;
}
/* (=) Move/Equality Operator Overloading */
intData intData::operator=(intData &&otherObj) noexcept {		// noexcept: guarantee to compiler, that while moving, there is no way exception will be thrown.
	//-- before using noexcept i have to make sure my impelmentation is exception safe!
	std::cout << "operator=() - Move/Equality Operator Overloading Invoked..." << std::endl;
	if(this != &otherObj) {	// Handle Self-Assignment
		delete this->pInt;			// Clean up existing resources
		this->pInt = otherObj.pInt;	// Shallow Copy.
		otherObj.pInt = nullptr;	// Remove Resource from old instance.
	}
	return *this;
}
/*******************************************************************************************************************************************/
//////////////////////////////////////////////////////////
/** Built-in Class Operator Overloading Methods ********************************************************************************************/
/* Because this is Operator Overloading from Object, no need to add second Operand it is accessed through calling object. */
/* (+) Addition Operator Overloading */
intData intData::operator+(const intData &otherObj) const {	// this is a const method, NOT MODFIYING in Calling Object, using it only.
	std::cout << "operator+() - Addition Operator Overloading Invoked..." << std::endl;
	intData result;
	*result.pInt = *this->pInt + *otherObj.pInt;
	return result;
}
/* (++) Pre-Increment Operator Overloading */
intData& intData::operator++() {								// PREFIX Increment Operator - More Efficient
	std::cout << "operator++() - Pre-Increment Operator Overloading Invoked..." << std::endl;
	*this->pInt = *this->pInt+1;
	return *this;
}
/* (++) Post-Increment Operator Overloading */
intData intData::operator++(int) {							// POSTFIX Increment Operator - Less Efficient
	std::cout << "operator++() - Post-Increment Operator Overloading Invoked..." << std::endl;
	intData temp {*this};// @suppress("Invalid arguments")
	*this->pInt = *this->pInt+1;	// I will increment the Object.
	return temp;					// return incremented temp.
}
/* (==) Check Equality Operator Overloading */
bool intData::operator==(const intData &otherObj) const {		// Check Equality
	return (*this->pInt == *otherObj.pInt);
}
bool intData::operator>(const intData &otherObj) const {		// Check Greater Than
	return (*this->pInt > *otherObj.pInt);
}
bool intData::operator<(const intData &otherObj) const {		// Check Less Than
	return (*this->pInt < *otherObj.pInt);
}
/* (()) SIMPLE Function Call Operator Overloading */
void intData::operator()() {
	std::cout << "operator()() - Function Call Operator Overloading Invoked..." << std::endl;
	std::cout << "SIMPLE IMPLEMENTATION OF Function Call." << std::endl;
	std::cout << *this->pInt << std::endl << std::endl;
}
/*******************************************************************************************************************************************/
//////////////////////////////////////////////////////////
/** Type Conversion Operator Overloading ***************************************************************************************************/
intData::operator int() {
	return *pInt;
}
/*******************************************************************************************************************************************/
//////////////////////////////////////////////////////////
/** Class Methods Implementation ***********************************************************************************************************/
int intData::fetchValue(void) const {
	return *pInt;
}

int intData::getValue(void) const {
//	std::cout<< "intData= " << *pInt << std::endl;
	return *pInt;
}

void intData::setValue(int l_value) {
	if(nullptr == pInt) { // Re-Initialize if MOVED. OR // Define an Error.
		pInt = new int {l_value};
		// OR // std::cout << "ERR: This Object has been moved!!" << std::endl;
	}
		*pInt = l_value;
}
/*******************************************************************************************************************************************/


