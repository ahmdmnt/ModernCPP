/*
 * _11_SharedPointer.cpp
 *
 *  Created on: Apr 30, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>
#include <memory>

/* Module Description:-
 * ---------------------
 * Shared Pointer
 *
 * 	1. Shared Pointer Example:
 * 	 We have a Project, the Project has list of Employees working in it.
 */

/* How to decide what to use?
 * First start thinking of using unique ptr, if it is not possible,
 * then use shared ptr.
 */

class project {
	std::string m_Name {"default"};
public:
	void setName(const std::string& l_name) {
		if( m_Name=="default" )
			m_Name = l_name;
		else
			std::cout << "ERR: Project name is already set!" << std::endl;
	}
	void showProjectDetails() const {
		std::cout<< "[Project Name]: " << m_Name << std::endl;
	}
};

class employee {
	std::shared_ptr<project> m_pProject {};			// use of shared_ptr<>()

public:
	void setProject(const std::shared_ptr<project>& l_project) {
		m_pProject = l_project;
	}
	const std::shared_ptr<project>& getProject() const {
		return m_pProject;
	}
};

void showEmployeeInfo(const std::unique_ptr<employee>& l_emp) {
	std::cout << "Employee Details: ";
	l_emp->getProject()->showProjectDetails();
}

void _11_SharedPointer(void) {

	std::shared_ptr<project> project102 {new project {}};
	project102->setName("Project_102");

	std::unique_ptr<employee> emp102_1 {new employee {}};
	emp102_1->setProject(project102);

	std::unique_ptr<employee> emp102_2 {new employee {}};
	emp102_2->setProject(project102);

	std::unique_ptr<employee> emp102_3 {new employee {}};
	emp102_3->setProject(project102);

	showEmployeeInfo(emp102_1);
	showEmployeeInfo(emp102_2);
	showEmployeeInfo(emp102_3);

	project102->showProjectDetails();

	std::cout<< "Check SharedPointer Copies: " << project102.use_count() << std::endl;
}
