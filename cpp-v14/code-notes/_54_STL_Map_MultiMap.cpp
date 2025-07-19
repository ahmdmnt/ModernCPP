/*
 * _54_STL_Map_MultiMap.cpp
 *
 *  Created on: May 26, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <map>

/****************************************************************************************
 * Associative Containers:
 * ------------------------
 * 	- Set & Multiset.
 * 	- Map & Multimap.
 */

/****************************************************************************************
 * std::map/multimap:
 * -------------------
 * 	- Implemented as a binary tree.
 * 	- Store a pair that contains a key and value.
 * 	- Elements are stored in sorted order based on key.
 * 	- Fast Search as set.
 * 	- NO Random Access.
 * 	- Keys can not be modified directly, but values yes.
 * 	- #include <map/multimap>
 */
void _54_01_STL_Map() {

	///////////// Create a Map
	std::map<int, std::string, std::less<int>> myMap {
		{1, "Class A"},
		{2, "Class B"},
		{3, "Class C"}
	};

	///////////// Insert an object
	myMap[7] = "Class G";
	myMap.insert(std::make_pair(4, "Class D"));
	myMap.insert(std::pair<int, std::string>(5, "Class E"));

	///////////// Use the Subscript Operator []
	std::cout << "myMap[3] = " << myMap[3] << std::endl;
	std::cout << "myMap[100] = " << myMap[100] << std::endl;	// IF IT IS NOT FOUND, it will add a new Key with no Value
	//// NOT RECOMMENDED TO USE <<<


	///////////// Modify Value and Using Iterators
	myMap[0] = "Class A+";

	auto mapItr = myMap.begin();
	std::cout << "Key: "<< mapItr->first << " -- Value: " << mapItr->second << std::endl;
	auto printMap = [&myMap]() {
		for(auto pairElement: myMap)
			std::cout << pairElement.first << ": " << pairElement.second << std::endl;
		std::cout << std::endl;
	};
	printMap();

	///////////// Erase operation
	myMap.erase(2);myMap.erase(3);myMap.erase(100);
	printMap();

	///////////// Search Operation by Key
	auto findItr = myMap.find(7);
	if(myMap.end() != findItr)
		std::cout << "Key: " << findItr->first << " -- Value: " << findItr->second << std::endl;

	///////////// CAN NOT Add Multiple Keys Occurrence
	myMap.insert(std::make_pair(4, "Class D"));			// Only one occurrence will be their

	std::cout<< "-------------------------------------" << std::endl;
}
void _54_02_STL_MultiMap() {

	///////////// Create a Map
	std::multimap<int, std::string, std::less<int>> myMulMap {
		{1, "Class A"},
		{2, "Class B"},
		{3, "Class C"}
	};

	///////////// SAME MAP BEHAVIOR

	///////////// CAN Add Multiple Keys Occurrence
	myMulMap.insert(std::make_pair(4, "Class D"));
	myMulMap.insert(std::make_pair(4, "Class D"));
	myMulMap.insert(std::make_pair(4, "Class DD"));
	myMulMap.insert(std::make_pair(4, "Class DDD"));

	///////////// Using Iterators
	auto printMap = [&myMulMap]() {
		for(auto pairElement: myMulMap)
			std::cout << pairElement.first << ": " << pairElement.second << std::endl;
		std::cout << std::endl;
	};
	printMap();

	///////////// Support of equal_range operation like multiset
	auto checkItrCount = [&myMulMap](auto value) {
		auto itrCount {0};
		auto foundItr = myMulMap.equal_range(value);
		if(foundItr.first != foundItr.second) {
			std::cout<< "Key: " << foundItr.first->first << " - Value: " << foundItr.first->second << std::endl;
			while(foundItr.first != foundItr.second) {
				++itrCount;
				++foundItr.first;
			}
			std::cout<< itrCount << " Occurrence." << std::endl;
		}
		else {
			std::cout << "Not Found!" << std::endl;
		}
	};

	checkItrCount(0);
	checkItrCount(1);
	checkItrCount(4);
}


void _54_STL_Map_MultiMap() {

	_54_01_STL_Map();
	_54_02_STL_MultiMap();
}


