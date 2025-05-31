/*
 * _57_STL_Conatiners_ExtraFeatures.cpp
 *
 *  Created on: May 30, 2025
 *      Author: AhmedMontasser
 */


#include <vector>
#include <deque>
#include <list>
#include <set>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "intData.hpp"

void _57_STL_Conatiners_ExtraFeatures_P1() {
	/**
	 * Module Description:-
	 * ---------------------
	 * 	1. Brace-list Initialization	: Directly Initialization in Variable Definition.
	 * 	2. emplace functions			: Better handling of assigning minimum constructor calls.
	 */
	std::vector<int> vInt {1, 2, 3, 4};			// Brace-list Initialization, Available in all Containers

	std::vector<intData> vIntData;
	//vIntData.push_back(5);						// Two Constructor called, Parameterized then Move Constructors
	vIntData.emplace_back(5);						// Better Practice {direct Values} : emplace(), only Parameterized constructor is called directly in vector.
	// If already created Object, no difference between Push() and Emplace()

	std::vector<std::pair<int, std::string>> vPair;
	vPair.push_back(std::make_pair(100, "Ahmed"));
	vPair.emplace_back(101, "Mohamed");					// Simple usage.
}

void _57_STL_Conatiners_ExtraFeatures_P2() {
	/**
	 * Module Description:-
	 * ---------------------
	 * 	1. Make sure if storage is reallocated, The Class uses Move Operation instead of copy..
	 * 	>>> using of noexcept
	 *------------------------------------------------------
	 * Adding noexcept to move constructor:
	 * - Give you the ability to use move constructors be compiler when possible,
	 * usecase: vector is reallocating the members, move will be executed instead of copy.
	 */
	std::vector<intData> vIntData_1;
	vIntData_1.emplace_back(1);
	vIntData_1.emplace_back(2);
	vIntData_1.emplace_back(3);
	vIntData_1.emplace_back(4);
	vIntData_1.emplace_back(5);
}

void _57_STL_Conatiners_ExtraFeatures_P3() {
	/**
	 * Module Description:-
	 * ---------------------
	 * 	1. Vector Capacity and Shrink Feature
	 */

	std::vector<int> vInt;
	for(size_t i{0}; i<100; ++i) {
		vInt.emplace_back(i);
	}
	std::cout<< "Size= " << vInt.size() << std::endl;				// Total # of elements, that are allocated.
	std::cout<< "Capacity= " << vInt.capacity() << std::endl;		// Total # of elements, Vector can allocate before initiating a capacity grow.

	// What if i remove some elements from vector?
	vInt.erase(vInt.begin(), vInt.end()-20);
	std::cout<< "Size= " << vInt.size() << std::endl;				// Size is updated.
	std::cout<< "Capacity= " << vInt.capacity() << std::endl;		// The Capacity remains the same, will lead to memory waste.
	vInt.shrink_to_fit();
	std::cout<< "Capacity= " << vInt.capacity() << std::endl;		// C++11 Feature: Extra unused memory will be trimmed. [Size==Capacity]
}

void _57_STL_Conatiners_ExtraFeatures_P4() {
	/**
	 * Module Description:-
	 * ---------------------
	 * 	Use of Resize(), Data() in Vector.
	 * 	File system library ..
	 * 	Dynamic handling of file sizes.
	 * 	Without dealing with manual memory management.
	 */

	std::ifstream inputFile {"main.cpp"};
	if(!inputFile) {
		std::cout<< "Error: Couldn't find the file!" << std::endl;
		return;
	}
	// C++17 Feature to fetch size of file.
	auto size = std::filesystem::file_size("main.cpp");
	std::vector<char> fBuffer;				// Create a Buffer using vector
	fBuffer.resize(size);					// Resize vector size.
	inputFile.read(fBuffer.data(), size);	// Read data in Vector .data() return pointer to data in buffer.
	std::cout<< fBuffer.data() << std::endl;
}

template<typename varType__>
void print(const varType__& myElements) {
	for(const auto& element: myElements) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
};
void _57_STL_Conatiners_ExtraFeatures_P5() {
	/**
	 * Module Description:-
	 * ---------------------
	 * 	Erase by Value in vector, list, deque
	 */
	std::vector<int> vectorInt {1,2,3,4,2};
	std::list<int> listInt {1,2,3,4,2};
	std::deque<int> dequeInt {1,2,3,4,2};

	// C++20 Function: to Erase by Value
//	std::erase(vectorInt, 2);
//	std::erase(listInt, 2);
//	std::erase(dequeInt, 2);

	print(vectorInt);
	print(listInt);
	print(dequeInt);
}

void _57_STL_Conatiners_ExtraFeatures_P6() {
	/**
	 * Module Description:-
	 * ---------------------
	 * 	emplace_hint()
	 * 	It allows you to insert an element with a hint about where the insertion should occur,
	 * 	which can improve performance if the hint is accurate.
	 *
	 * 	Faster way in value inseration/change in associative container
	 */
	std::set<int> setInt {1,2,3,4,2};
	setInt.emplace_hint(setInt.begin(), 0);

	auto isFound = setInt.contains(4);		// Another way of search on element in assocaitive containers.
	if(isFound)
		std::cout<< "Element found." << std::endl;

	/**************************************/

	std::set<std::string> myStr {"Ahmed", "mohamed", "Mahmoud"};
	for(auto element: myStr)
		std::cout << element << " ";
	std::cout << std::endl;

	auto foundItr = myStr.find("mohamed");
	if(myStr.end() != foundItr) {
		auto node = myStr.extract(foundItr);
		/** Better way */
		node.value()[0] = 'M';
		myStr.insert(std::move(node));

		/** Traditional way */
//		auto element = *foundItr;
//		element[0] = "U";
//		myStr.erase(foundItr);
//		myStr.insert(element);
	}

	for(auto element: myStr)
		std::cout << element << " ";
	std::cout << std::endl;
}


void _57_STL_Conatiners_ExtraFeatures() {

//	_57_STL_Conatiners_ExtraFeatures_P1();
//	_57_STL_Conatiners_ExtraFeatures_P2();
//	_57_STL_Conatiners_ExtraFeatures_P3();
//	_57_STL_Conatiners_ExtraFeatures_P4();
//	_57_STL_Conatiners_ExtraFeatures_P5();
	_57_STL_Conatiners_ExtraFeatures_P6();


}
