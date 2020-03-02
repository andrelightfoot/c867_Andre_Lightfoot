#include <iostream>
#include "NetworkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent() :Student()
{
    dtype = NETWORKING;
}

NetworkStudent::NetworkStudent(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int* days, DegreeType degreetype)
    : Student(studentID, firstName, lastName, email, age, days)
{
    dtype = NETWORKING;
}

DegreeType NetworkStudent::getDegreeType() {
    return NETWORKING;
}

void NetworkStudent::print() {
    this->Student::print();
    cout << "NETWORKING" << "\n";
}

NetworkStudent::~NetworkStudent() {
    Student::~Student();
}