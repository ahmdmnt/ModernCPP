/*
 * _17_Strings.cpp
 *
 *  Created on: May 4, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <sstream>

/* Module Description:-
 * ---------------------
 * 	1. C-Style Strings.
 *	2. C++ Strings.
 */

void combineStr(const char* pFirst, const char* pLast, char* combinedString) {
	int i{0};
	while('\0' != pFirst[i]) {
		combinedString[i] = pFirst[i];
		++i;
	}
	combinedString[i] = ' ';
	++i;

	int j{0};
	while('\0' != pLast[j]) {
		combinedString[i] = pLast[j];
		++i;
		++j;
	}
	combinedString[i] = '\0';
}

void _17_Strings() {
	/* C-Style Strings - Static Memory Allocation */
	char firstName[10] {"Ahmed"};
	char  lastName[10] {"Montasser"};
	char fullName[40] {};
	combineStr(firstName, lastName, fullName);
	std::cout<< "Full Name: " << fullName << std::endl;

	/* C++ Strings */
	std::string myString {"Hi!"};
	myString = "hello!";
	myString[0] = 'H';
	std::cout << "myString: " << myString << std::endl;
	/* String Methods */

	std::cout << "Length: " << myString.length() << std::endl;

	myString  += "This is C++.";
	std::cout << "myString: " << myString << std::endl;

	myString.insert(6, " ");
	std::cout << "myString: " << myString << std::endl;		// Hello! This is C++.

	if(myString != "Hello")
		std::cout<< "String not equal to Hello" << std::endl;

	auto strPosition = myString.find("C++", 0);		// ("DESIRED_TXT, START_IDX)
	if (std::string::npos != strPosition)			// Make sure string is found
		std::cout << "strPosition: " << strPosition << std::endl;	// return index.

	printf("\nCONVERT TO RAW C-Style String: %s\n\n", myString.c_str());

	myString.erase(0, 3);	// Erase From > To.
	std::cout << "myString: " << myString << std::endl;
	myString.erase(6);		// Erase From > END
	std::cout << "myString: " << myString << std::endl;
	myString.erase();		// Erase All
	myString.clear();		// Erase All
	std::cout << "myString: " << myString << std::endl;


	/* String Stream:-
	 * ----------------
	 * 	- Performing operations on string buffer.
	 * 	- using different data types with strings.
	 */
	int num1{10}, num2{20};

	std::istringstream iss;		// Only Extraction Operation
	std::ostringstream oss;		// Only Insertion Operation
	std::stringstream   ss;		// Insertion and Extraction Operation

	ss << "Sum of value (" << num1 << ") and (" << num2 << ") is equal to ... " << num1+num2 << std::endl;		// Do Operations and Manage String buffer
	std::string outputString = ss.str();		// then we can access it through .str() function	"to read String Buffer"
	std::cout << "outputString: " << outputString;

	ss.str("");		// to write in string buffer -- here it is clear example because nothing is passed.
	outputString = ss.str();
	std::cout<< "outputString: " << outputString << std::endl;

	/* Convert into String */
	std::cout << std::to_string(num1+num1+num2) << std::endl;



	/* Extract Data from String */
	std::string date = "10 10 2025";
	int number{};

	ss.str(date);
	while( ss >> number ) {			// Extract Data, if no data available it will return fail, boolean > 0

		std::cout << ">" << number << std::endl;
	}

	int num__1 = std::stoi("23");		// from string to any other primitive Datatypes.1

}
