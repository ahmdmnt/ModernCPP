/*
 * _56_STL_Algorithms-P1.cpp
 *
 *  Created on: May 28, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

/* Algorithms - Part 01:
 * ----------------------
 * STL provides algorithms for common tasks, sort, remove, search, numeric, etc...
 *  - More Optimized than handwritten loops.
 *  - Works with all containers, regardless container datatype.
 *  - Can be customized with user-defined operations (Function Callback/Objects).
 *  - Some containers provide specialized version of algorithms.
 *  	- List  				 : sort, remove, etc..
 *  	- Associative Containers : lower_bound, upper_bound, find, etc..
 *  - #include <algorithm>
 */

class developer {
	int mId;
	std::string mName;
	std::string mProgrammingLanguage;
public:
	developer(const int& id, const std::string& name, const std::string& progLang):
		mId(id), mName(name), mProgrammingLanguage(progLang) {
	}
	const int& getId() const {
		return mId;
	}
	const std::string& getName() const {
		return mName;
	}
	const std::string& getProgrammingLanguage() const {
		return mProgrammingLanguage;
	}
	bool operator<(const developer& otherDev) {		// User-Defined LessThan Operator Overloading
		return this->mId < otherDev.mId;
	}
	bool operator>(const developer& otherDev) {		// User-Defined GreatersThan Operator Overloading
		return this->mId > otherDev.mId;
	}
	bool operator==(const developer& otherDev) {	// User-Defined Equality Operator Overloading
		return this->mProgrammingLanguage == otherDev.mProgrammingLanguage;
	}
};
/******************************************************************************************************/
void vectorExamples() {
	std::vector<developer> devList {
		developer{103, "Ahmed", "C++"},
		developer{101, "Asser", "C++"},
		developer{102, "Karim", "Python"},
		developer{105, "Aadam", "Java"},
		developer{104, "Zayed", "C++"}
	};
	auto printDevEntries = [&devList](){
		for(auto dev: devList)
			std::cout << dev.getId() << ": " << dev.getName() << " : " << dev.getProgrammingLanguage() << "    ";
		std::cout  << std::endl << std::endl;
	};
	printDevEntries();

	std::sort(devList.begin(), devList.end());		// By Default: it use less than operator ... we will define it in developer class
	printDevEntries();


	// What if i need to do sort with another criteria,,, i can use sort, with a predicate callback function.
	std::sort(devList.begin(), devList.end(), [](const auto& dev1, const auto& dev2) {
		return dev1.getName() < dev2.getName();
	});
	printDevEntries();


	// Count users that know C++
	//int countCppUsers = std::count(devList.begin(), devList.end(), developer{0, "", "C++"});		// OR, Better to use below
	std::string cppText {"C++"};
	auto countCppUsers = std::count_if(devList.begin(), devList.end(), [&cppText](const auto& dev){
		return dev.getProgrammingLanguage() == cppText;
	});
	std::cout << "countCppUsers= " << countCppUsers << std::endl;


	// Find user that know Java
	std::string javaText {"Java"};
	auto findJavaUser = std::find_if(devList.begin(), devList.end(), [&javaText](const auto& dev){
		return dev.getProgrammingLanguage() == javaText;
	});
	if(findJavaUser != devList.end())
		std::cout << "findJavaUser= " << findJavaUser->getName() << " is Java Developer." << std::endl;
	else
		std::cout << "Java Developer not found." << std::endl;


	// Display List Entries using for_each()
	std::for_each(devList.begin(), devList.end(), [](const auto& dev){
		std::cout << dev.getId() << ": " << dev.getName() << " : " << dev.getProgrammingLanguage() << "    ";
	});
	std::cout << std::endl;


	// get all IDs of C++ Developers
	std::vector<int> cppDevIds;
	std::for_each(devList.begin(), devList.end(), [&cppText, &cppDevIds](const auto& dev) {
		if(dev.getProgrammingLanguage() == cppText)
			cppDevIds.push_back(dev.getId());
	});
	std::cout << "CPP Developer(s) ID: ";
	std::for_each(cppDevIds.begin(), cppDevIds.end(), [](const auto& id){
		std::cout << id << "  ";
	});
	std::cout << std::endl;
}
/******************************************************************************************************/
struct devCompare {
	bool operator()(const developer& dev1, const developer& dev2) const {
		return dev1.getId() > dev2.getId();
	}
};
void setExamples() {
	std::set<developer, devCompare> devSet {		// Compare Function shall be passed to be able to sort set
		developer{103, "Ahmed", "C++"},
		developer{101, "Asser", "Ruby"},
		developer{102, "Karim", "Python"},
		developer{104, "Aalaa", "Java"}
	};
	auto printDevEntries = [&devSet](){
		for(auto dev: devSet)
			std::cout << dev.getId() << ": " << dev.getName() << " : " << dev.getProgrammingLanguage() << std::endl;
		std::cout  << std::endl;
	};
	printDevEntries();
}
/******************************************************************************************************/

void _56_STL_Algorithms() {

	vectorExamples();
	//	setExamples();

}

