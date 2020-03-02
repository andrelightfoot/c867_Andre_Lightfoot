#include <iostream>
#include "SecurityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent() :Student()
{
    dtype = SECURITY;
}

SecurityStudent::SecurityStudent(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int* days, DegreeType degreetype)
    : Student(studentID, firstName, lastName, email, age, days)
{
    dtype = SECURITY;
}

DegreeType SecurityStudent::getDegreeType() {
    return SECURITY;
}

void SecurityStudent::print() {
    this->Student::print();
    cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent() {
    Student::~Student();
}