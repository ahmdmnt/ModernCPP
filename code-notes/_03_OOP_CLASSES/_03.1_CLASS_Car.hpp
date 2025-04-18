/*
 * _03.1_CLASS_Car.hpp
 *
 *  Created on: Apr 14, 2025
 *      Author: AhmedMontasser
 */

#ifndef _CLASS_Car_
#define _CLASS_Car_

/* CLASS.hpp File:-
 * -----------------
 * File where Class Declaration shall be available.
 */

#include <string>

class Car {
	/* By Default:
	 * Members are private */

private:	/* Private Member: Not visible outside Class */
	/* [C++11] Non-Static Data Member Initializer:-
	 * -------------------------------------
	 * 	- Convenient way to initialize class member, to make sure object always have valid values.
	 * 	- Available from C++11 only.
	 * 	- Can be used with any member type.
	 * 	- Compiler automatically generate initialization code.
	 * 	- [IMPORTANT] Also you have ability to Initialize with User-Defined constructor if needed.
	 *	- [LIMITATION]: auto keyword can't be used here, not allowed
	 */
	int passengers 	  {1};	//	Attributes
	int speed	      {0};
	bool brakeApplied {false};
	float fuel	      {0};
	//auto status {0};		//error: non-static data member declared with placeholder 'auto'

	static int totalCarCount;	// STATIC Member Variable.


public:		/* Public Member: Visible outside Class */
	std::string carName {"Default"};	// non-static data member
	Car();												/* Default Constructor */
	Car(int fuelAmmount, int passengerCount);			/* Parameterized Constructor */
	Car(const Car &refObj);								/* Copy Constructor * no implementation needed, because no Pointer or Heap Resources,
														 * just normal variable members auto-generated copy constructor is sufficient */
	~Car();												/* Destructor */

	void fillFuel(float amount);	// Methods
	void calcAccelerate();
	void applyBrake();
	void releaseBrake();
	void addPassenger(int count);
	void comparePassengers(const Car &otherCar);

	void checkDashboard() const;	// Constant Member Function

	static void checkCarCount();	// STATIC Member Function.
};

#endif /* _CLASS_Car_ */
