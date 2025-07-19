/*
 * _39_ClassTemplates_P2.cpp
 *
 *  Created on: May 20, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <vector>

/* Module Description:-
 * ---------------------
 * 	1. Class Explicit Specialization.
 * 		All Template parameters can be specialized.
 * 	2. Class Method Explicit Specialization.
 * 		Only Certain method in class can be specialized.
 * 	3. Class Partial Specialization.
 * 		Only some of parameters can be specialized.
 */

/* Class Template Explicit Specialization */
template<typename printType__>
class prettyPrinter {
	printType__* mPtrData;
public:
	prettyPrinter(printType__* l_data): mPtrData(l_data) {}
	void execute() const {
		std::cout << "{ " << *mPtrData << " }" << std::endl;
	}
	printType__* getDataPtr() const {
		return mPtrData;
	}

};
/* Template Explicit Specialization - const char* */
template<>			// Here if want to change multiple behavior in template class
class prettyPrinter<const char*> {
	const char* mPtrData;
public:
	prettyPrinter(const char* l_data): mPtrData(l_data) {}
	void execute() const {
		std::cout << "{ " << *mPtrData << " }" << std::endl;
	}
	const char* getDataPtr() const {
		return mPtrData;
	}

};
/* Method Function Explicit Specialization - in std::vector */
template<>			// Here if want only to change method inside template class
void prettyPrinter<std::vector<int>>::execute() const {
	std::cout << "{ ";
	for(const auto& element: *mPtrData) {
		std::cout << element << " ";
	}
	std::cout << "}" << std::endl;
}

/* --------------- Assignment V --------------- */
/* Method Function Explicit Specialization - in std::vector<std::vector<int>> */
template<>			// Here if want only to change method inside template class
void prettyPrinter<std::vector<std::vector<int>>>::execute() const {
	for(const auto& vect: *mPtrData) {
		std::cout << "{ ";
		for(const auto& element: vect) {
			std::cout << element << " ";
		}
		std::cout<< "}" << std::endl;
	}
}
/*********************************************************************************************************/



/* Partial Class Template Explicit Specialization */
template<typename printType__, int COLUMNS>
class prettyPrint {
	printType__* mPtrData;
public:
	prettyPrint(printType__* l_data): mPtrData(l_data) {}
	void execute() const {
		std::cout << "{ " << *mPtrData << " }" << std::endl;
	}
	printType__* getDataPtr() const {
		return mPtrData;
	}

};
/* Partial Specialization */
template<typename printType__>
class prettyPrint<printType__, 10> {
	printType__* mPtrData;
public:
	prettyPrint(printType__* l_data): mPtrData(l_data) {}
	void execute() const {
		std::cout << "{ " << *mPtrData << " } -- Using COLUMNS: 10" << std::endl;
	}
	printType__* getDataPtr() const {
		return mPtrData;
	}

};

template<typename ptrType__>
class smartPTR {
	ptrType__ *mPtr;
public:
	smartPTR(ptrType__* l_ptr): mPtr(l_ptr) {
		std::cout << "Constructor smartPTR()..." << std::endl;
	}
	ptrType__* operator->() {
		return mPtr;
	}
	ptrType__& operator*() {
		return *mPtr;
	}
	~smartPTR() {
		std::cout << "Destructor ~smartPTR()..." << std::endl;
		delete mPtr;
	}
};
/* Partial Specialization */
template<typename ptrType__>
class smartPTR<ptrType__[]> {
	ptrType__ *mPtr;
public:
	smartPTR(ptrType__* l_ptr): mPtr(l_ptr) {
		std::cout << "Constructor-ParitialSpecialization smartPTR()..." << std::endl;
	}
	ptrType__& operator[](int idx) {
		return mPtr[idx];
	}
	~smartPTR() {
		std::cout << "Destructor-ParitialSpecialization ~smartPTR()..." << std::endl;
		delete[] mPtr;
	}
};
/*********************************************************************************************************/

void _39_ClassTemplates_P2() {

	int iData {10};
	prettyPrinter<int> intPP {&iData};
	std::cout << ".." << intPP.getDataPtr() << ".." << std::endl;
	intPP.execute();

	float fData {20.20};
	prettyPrinter<float> floatPP {&fData};
	std::cout << ".." << floatPP.getDataPtr() << ".." << std::endl;
	floatPP.execute();

	const char* strData_0 {"Hello,"};
	prettyPrinter<const char> strPP_0 {strData_0};
	std::cout << std::endl << "{ " << strPP_0.getDataPtr();

	//	const char* strData_1 {"Goodbye!"};
	//	prettyPrinter<const char*> strPP_1 {&strData_1};
	//	std::cout << ".."  << *(strPP_1.getDataPtr()) << std::endl;
	const char* strData_2 {"Goodbye!"};
	prettyPrinter<const char*> strPP_2 {strData_2};							// Instead of using with const char ... or const char* with *().
	std::cout << ".." << strPP_2.getDataPtr() << " }" << std::endl;			// we can handle it with Explicit Specialization

	std::vector<int> vectData {1, 2, 3, 4, 5, 10, 20, 30, 40, 50};
	prettyPrinter<std::vector<int>> vectPP {&vectData};
	std::cout << ".." << vectPP.getDataPtr() << ".." << std::endl;
	vectPP.execute();

	std::vector<std::vector<int>> vVectData {{1, 2, 3, 4, 5}, {10, 20, 30, 40, 50}};
	prettyPrinter<std::vector<std::vector<int>>> vVectPP {&vVectData};
	std::cout << ".." << vVectPP.getDataPtr() << ".." << std::endl;
	vVectPP.execute();
	/*********************************************************************************************************/


	/* Partial Specialization Topic */
	const char* strData {"Hello, World!"};
	prettyPrint<const char, 50> stringPP_ {strData};
	stringPP_.execute();;

	prettyPrint<const char, 10> stringPP__ {strData};
	stringPP__.execute();;

	smartPTR<int> myPtr {new int {5}};
	std::cout << "*myPtr= " << *myPtr << std::endl;

	smartPTR<int[]> myArrPtr {new int[2]};
	myArrPtr[0] = 10;
	myArrPtr[1] = 20;
	std::cout << "myArrPtr[0]= " << myArrPtr[0] << std::endl;
	std::cout << "myArrPtr[0]= " << myArrPtr[1] << std::endl;
	/*********************************************************************************************************/
}
