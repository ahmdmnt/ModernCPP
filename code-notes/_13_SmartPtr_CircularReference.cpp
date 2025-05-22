/*
 * _13_SmartPtr_CircularReference.cpp
 *
 *  Created on: Apr 30, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>
#include <vector>

/* Module Description:-
 * ---------------------
 * 	1. Circular Reference.
 *	2. Solution: Weak Pointer
 */

class projectClass;

class employeeClass {
	std::string m_Name {};
	std::weak_ptr<projectClass> m_Project;
	// THIS IS IMPORTANT, because if m_Project was shared_ptr circular ref. issue will occurs.
	// when weak_ptr is used, m_Project is not counted in shared_ptr ref count.
	// BUT STILL CAN BE USED.

public:
	employeeClass(std::string l_name) {
		m_Name = l_name;
		std::cout << "employeeClass()" << std::endl;
	}
	~employeeClass() {
		std::cout << "~employeeClass()" << std::endl;
	}
	void setProject(const std::shared_ptr<projectClass>& l_proj) {
		m_Project = l_proj;
	}
	std::string getName() {
		return m_Name;
	}
	void showInfo() {
		if(m_Project.expired()) {
			std::cout<< "Resource not valid anymore!" << std::endl;
			return;
		}
		auto shaPtrLock = m_Project.lock();
		// DO WHATEVER YOU WANT
		return;
	}
};
class projectClass {
	std::string m_Name {};
	std::vector<std::shared_ptr<employeeClass>> m_EmployeeList;
public:
	projectClass(std::string l_name) {
		m_Name = l_name;
		std::cout << "projectClass()" << std::endl;
	}
	~projectClass() {
		std::cout << "~projectClass()" << std::endl;
	}
	void setEmployee(const std::shared_ptr<employeeClass>& l_emp) {
		m_EmployeeList.push_back(l_emp);
	}
	void showInfo() {
		std::cout<< "Project: " << m_Name << std::endl;
		for(auto& employee: m_EmployeeList) {
			std::cout<< "  - Employee: " << employee->getName() << std::endl;
		}
	}
	void showEmployeeCount() {
		std::cout<< "  Total Count: " << m_EmployeeList.size() << std::endl;
	}
};


void _13_SmartPtr_CircularReference() {
	std::shared_ptr<employeeClass> emp001 {new employeeClass{"Ahmed"}};
	std::shared_ptr<employeeClass> emp002 {new employeeClass{"Mohamed"}};
	std::shared_ptr<projectClass>  proj01 {new projectClass{"JLR ADAS Project"} };

	emp001->setProject(proj01);
	emp002->setProject(proj01);

	proj01->setEmployee(emp001);
	proj01->setEmployee(emp002);

	proj01->showInfo();
	proj01->showEmployeeCount();

	emp002->showInfo();

	/* Normally, Destructor is not invoked, because of Circular Reference.
	 * --------------------------------------------------------------------
	 * Both Object are pointing to each other, and because shared_ptr is used.
	 * Pointer/Resource will not be released.
	 * - Created Object is deleted successful
	 * but, each object have reference to the other object which is not being deleted,
	 * because they are dependent to each other.
	 * [[SOLUTION]]: weak_ptr is used.
	 * either in empolyee or project according to SW...
	 */
}


