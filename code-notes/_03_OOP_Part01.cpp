/*
 * _03_OOP_Part01.cpp
 *
 *  Created on: Apr 7, 2025
 *      Author: AhmedMontasser
 */

/*
 * Module Description:
 *	1. OOP Basics.
 *	2. Classes and Structures.
 *	3. Constructors Types and Destructor.
 *	4. Non-Static Data Initializers C++11.
 *	5. Keyword "this" Pointer.
 *	6. Static Members.
 *		6.1. Static Member Variables.
 *		6.2. Static Member Functions.
 *	7. Constant Member Functions.
 *	--------------------------------
 *	8. Copy Constructor.
 *	9. RULE OF 3 :: [[IMPORTANT]].
 *	10. Compiler Optimization: (RVO) return value optimization _OR_ copy elision.
 *	11. Copy Assignment Operator.
 *	12. Member Initialization List.
 *	--------------------------------
 *	13. Default Function.
 *	14. Delete Function.
 */

#include <iostream>

#include "_03_OOP_CLASSES/_03.1_CLASS_Car.hpp"				// TOPICS: 1/2/3/4/5/6/7
#include "_03_OOP_CLASSES/_03.2_CLASS_HeapInteger.hpp"		// TOPICS: 8/9/10/11/12
#include "_03_OOP_CLASSES/_03.3_CLASS_DATA.hpp"				// TOPICS: 13/14

#define ENABLE_CLASS_CAR				true	// TOPICS: 1/2/3/4/5/6/7
#define ENABLE_CLASS_HEAP_INTEGER		true	// TOPICS: 8/9/10/11/12
#define ENABLE_CLASS_DATA				true	// TOPICS: 13/14

HeapInteger sumHeapInteger(int num1, int num2);
void localPrint(HeapInteger data);

/* Structure:-
 * ------------
 * 	- Create user-defined type through keyword struct.
 * 	- Similar to Class, except by default all Members are public, except if it is mentioned explicitly to private.
 *	- For creating simple abstract types, for e.g. if all member are public access.
 *
 */
struct Point {
	int x_axis;
	int y_axis;

	void DrawLine(Point pStart, Point pEnd) {
		std::cout<< "Start = (" << pStart.x_axis << "," << pStart.y_axis << ")" << std::endl;
		std::cout<< "  End = (" << pEnd.x_axis << "," << pEnd.y_axis << ")" << std::endl;
	}
};
void DrawLine(Point pStart, Point pEnd) {
	std::cout<< "Start = (" << pStart.x_axis << "," << pStart.y_axis << ")" << std::endl;
	std::cout<< "  End = (" << pEnd.x_axis << "," << pEnd.y_axis << ")" << std::endl;
}

void _03_OOP_Part01(void) {

	/* Object Oriented Programming:-
	 * ------------------------------
	 * Objects are the fundamental building blocks rather than the Code Algorithm
	 * 	- Program is created as a collection of Objects.
	 * 	- Every Object is an instance of a Class.
	 * 		> Classes are blueprints for creating objects. An object is an instance of a class.
	 * 	- OOP simulate interaction between Objects.
	 * 	- Make code more reusable, extensible, and maintainable.
	 * 	------------------------------------------------------------------------------------
	 * 	- Basic Principles to write OO Programs:-
	 * 	------------------------------------------
	 * 		- Abstraction:
	 * 		Hiding the complex implementation details and showing only the essential features.
	 * 		Example: CoffeeMachine class might have a method makeEspresso();
	 * 		users don’t need to know how it heats water or grinds coffee beans internally.
	 * 			- Represent real-life objects in software, without the associated complexity.
	 * 			- Represented through class, struct, interface, union and enum.
	 * 		--------------------------------------------------------------------------------
	 * 		- Encapsulation:
	 * 		Bundling data and methods together while restricting direct access to some components.
	 * 		Example: A BankAccount class may have private attributes like balance
	 * 		and public methods like deposit() and withdraw(), ensuring balance can’t be directly modified.
	 * 			- Hide Implementation details of a class.
	 * 			- Class provide behavior without revealing the implementation.
	 * 			- This Implementation can be changed, without user knowledge.
	 * 		--------------------------------------------------------------------------------
	 * 		- Inheritance:
	 * 		Enabling one class (child) to inherit properties and methods from another class (parent).
	 * 		Example: A Dog class might inherit from an Animal class, where Animal defines attributes like name and age,
	 * 		and Dog adds methods like bark().
	 * 			- Represent a hierarchy of classes, where classes are related to each other.
	 * 			- This relation is due to some basic behavior of the classes.
	 * 			- Child class can use behavior of Parent Class.
	 * 			- Promotes reusability and extensibility.
	 * 		--------------------------------------------------------------------------------
	 * 		- Polymorphism:
	 * 		Allowing methods or objects to take many forms.
	 * 		Example: A Shape class might have a method area() that behaves differently for its subclasses Circle and Rectangle.
	 * 			- Used in conjunction with inheritance.
	 * 			- Represents common behavior with different implementations.
	 * 			- Responses will be different for each object: based on its class name or arguments.
	 * 				> e.g. car, cycle, person, etc.. all can move but in different way.
	 * 			- Polymorphism is applied through: Function overloading, Templates, Virtual functions.
	 * 			- Also, promotes reusability and extensibility.
	 *	------------------------------------------------------------------------------------
	 * 	- Class:-
	 * 	-----------------------------------
	 * 		- Blueprint, template, or recipe.
	 * 		- Represent an abstraction.
	 * 		- Class can have many Instances == Object (process called class instantiation).
	 *	------------------------------------------------------------------------------------
	 * 	- Basic Elements in Object/Class:-
	 * 	-----------------------------------
	 * 		- Methods: Functions defined inside a class and operate on its objects.
	 * 			> Car class might have a method startEngine().
	 * 		- Attributes: Variables associated with objects.
	 * 			> A Car object might have an attribute speed.
	 *	------------------------------------------------------------------------------------
	 */
	std::cout<< "CLASSES Section:- "<< std::endl << std::endl;

	if(ENABLE_CLASS_CAR)				// TOPICS: 1/2/3/4/5/6/7
	{
		Car::checkCarCount();			// Static Member Function - Call through Class Name

		//	Car carToyota;					// Invoke the Default constructor and set the Values with Non-Static Member Initializers
		Car carToyota(30, 2);			// Create Car Object/Instance from Class

		carToyota.carName = "Toyota";
		carToyota.fillFuel(27.3);		// Use Car Object Methods
		carToyota.releaseBrake();
		carToyota.calcAccelerate();
		carToyota.checkDashboard();

		Car carTemp(10,5);
		carToyota.comparePassengers(carTemp);

		carToyota.checkCarCount();		// Static Member Function - Call through Object Name

		Car constantCarObject;
		constantCarObject.checkCarCount();
		constantCarObject.checkDashboard();
		//	constantCarObject.fillFuel(10);		// Error can NOT invoke non-constant function
		std::cout<< std::endl << std::endl;


		/* COPY CONSTRUCTOR USAGE EXAMPLE:
		 * 1. Create new Object with existing object.
		 * 2. When Fu return of Object by value.
		 * 3. Pass the Object by Value; will create new copy of Object.
		 * 4. Assign Object with existing object.   */
		Car carObject1 {carToyota};						// #1 Copy Constructor invoked, Auto-generated by Compiler. // @suppress("Invalid arguments")
		std::cout<< "---------------------------------------------------------------------" << std::endl;
	}
	if(ENABLE_CLASS_HEAP_INTEGER)						// TOPICS: 8/9/10/11/12
	{
		HeapInteger intData1 {120};
		HeapInteger intData2 {intData1};				// #1 Copy Constructor invoked, user-defined. // @suppress("Invalid arguments")
		HeapInteger intData4 {sumHeapInteger(30,20)};	// #2 Copy Constructor invoked, user-defined. // @suppress("Invalid arguments")
		localPrint(intData4);							// #3 Copy Constructor invoked, user-defined.

		HeapInteger intData5;
		intData5 = intData1;							// #4 Copy Assignment Operator invoked, user-defined.
		localPrint(intData5);

		/* DELEGATING CONSTRUCOT EXAMPLE:
		 * 	- Here I am calling normally the Default Constructor.
		 * 	But when it is called, it will delegate to Parameterized.
		 */
		HeapInteger intData6;
		std::cout<< "---------------------------------------------------------------------" << std::endl;
	}
	if(ENABLE_CLASS_DATA)								// TOPICS: 13/14
	{
		Data myData1;
		Data myData2(10,20);

		//Data myData3 {myData1};			// error: use of deleted function 'Data::Data(const Data&)'

		myData1.setValue(10);
		//myData1.setValue(10.5f);			// error: use of deleted function 'void Data::setValue(float) -- because delete keyword.
		myData1.setValue(static_cast<int>(15.5f));		// Explicit casting is used.
		std::cout<< "---------------------------------------------------------------------" << std::endl;
	}
	/***********************************************************************************************************************************/
	/* Structure:-
	 * ------------
	 * 	- Create user-defined type through keyword struct.
	 * 	- Similar to Class, except by default all Members are public, except if it is mentioned explicitly to private.
	 *	- For creating simple abstract types, for e.g. if all member are public access.
	 *
	 */
	std::cout<< std::endl << "STRUCTURES Section:- "<< std::endl;
	Point Start {10,20};
	Point End {-10,-20};
	Start.DrawLine(Start, End);		// Either to add function in struct
	DrawLine(Start, End);			// or normally, simply implement them alone.
	/***********************************************************************************************************************************/
}

/* Example for Copy Constructor invoke, Object Pass by Value */
HeapInteger sumHeapInteger(int num1, int num2) {
	/* (RVO) return value optimization or copy elision:-
	 * ---------------------------------------------------
	 * C++ Will Perform Compiler Optimization named due to: RVO or Copy Elision
	 * 	When a function returns an object of the same class type, the compiler often skips the creation of a temporary object
	 * 	and directly constructs the returned object using the parameterized constructor.
	 * 		- copy elision:
	 * 			When a temporary object would normally be created, the compiler skips the creation of the temporary
	 * 			and directly constructs the object in its final location. This eliminates the need for a copy constructor.
	 * 		- (RVO) return value optimization:
	 * 			A specific case of copy elision that occurs, when returning a object by value from a function.
	 * 	 This optimization improves performance by reducing unnecessary copies.
	 *
	 * instead to disable this Compile Optimization:
	 * Explicitly create a temporary object before returning (might not work, and compiler may optmize also.
	 * and/or use "-fno-elide-constructors" flag in compiler */

//	return HeapInteger(num1+num2);
	HeapInteger temp(num1+num2);
	return temp;
}
void localPrint(HeapInteger data) {
	std::cout << "Data is equal to: " << data.getValue() << std::endl;
}

