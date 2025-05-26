/*
 * _51_STL_Array_Vector_Deque.cpp
 *
 *  Created on: May 24, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <array>
#include <vector>
#include <deque>

/**
 * STL: Standard Template Library:-
 * --------------------------------
 * 	1. Provides fast and reusable containers and algorithm.
 * 	2. Relies heavily on templates; almost every component in STL is a template.
 * 	3. Core Components in STL are:
 * 		- Container Classes : Represents the Data.
 * 		- Algorithms		: Operation on the Data.
 * 		- Iterators			: Operations done on Containers are through Iterators.
 * 	4. Other Classes for Concurrency, Random Numbers, Regular Expression and utilities etc...
 *
 *  5. Why using STL?
 *   - Quicker Development time.
 *   - Reliable, Portable, Efficient and Fast < Developed/Tested by experts.
 *   - Accurate and More Readable.
 *   - Low Maintenance Cost.
 *
 *   STL Containers:
 *    - Sequence Containers:
 *    ----------------------
 *      array / vector / list / deque / forward_list
 *
 *    - Associative Containers:
 *    -------------------------
 *		set / multiset / map / multimap
 *
 *    - Unordered Containers:
 *    -----------------------
 *      unordered_set / unordered_multiset / unordered_map / unordered_multimap
 *
 *    Common Functions:
 *    default/copy/iterator Constructor - uniform initialization - size() - clear() - begin() - end() - default allocator
 *
 *
 *   STL Iterators:
 *    - Pointer Like Objects.
 *    - Used to access element of container by their Position.
 *    - Provide multiple operator overloading operators, such as ++, --, *, etc..
 *    - Can be created through method begin() or end() in all containers.
 *    	- begin(): Iterator points to [[FIRST Element  ]] in Container.
 *    	- end()  : Iterator points to [[LAST+1 LOCATION]] after Container.
 *     			>>>ALSO USED, to check for SUCCESS/FAIL for certain algorithm, many algorithm return .end() upon failure.
 *****************************************************************************************************************************/

/****************************************************************************************
 * std::array:
 * -----------
 * 	- Thin wrapper over C-Style static array.
 *	  Store Element as static array internally.
 *	- Support Iterators.
 *	- Knows about its size and allow random access.
 *	- can be used with C FUNCTION.
 *	- IT CAN NOT Grow, static array unlike vectors.
 *	- #include <array>
 */
void _51_01_STL_Array() {
	///////////// Create an std::array
	std::array<int, 5> myArray {3, 4, 8, 9, 10};

	///////////// usage of size() Method
	int size {static_cast<int>(myArray.size())};
	for(auto idx{0}; idx<size; ++idx) {
		///////////// usage of operator[]
		myArray[idx] = idx;
	}

	///////////// usage of Iterators
	auto arrItr = myArray.begin();
	for(auto element: myArray) {		// element
		std::cout << element << " ";
	}
	std::cout << std::endl;

	///////////// return pointer to internal array, to be backward compatible with C.
	int* ptrArray = myArray.data();
	std::cout << *(ptrArray+0) << std::endl;
	std::cout << *(ptrArray+1) << std::endl;
	std::cout <<   ptrArray[2] << std::endl;
}
/****************************************************************************************
 * std::vector:
 * -----------
 * 	- Behave like a dynamic Array, Can Grow in Run-time.
 *	- Efficient in removal/addition of element at the end.
 *  - Internally implemented as Array, it provide random access.
 *  - NOT GOOD in Insertion and deletion, except at the end.
 *	- #include <vector>
 */
void _51_02_STL_Vector() {

	///////////// Create a Vector
	std::vector<int> myVector {1, 2, 3, 4, 5};		// No need to mention size it will deduce it.

	///////////// Use Iterators inside Lambda Expression
	auto printVector = [&myVector]() {
		auto vectorItr {myVector.begin()};
		while( vectorItr != myVector.end() ) {
			std::cout << *vectorItr++ << " ";
		}
		std::cout << std::endl;
	};
	printVector();

	///////////// Check size of Vector
	std::cout << "Vector Size: " << myVector.size() << std::endl;

	///////////// Add Element at the End -- Remove Element from End  {{BEST-PRACTICE}}
	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);
	printVector();
	std::cout << "Vector Size: " << myVector.size() << std::endl;
	myVector.pop_back();
	printVector();
	std::cout << "Vector Size: " << myVector.size() << std::endl;

	///////////// Access by Element
	std::cout << "Element 0: " << myVector[0] << std::endl;
	std::cout << "Element 1: " << myVector.at(1) << std::endl;


	///////////// Insertion/Deletion Operation
	// Not Recommended ,, Complex Operation that shift whole existing element in vector and
	// it will lead to multiple assignments/copies, especially with user-defined objects.
	myVector.insert(myVector.begin(), 0);
	printVector();
	std::cout << "Vector Size: " << myVector.size() << std::endl;
	myVector.erase(myVector.end()-3);
	printVector();
	std::cout << "Vector Size: " << myVector.size() << std::endl;
}
/****************************************************************************************
 * std::deque:
 * -----------
 * 	- Short for Double Ended Queue.
 * 	- Similar to Vector, PLUS, you can add elements to both ends.
 * 	- Provide random access.
 * 	- EFFICIENT in Addition and Removal from both Ends.
 * 	- NOT GOOD in Insertion and deletion, except at the begin/end.
 * 	- Most Common in Implementing Queues.
 *	- #include <deque>
 */
void _51_03_STL_Deque() {

	///////////// LITRALLY I COPIED VECTOR CODE .. SAME BEHAVIOR, EXCEPT IT IS EFFICIENT FOR
	// ADDING REMOVING FROM BOTH ENDS <<<<

	///////////// Create a Deque
	std::deque<int> myDeque {1, 2, 3, 4, 5};		// No need to mention size it will deduce it.

	///////////// Use Iterators inside Lambda Expression
	auto printDeque = [&myDeque]() {
		auto dequeItr = myDeque.begin();
		while( dequeItr != myDeque.end() ) {
			std::cout << *dequeItr++ << " ";
		}
		std::cout << std::endl;
	};
	printDeque();

	///////////// Check size of Deque
	std::cout << "Deque Size: " << myDeque.size() << std::endl;

	///////////// Add Element at the Begin/End -- Remove Element from Begin/End  {{BEST-PRACTICE}}
	myDeque.push_back(10);
	myDeque.push_back(20);
	myDeque.push_front(10);
	myDeque.push_front(20);
	printDeque();
	std::cout << "Deque Size: " << myDeque.size() << std::endl;
	myDeque.pop_back();
	myDeque.pop_front();
	printDeque();
	std::cout << "Deque Size: " << myDeque.size() << std::endl;

	///////////// Access by Element
	std::cout << "Element 0: " << myDeque[0] << std::endl;
	std::cout << "Element 1: " << myDeque.at(1) << std::endl;


	///////////// Insertion/Deletion Operation
	// Not Recommended ,, Complex Operation that shift whole existing element in vector and
	// it will lead to multiple assignments/copies, especially with user-defined objects.
	myDeque.insert(myDeque.begin()+1, 0);
	printDeque();
	std::cout << "Deque Size: " << myDeque.size() << std::endl;
	myDeque.erase(myDeque.end()-3);
	printDeque();
	std::cout << "Deque Size: " << myDeque.size() << std::endl;
}


void _51_STL_Array_Vector_Deque() {

	//	_51_01_STL_Array();
//	_51_02_STL_Vector();
	_51_03_STL_Deque();

}
