#pragma once
#include <string>
#include "student.h"

class SecurityStudent : public Student {

public:
	SecurityStudent();
	SecurityStudent(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int days[], DegreeType degreetype);

	//Virtual Method overloads
	DegreeType getDegreeType();
	void print();

	//Deconstructor
	~SecurityStudent();

};