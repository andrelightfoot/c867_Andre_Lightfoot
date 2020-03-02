#include<iostream>
#include<iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

//Empty constructor to sett all values
Student::Student() {
	this->studentID = "";
	this->FN = "";
	this->LN = "";
	this->studentEmail = "";
	this->age = 0;
	for (int i = 0; i < studentArraySize; i++) this->days[i] = 0;
};

//Full Constructor
Student::Student(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int days[]) {
	this->studentID = ID;
	this->FN = firstName;
	this->LN = lastName;
	this->studentEmail = email;
	this->age = age;
	for (int i = 0; i < studentArraySize; i++) this->days[i] = days[i];
}

//Getters!
std::string Student::getID()
{
	return studentID;
}
std::string Student::getFN()
{
	return FN;
}
std::string Student::getLN()
{
	return LN;
}
std::string Student::getemail()
{
	return studentEmail;
}
int Student::getAge()
{
	return age;
}
int* Student::getDays()
{
	return days;
};

//Setters 

void Student::setID(std::string ID)
{
	this->studentID = ID;
}
void Student::setFN(std::string firstName)
{
	this->FN = firstName;
}
void Student::setLN(std::string lastName)
{
	this->LN = lastName;
}
void Student::setEmail(std::string email)
{
	this->studentEmail = email;
}
void Student::setAge(int age)
{
	this->age = age;
}
void Student::setDays(int days[])
{
	for (int i = 0; i < studentArraySize; i++)
		this->days[i] = days[i];
};


//Print method displaying all fields except for book type
void Student::print()
{
	cout << left << setw(10) << studentID;
	cout << left << setw(10) << "First Name: " << setw(10) << FN;
	cout << left << setw(10) << "Last Name: " << setw(10) << LN;
	cout << left << setw(10) << "Email: " << setw(30)<<studentEmail;
	cout << left << setw(5) << "Age: " <<setw(10) << age;
	cout << left << setw(10)<< "daysInCourse: "<< setw(1) << "{" << days[0] << ", " << days[1] << ", " << days[2] <<setw(7)<< "}";
	cout << left << setw(1) << "Degree Program: ";
}
		


//{
//	cout << left << setw(5) << studentID;
//	cout << left << setw(10) << FN;
//	cout << left << setw(20) << LN;
//	cout << left << setw(30) << studentEmail;
//	cout << left << setw(10) << age;
//	cout << left << setw(10) << days[0];
//	cout << left << setw(10) << days[1];
//	cout << left << setw(10) << days[2];
//}

Student::~Student() {
};
