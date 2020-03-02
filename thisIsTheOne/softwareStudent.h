#pragma once
#include <string>
#include "student.h"

class SoftwareStudent : public Student {

public:
	SoftwareStudent();
	SoftwareStudent(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int days[], DegreeType degreetype);
	 
	DegreeType getDegreeType();
	void print();

	//Deconstructor
	~SoftwareStudent();

};