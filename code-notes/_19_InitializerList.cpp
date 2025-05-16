/*
 * _19_InitializerList.cpp
 *
 *  Created on: May 6, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <initializer_list>

/* Module Description:-
 * ---------------------
 * 	1.
 *
 */

enum class processStatus : bool { NOK, OK };

class bag {
	constexpr static int SIZE {20};
	int pockets[SIZE];
	int occupied {0};

public:
	bag() {

	}

	bag(std::initializer_list<int> l_values) {
		if(l_values.size() > SIZE) {
			std::cout << "Error: Bag maximum size is 10 pockets." << std::endl;
			return;
		}
		auto pocketIt = l_values.begin();
		while(pocketIt != l_values.end()) {
			this->pocketInsert(*pocketIt);
			++pocketIt;
		}
	}
	processStatus pocketInsert(int value) {
		if(occupied >= SIZE) {
			std::cout<< "The Bag is full, unable to process!" << std::endl;
			return processStatus::NOK;
		}
		else {
			pockets[occupied++] = value;
			return processStatus::OK;
		}
	}
	void pocketRemove(int count=1) {
		while(count > 0 ) {
			--occupied;
			--count;
		}
	}
	int pocketOccupiedSize() const {
		return occupied;
	}
	void pocketCheckAll() const {
		std::cout << "Pockets Content: ";
		for(auto idx=0; idx<occupied; idx++) {
			std::cout<< pockets[idx] << " ";
		}
		std::cout << std::endl;
	}
	int operator[](int idx) {
		return pockets[idx];
	}
};

void fetchRawContent_gFu(std::initializer_list<int> l_vals) {
	auto valIt= l_vals.begin();
	while (valIt != l_vals.end()) {
		std::cout<< *valIt++ << " ";
	}
	// OR	Ranged-For Loop
	//for(auto ele: l_vals) {
	//	std::cout<< ele << " ";
	//}
	std::cout<< std::endl;
}

void _19_InitializerList(void) {
	/* Uniform Initialization */
	int a {10};
	float b {10.1};
	int arr[] {1, 2, 3, 4};
	std::string str {"ABCD"};

	/* Initializer List:-
	 * -------------------
	 * Introduced by uniform initialization. and it is used to store array of objects.
	 * - It is a class template.
	 * - What is the Purpose of Initializer List?
	 * 	 It is commonly used with container classes. Container class are those classes that can hold objects of other classes.
	 * - Lightweight proxy object that represent array of Objects.
	 * - Constructed automatically from braced list of elements.
	 * 	  - when used:
	 * 		1. directly,
	 * 		2. Keyword: auto,
	 * 		3. Ranged-For loop,
	 * 		4. Object Constructor,
	 * 		5. Function Argument.
	 * - Provide access to its elements through, iterators.
	 */

	std::initializer_list myData1 {1, 2, 3};
	auto myData2 = {1, 2, 3};							// This {} value will be deduced as an initializer list.

	bag myBag;
	myBag.pocketInsert(10);
	myBag.pocketInsert(20);
	myBag.pocketInsert(30);
	myBag.pocketInsert(40);
	myBag.pocketInsert(50);
	myBag.pocketInsert(60);

	std::cout<< "myBag Occupied Size: " << myBag.pocketOccupiedSize() << std::endl;
	myBag.pocketCheckAll();

	myBag.pocketRemove();
	myBag.pocketRemove(2);
	std::cout<< "Occupied Size: " << myBag.pocketOccupiedSize() << std::endl;
	std::cout<< "Content: ";
	for(auto idx=0; idx<myBag.pocketOccupiedSize(); ++idx) {
		std::cout<< myBag[idx] << " ";
	}
	std::cout<< std::endl << "------------------------------" << std::endl;

	/* What if i need to initialize the element in class, like array in declaration, instead of using .pocketInsert() ?
	 * -----------------------------------------------------------------------------------------------------------------
	 *
	 */
	bag yourBag {15,25,35};

	/* Example for Global function with Init_list */
	std::cout<< "yourBag Occupied Size: " << yourBag.pocketOccupiedSize() << std::endl;
	yourBag.pocketCheckAll();
	std::cout << std::endl;

	std::cout<< "Raw List: " << yourBag.pocketOccupiedSize() << std::endl;
	fetchRawContent_gFu({101, 102, 103, 104});
}



