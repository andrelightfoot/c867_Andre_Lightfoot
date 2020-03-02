#pragma once
#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student {

public:

	//Default constructor
	Student();
	//Constructor
	Student(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int days[]);
	 
	//Getters	
	std::string getID();
	std::string getFN();
	std::string getLN();
	std::string getemail();
	int getAge();
	int* getDays();
	virtual DegreeType getDegreeType() = 0;

	//Setters
	void setID(std::string ID);
	void setFN(std::string firstName);
	void setLN(std::string lastName);
	void setEmail(std::string email);
	void setAge(int age);
	void setDays(int days[]);

	virtual void print() = 0;
	
	const static int studentArraySize = 3;

	//Deconstructor
	~Student();
	
protected:
	std::string studentID;
	std::string FN;
	std::string LN;
	std::string studentEmail;
	int age;
	int days[studentArraySize];
	DegreeType dtype;
};