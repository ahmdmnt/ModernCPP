/*
 * _22_OOP_Composition_Inheritance.cpp
 *
 *  Created on: May 9, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Module Description:-
 * ---------------------
 * 	1. Composition.
 *	2. Inheritance.
 *	3. Access Modifiers.
 */

class Animal {
public:
	Animal() {std::cout << "> Animal() Instantiation" << std::endl;}
	void Eat(std::string type="Animal") {
		std::cout << type << " eating..." << std::endl;
	}
	void Run(std::string type="Animal") {
		std::cout << type << " running..." << std::endl;
	}
	void Speak(std::string type="Animal") {
		std::cout << type << " speaking..." << std::endl;
	}
};
class Dog : public Animal {
public:
	Dog() {std::cout << "> Dog() Instantiation" << std::endl;}
	void Run() {
		std::cout << "THE DOG IS RUNNING..." << std::endl;
	}
	void Serve(std::string type="Dog") {
		std::cout << type << " serving..." << std::endl;
	}
};

/* Access Modifiers:-
 * -------------------
 * - PRIVATE	: Members are inaccessible.
 * - PROTECTED	: Members are accessible for CHILD classes only.
 * - PUBLIC		: Members are accessible.
 * ---------------------------------------------------------------------------
 * class Base {					| class Child : <ACCESS_MODIFIER> Base {
 * private:						| private:
 * 	  Member A;					|     Member A;
 * protected:					| protected:
 * 	  Member B;					|    Member B;
 * public:						| public:
 * 	  Member C;					|    Member C;
 * }							| }
 *----------------------------------------------------------------------------
 * <ACCESS_MODIFIER>:
 * 		- class Child : public Base {			[PREFERABLE]
 * 			Base Members will be inherited as [their original] Access.
 * 			> Public	: will be accessible as public.
 * 			> Protected	: will be accessible as protected.
 * 			> Private	: will not be accessible in child class, even though it is inherited.
 *
 * 		- class Child : protected Base {
 * 			Base Members will be inherited as [protected] Access.
 * 			> Public 	: will be accessible as protected.
 * 			> Protected : will be accessible as protected.
 * 			> Private 	: will not be accessible in child class, even though it is inherited. << IMPORTANT Note.
 *
 * 		- class Child : private Base {
 * 			Base Members will be inherited as [private] Access.
 * 			> Public 	: will be accessible as private.
 * 			> Protected : will be accessible as private.
 * 			> Private 	: will not be accessible in child class, even though it is inherited.
 *
 * 	If <ACCESS_MODIFIER> is not mentioned at all, it will be same as Child Class,
 * 	if child is struct; inheritance will be public, -- if child is class; inheritance will be private.
 *
 * Object Construction in Inheritance:-
 * -------------------------------------
 * When Instance of child is created.
 *  > The Constructor will be executed; from Base to Child ...
 *  > The Destructor will be executed; from Child to Base ...
 */


void _22_OOP_Composition_Inheritance() {
	/*
	 * Composition:-
	 * --------------
	 * - Object is composed in another Object.
	 * - Represent of it "has relation" with other object.
	 * - Reuse behavior; the Out-Object can use behavior of In-Object "ex. Car/Engine relation".
	 *
	 * Inheritance:-
	 * --------------
	 * - Class can inherit feature of another class.
	 * - Parent and Child relation, which lead to reuse and inherit behavior.
	 * - Child can inherit and reuse features of a Parent. "ex. Parent: Animal, Child: Cat".
	 */

	Animal myAnimal;
	myAnimal.Eat();					// use class methods, with default values.
	myAnimal.Run("myAnimal");		// use class methods.

	std::cout << std::endl << std::endl;

	Dog myDog;
	myDog.Eat();					// use Parent class methods, with default values.
	myDog.Eat("Dog");				// use Parent class methods.
	myDog.Run();					// Hide the Animal Run and use Dog Run.
	myDog.Serve();					// use Child-own class methods.

}

