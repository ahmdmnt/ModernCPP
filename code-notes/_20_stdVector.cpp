/*
 * _20_stdVector.cpp
 *
 *  Created on: May 6, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <vector>

/* Module Description:-
 * ---------------------
 * 	1.
 *
 */

void printVector(std::vector<int>& l_vect) {
	std::cout << "myVector: ";
	for(auto element: l_vect) {
		std::cout << element << " ";
	}
	std::cout<< std::endl;
}


void _20_stdVector(void) {

	/* Std::Vector:-
	 * --------------
	 */
	std::vector<int> myVector {1, 2, 3, 4};		// Initialized using initializer_list

	/* Extend Vector size dynamically, without use handling */
	for(int idx=0; idx<20; ++idx) {
		myVector.push_back(idx*10);
	}

	/* Access Elements */
	myVector[0] = 1200;
	myVector.at(1) = 1300;

	/* Print out Data */
	printVector(myVector);

	/* Iterators */
	auto it = myVector.begin();
	std::cout<< *it << std::endl;
	it++;
	std::cout<< *it << std::endl;
	it+=3;
	std::cout<< *it << std::endl;

	/* Erase Element by Iterator */
	printVector(myVector);
	myVector.erase(myVector.begin());
	printVector(myVector);
	myVector.erase(it);
	printVector(myVector);

	/* Insert Element by Iterator */
	myVector.insert(myVector.end(), 444);
	printVector(myVector);

}

