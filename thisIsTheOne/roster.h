#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"

//Roster sotres collection on Students
class Roster {
private:
	int lastIndex;
	int capactiy;
	Student** classRosterArray;

public:
	Roster();
	Roster(int capactiy);

	Student* getStudentAt(int index);
	void parseThenAdd(string row);
	void add(string StudentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType dp);
	void print_All();
	void printAveragedaysInCourse(string studentID); 
	bool remove(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeType d) ;
	~Roster();
};