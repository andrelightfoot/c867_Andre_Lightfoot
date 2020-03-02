#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent():Student()
{
    dtype = SOFTWARE; 
}

SoftwareStudent::SoftwareStudent(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int* days, DegreeType degreetype)
    : Student(studentID, firstName, lastName, email, age, days)
{
    dtype = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType() {
    return SOFTWARE;
}

void SoftwareStudent::print() {
    this->Student::print();
    cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent() {
    Student::~Student();
}