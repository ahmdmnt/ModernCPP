/*
 * _03.3_CLASS_DATA.cpp
 *
 *  Created on: Apr 16, 2025
 *      Author: AhmedMontasser
 */

#include "_03.3_CLASS_DATA.hpp"

#include <iostream>


Data::Data(int n1, int n2): d1(n1), d2(n2) {
	std::cout << "Data() - Parameterized Constructor is invoked!" << std::endl;
};

void Data::setValue(int value) {
	d1 = value;
	d2 = value;
	std::cout << "d1=" << d1 << " - d2=" << d2 <<std::endl;
}
