/*
 * _55_STL_UnorderedContainers_HashFunction.cpp
 *
 *  Created on: May 26, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <unordered_set>
#include <unordered_map>


/****************************************************************************************
 * Unordered Containers:
 * ------------------------
 * - Associative Containers that are implemented as hash tables.
 * - Values are hashed, The Hash act like a key when it is stored in a container.
 * - Elements are stored in undefined order.
 * - FAST in Search/Insertion/Deletion, but it will degrade over period of time.
 * - std::unordered_set
 * 	 Store Values that act as key for hashing.
 * - std::unordered_map:
 *   Store Pairs, first is used to compute the Hash.
 * - Iterators are constant, values are not modifiable.
 */

void _55_01_STL_UnorderedSet() {
	//////////// Create Unordered set
//	std::unordered_set<std::string> myUnordSet {"ClassA", "ClassB", "ClassC", "ClassC"};			// UnOrdered Set.
	std::unordered_multiset<std::string> myUnordSet {"ClassA", "ClassB", "ClassC", "ClassC"};		// UnOrdered MultiSet.

	//////////// Insert an Element
	myUnordSet.insert("ClassD");

	//////////// Use of Iterators
	for(auto element: myUnordSet)
		std::cout << "Bucket #" << myUnordSet.bucket(element) << ", contains: " << element << std::endl;
	// NOTE:
	// If more than one element in same bucket, that will degrade the performance of Set operations.

	//////////// Check Allocation: if Elements > Bucket ... reallocation of buckets will occur.
	std::cout << "Bucket Count: " << myUnordSet.bucket_count() << std::endl;		// Total Available Buckets.
	std::cout << "Number of Elements: " << myUnordSet.size() << std::endl;			// Actual Bucket Allocation.
	std::cout << "Load Factor: " << myUnordSet.load_factor() << std::endl;			// Factor Buckets/Elements
	// NOTE:
	// If reallocation of buckets occurs, WHOLE ELEMENTS will be rehashed.
	myUnordSet.insert("ClassE");myUnordSet.insert("ClassF");myUnordSet.insert("ClassG");myUnordSet.insert("ClassH");myUnordSet.insert("ClassI");
	myUnordSet.insert("ClassD");myUnordSet.insert("ClassD");myUnordSet.insert("ClassD");myUnordSet.insert("ClassD");myUnordSet.insert("ClassD");

	for(auto element: myUnordSet)
		std::cout << "Bucket #" << myUnordSet.bucket(element) << ", contains: " << element << std::endl;
}

void _55_02_STL_UnorderedMap() {
	//////////// Create Unordered Map
//	std::unordered_map<std::string, std::string> myUnordMap {				// UnOrdered Map.
//		{"1", "ClassA"},
//		{"2", "ClassB"},
//		{"3", "ClassC"},
//		{"4", "ClassD"},
//	};
	std::unordered_multimap<std::string, std::string> myUnordMap {				// UnOrdered Multi Map.
		{"1", "ClassA"},
		{"2", "ClassB"},
		{"3", "ClassC"},
		{"4", "ClassD"},
	};


	//////////// Insert an Element
	myUnordMap.insert(std::make_pair("1", "ClassA"));

	//////////// Use of Iterators
	for(auto element: myUnordMap)
		std::cout << "Bucket #" << myUnordMap.bucket(element.first) << " {" << element.first << ": " << element.second << "}" << std::endl;
	// NOTE:
	// If more than one element in same bucket, that will degrade the performance of Set operations.

	//////////// Check Allocation: if Elements > Bucket ... reallocation of buckets will occur.
	std::cout << "Bucket Count: " << myUnordMap.bucket_count() << std::endl;		// Total Available Buckets.
	std::cout << "Number of Elements: " << myUnordMap.size() << std::endl;			// Actual Bucket Allocation.
	std::cout << "Load Factor: " << myUnordMap.load_factor() << std::endl;			// Factor Buckets/Elements

}

void _55_03_STL_CustomizedHashFunction() {
	std::hash<std::string> myHash;
	std::cout << "Hash: " << myHash("Hello") << std::endl;


}

class employee {
	std::string mName;
	int mId;
public:
	employee(const std::string& name, const int& id): mName(name), mId(id) {}
	const std::string& getName() const {return mName;}
	const int& getId() const {return mId;}
};

struct employeeHash {

	/// BEST PRACTICE: Use Hash Combine functions from boot.org

	size_t operator()(const employee& emp) const {
		auto s1 = std::hash<std::string>{}(emp.getName());
		auto s2 = std::hash<int>{}(emp.getId());
		return s1^s2;
	}
};
struct employeeEquality {

	/// BEST PRACTICE: Check Equality for all attributes used in Hash Function.

	bool operator()(const employee& e1, const employee& e2) const {
		return ((e1.getId()==e2.getId())&&(e1.getName()==e2.getName()));
	}
};

void _55_STL_UnorderedContainers_HashFunction() {

//	_55_01_STL_UnorderedSet();
//	_55_02_STL_UnorderedMap();
//	_55_03_STL_CustomizedHashFunction();

	/// From Created Class/FunctionObject of Hash and Equality .. Create an unordered set.
	std::unordered_set<employee, employeeHash, employeeEquality> myEmployeeSet;

	myEmployeeSet.insert(employee{"Ahmed", 123});
	myEmployeeSet.insert(employee{"Karim", 124});
	myEmployeeSet.insert(employee{"Asser", 125});

	for(const auto& empElement: myEmployeeSet) {
		std::cout << empElement.getId() << ": " << empElement.getName() << std::endl;
	}
}


