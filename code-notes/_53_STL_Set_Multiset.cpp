/*
 * _53_STL_Set_Multiset.cpp
 *
 *  Created on: May 26, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <set>

/****************************************************************************************
 * Associative Containers:
 * ------------------------
 * 	- Set & Multiset.
 * 	- Map & Multimap.
 */

/****************************************************************************************
 * std::set/multiset:
 * -------------------
 * 	- Implemented as a binary tree.
 * 	- Elements are stored in sorted order, it uses operators "<" and ">".
 * 	- Value act as a key.
 * 	- Fast in Search mechanism.
 * 	- NO Random Access.
 * 	- Elements can't be modified directly.
 * 	- #include <set/multiset>
 */
void _53_01_STL_Set() {

	///////////// Create a Set
	//std::set<int, std::greater<int>> mySetg {100, 23, 50, 14, -1, 28};		// Sort Descending
	//std::set<int, std::less<int>> mySetl {100, 23, 50, 14, -1, 28};			// Sort Ascending
	std::set<int> mySet {100, 23, 50, 14, -1, 28};								// Default Sort: Less

	///////////// Using Iterators
	auto printSet = [&mySet]() {
		for(auto element: mySet)
			std::cout << element << " ";
		std::cout<< std::endl;
	};
	printSet();

	///////////// Insert operation only available, locating in correct location according to sorting.
	mySet.insert(120);
	mySet.insert(220);
	mySet.insert(220);
	mySet.insert(220);
	mySet.insert(220);		// Set DOESNOT ALLOW DUPLICATES.
	printSet();

	///////////// I CAN NOT MODIFY VALUE, Only Erase.
	//auto itr {mySet.begin()}; *itr = 1;				// WRONG
	mySet.erase(-1);									// Either by value, because value == key.
	mySet.erase(mySet.begin());							// or by Iterator
	printSet();

	///////////// Using find() operation
	auto checkItr = [&mySet](auto myItr) {
		if(mySet.end() != myItr)
			std::cout << "Element Found..." << std::endl;
		else
			std::cout << "Element NOT Found..." << std::endl;
	};
	checkItr(mySet.find(120));
	auto isFoundItr = mySet.find(1000);
	checkItr(isFoundItr);

	std::cout<< "-------------------------------------" << std::endl;
}
void _53_02_STL_Multiset() {

	///////////// Create a Set
	//std::set<int, std::greater<int>> mySetg {100, 23, 50, 14, -1, 28};		// Sort Descending
	//std::set<int, std::less<int>> mySetl {100, 23, 50, 14, -1, 28};			// Sort Ascending
	std::multiset<int> myMultiSet {100, 23, 50, 14, -1, 28};								// Default Sort: Less

	///////////// Using Iterators
	auto printSet = [&myMultiSet]() {
		for(auto element: myMultiSet)
			std::cout << element << " ";
		std::cout<< std::endl;
	};
	printSet();

	///////////// Insert operation only available, locating in correct location according to sorting.
	myMultiSet.insert(120);
	myMultiSet.insert(220);
	myMultiSet.insert(220);
	myMultiSet.insert(220);
	myMultiSet.insert(220);		// MULTISet DUPLICATES.
	printSet();

	///////////// I CAN NOT MODIFY VALUE, Only Erase.
	//auto itr {mySet.begin()}; *itr = 1;				// WRONG
	myMultiSet.erase(-1);									// Either by value, because value == key.
	myMultiSet.erase(myMultiSet.begin());							// or by Iterator
	printSet();

	///////////// Using find() operation
	auto checkItr = [&myMultiSet](auto myItr) {
		if(myMultiSet.end() != myItr)
			std::cout << "Element Found..." << std::endl;
		else
			std::cout << "Element NOT Found..." << std::endl;
	};
	checkItr(myMultiSet.find(220));
	auto isFoundItr = myMultiSet.find(1000);
	checkItr(isFoundItr);


	///////////// EXTRA FEATURES IN MULTISET
	///////////// Search for a value .. Handle multiple occurence case.
	auto checkRange = [&myMultiSet](auto value) {
		auto count {0};
		auto rangeFound = myMultiSet.equal_range(value);		// Return an std::pair(of iterators). 1st and Last

		if(myMultiSet.end() != rangeFound.first) {				// Make sure it is found
			while(rangeFound.first != rangeFound.second) {		// Count Occurrence
				count++;
				rangeFound.first++;
			}
		}
		std::cout << count << " Occurrence(s)." << std::endl;
	};
	checkRange(1000);
	checkRange(23);
	checkRange(220);

}


void _53_STL_Set_Multiset() {

	_53_01_STL_Set();
	_53_02_STL_Multiset();
}


