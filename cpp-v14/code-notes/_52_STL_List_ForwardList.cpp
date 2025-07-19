/*
 * _52_STL_List_ForwardList.cpp
 *
 *  Created on: May 25, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <list>
#include <forward_list>

/****************************************************************************************
 * std::list:
 * -----------
 * 	- Implemented as a TWO-way Linked list.
 * 	  >>> Consists of nodes, and each node have pointers to next/previous nodes.
 * 	- Efficient for Insertion/Deletion at any location.
 * 	- CAN NOT Use Operator[], ONLY Iterators.
 * 	- DOES NOT Provide Random Access.
 * 	- COMMONLY USED: When u need list with frequent insertion and deletion and no need for random access
 * 	- #include <list>
 */
void _52_01_STL_List() {

	///////////// Create a List
	std::list<int> myList {1, 2, 3, 4, 5};

	///////////// Usage of Push Back/Front
	myList.push_back(10);
	myList.push_front(10);

	///////////// Use of Iterators
	auto printList = [&myList]() {
		auto itr = myList.begin();
		while(itr != myList.end())
			std::cout << *itr++ << " ";
		std::cout<< " -- Size: " << myList.size() << std::endl;
	};
	printList();

	///////////// Insertion/Deletion
	// Insertion/Deletion in ANY LOCATION take constant time, EFFICIENT!
	auto myItr = myList.begin();
	myList.insert(myItr, 1234);
	printList();
	myList.erase(--myItr);
	printList();

}
/****************************************************************************************
 * std::forward_list:
 * ------------------
 * 	- Implemented as a ONE-way Linked list.
 * 	  >>> Consists of nodes, and each node have pointers to next nodes, Forward Pointer ONLY.
 * 	- SMALL Memory Footprint.
 * 	- Efficient for Insertion/Deletion.
 * 	- When Elements are added, they are added from the Front.
 * 	- CAN NOT Use Operator[], ONLY Iterators.
 * 	- DOES NOT Provide Size
 * 	- #include <forward_list>
 */
void _52_02_STL_ForwardList() {

	///////////// Forward List Creation
	std::forward_list<int> myFwdList {0};

	///////////// Add Element, ONLY push_front
	myFwdList.push_front(1);
	myFwdList.push_front(2);
	myFwdList.push_front(3);
	myFwdList.push_front(4);

	///////////// Use of Iterators
	auto printFwdList = [&myFwdList]() {
		for(auto element: myFwdList)
			std::cout << element << " ";
		std::cout << std::endl;
		//myFwdList.size() 					// size() method is not available
	};
	printFwdList();

	///////////// Insertion/Deletion of Element
	myFwdList.insert_after(myFwdList.before_begin(), 100);			// Node will be inserted IN THE NEXT Position AFTER given iterator.
	printFwdList();
	myFwdList.erase_after(myFwdList.begin());						// Node will be erased IN THE NEXT Position AFTER given iterator.
	printFwdList();
}


void _52_STL_List_ForwardList() {

//	_52_01_STL_List();
	_52_02_STL_ForwardList();
}

