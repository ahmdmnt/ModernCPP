/*
 * _46_Lambda_CaptureList.cpp
 *
 *  Created on: May 22, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Module Description:-
 * ---------------------
 * 	1. Advantage of Lambda Expression:
 * 	- Easier and readable, SW code is directly beside desired usage.
 *
 * 	2. Capture List.
 * 	- What Does it mean?
 * 	- Copy of Original Variable.
 * 	- Mutable Keyword.
 *	- Capture by Reference, Value and Class Members.
 *	- Class Method with Lambda Expression and Capture List [this].
 *	- NESTED LAMBDA EXPRESSION.
 *	- Use of Lambda Expression as Callback.
 *	- Lambda Expression composition as FunctionPointer.
 *	Lambda will be decomposed as functionPointer because it has empty capture list.
 *
 *	NOTE::::
 *	:::::::: IMPORTANT
 *  So, when you use a lambda inside an expression that requires a function pointer, the type conversion
 *  operator of the lambda expression automatically converts the lambda into a function pointer.
 *  So, this is how it works.
 *  >>> expression should not have any capture list.
 *  >>> If it has a capture list, then the type conversion operator is not provided.
 */


/* Template to Perform generic SORT PROCESS for an ARRAY */
template<typename arrayType__, int SIZE, typename cmpFuObj>
void sortArray(arrayType__ (&arrVariable)[SIZE], cmpFuObj cmpFunction) {
	for( auto mainItr{0}; mainItr<SIZE-1; ++mainItr ) {
		for( auto cmpItr{0}; cmpItr<SIZE-1; ++cmpItr ) {
			if( cmpFunction(arrVariable[cmpItr], arrVariable[cmpItr+1]) ) {		// Here is a callback occurs to the Function Pointer.
				arrayType__ tempElement = std::move(arrVariable[cmpItr]);
				arrVariable[cmpItr]     = std::move(arrVariable[cmpItr+1]);
				arrVariable[cmpItr+1]   = std::move(tempElement);
			}
		}
	}
}

/* Template to Perform specific generic OPERATION on Each Element in ARRAY */
template<typename arrayType__, int SIZE, typename callbackType>
void forEach(arrayType__ (&arrVariable)[SIZE], callbackType cbkOperationFu) {
	for( auto itr{0}; itr<SIZE; ++itr ) {
		cbkOperationFu(arrVariable[itr]);
	}
}

/* Product Class */
class product {
	std::string name;
	double basePrice;
	double totalPrice;
public:
	product(const std::string& l_name, const double& l_price): name(l_name), basePrice(l_price), totalPrice(l_price) {
	}
	void assignFinalPrice() {
		double taxes[3] {12, 14, 3};
		forEach<double>(taxes, [this](double tax) {
			double taxedPrice = basePrice*tax/100;
			totalPrice += taxedPrice;
		});
	}
	double getTotalPrice() const {
		return totalPrice;
	}
	double getBasePrice() const {
		return basePrice;
	}
};

void _46_Lambda_CaptureList() {

	int intArray[10]  { 10, 4, 2, 3, 5, 8, 1000, -1, 23, 98};

	/* Check Array:-
	 * Easier Impl. by LambdaExpression instead of Normal For Loop */
	forEach<int>(intArray, [](auto& element) {
		std::cout << element << " ";
	});
	std::cout<< std::endl;

	/* Call Sort Function - and i can pass directly Lambda Expression code, instead of defining Function with FunctionPointer or defining FunctionObject */
	sortArray<int>(intArray, [](auto num1, auto num2) {
		return num1>num2;		// Ascending
	});

	/* Check Sorted Array */
	forEach<int>(intArray, [](auto& element) {
		std::cout << element << " ";
	});
	std::cout<< std::endl;


	/* CAPTURE LIST */
	// After Sorting, multiply a number offset to all elements
	int offset {10};
	forEach<int>(intArray, [offset](auto& element) /*mutable*/ {	// offset is not visible in Lambda Expression, in order to make it visible we can use Capture List.
		//offset += 1;			// error: assignment of read-only variable 'offset'
		element *= offset;		// Offset in Lambda is a Copy from original offset outside "CAN NOT BE MODIFIED".
								// Because by Default the FunctionCall OperatorOverloading is const function.
								// to make it modifiable i need to use mutable Keyword.
		std::cout << element << " ";
	});
	std::cout<< std::endl;

	/* I Can use also Capture list as Pass by Reference */
	auto sum {0};
	forEach<int>(intArray, [&sum, offset](auto& element) {
		sum = sum+element+offset;
	});
	std::cout << "sum:" << sum << std::endl;		// Here the Sum is updated, values updated inside lambda expression.

	// CAPTURE ALL Variable in inclosing SCOPE BY Reference, before Lambda Definition [&]:
	[&](auto& element) {
		sum = sum+element+offset;
	};
	// CAPTURE ALL Variable in inclosing SCOPE BY VALUE, before Lambda Definition [=]:
	[=](auto& element) {
		sum = sum+element+offset;
	};
	// CAPTURE ALL Variable in inclosing SCOPE BY VALUE, except sum by Reference:
	[=, &sum](auto& element) {
		sum = sum+element+offset;
	};
	// IMPORTANT:: CAPTURE ALL Member in inclosing Class, [this, others]:
	product myProduct("Circular Saw", 1200);
	if(myProduct.getTotalPrice() == myProduct.getBasePrice()) {
		myProduct.assignFinalPrice();
	}
	std::cout << "Total Price: " << myProduct.getTotalPrice() << std::endl;

}

