#include "roster.h"
using std::cout;
using std::cerr;

Roster::Roster() {
	this->capactiy = 5;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->capactiy = capactiy;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
};

void Roster::parseThenAdd(string row)
{
	if (lastIndex < 10) {
		lastIndex++;
		DegreeType degreeType;
		if (row.substr(row.length() - 8, 8) == "SOFTWARE") degreeType = SOFTWARE;  
		//(6:05)
		else if (row.substr(row.length() - 7, 7) == "NETWORK") degreeType = NETWORKING; 

		else if (row.substr(row.length() - 8, 8) == "SECURITY") degreeType = SECURITY;
			
		else {
			cerr << "Invalid Roster Type!";
			exit(-1);
		}
		int rhs = row.find(",");
		string sID = row.substr(0, rhs);

		//read first name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sFName = row.substr(lhs, rhs - lhs);

		//read last name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sLName = row.substr(lhs, rhs - lhs);

		//read email
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string emailAddress = row.substr(lhs, rhs - lhs);

		//read age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));

		//read days
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs)); 

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

		add(sID, sFName, sLName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
	}
	else{
		cerr << "INVALID ROSTER ENTRY! EXITING NOW!\n";
		exit(-1);
	}
}
void Roster::add(string StudentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType dp)
{
	int studentDays[Student::studentArraySize];
	studentDays[0] = daysInCourse1;
	studentDays[1] = daysInCourse2;
	studentDays[2] = daysInCourse3;
	if (dp == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(StudentID, firstName, lastName, emailAddress, age, studentDays, dp);
	else if (dp == NETWORKING) classRosterArray[lastIndex] = new NetworkStudent(StudentID, firstName, lastName, emailAddress, age, studentDays, dp);
	else if (dp == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(StudentID, firstName, lastName, emailAddress, age, studentDays, dp);
};

void Roster::print_All() {
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}


bool Roster::remove(string ID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == ID) 
		{
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	return found;
}

void Roster::printAveragedaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID) 
		{
			found = true;
			int* d = classRosterArray[i]->getDays();
			cout << "Avg days in course " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; ++i) {
		string email = classRosterArray[i]->getemail();
		if ((email.find(" ") != string::npos) || ((email.find("@") == string::npos) || (email.find(".") == string::npos))) {
			cout << "Invalid Email: " << email << std::endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeType d)
{
	cout << "Printing " << degreeTypesStrings[d] << " student(s):\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeType() == d) this->classRosterArray[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}


int main()
{
	cout << "Scripting and Programming - Applications: C867\n" << "Written in C++11\n" << "Andre Lightfoot:#000987244\n" << std::endl << std::endl;
	int numStudents = 5;

	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Andre,Lightfoot,alight@wgu.edu,27,1,2,3,SOFTWARE" };

	Roster* ros = new Roster(numStudents);
	cout << "Parsing data and adding students...  \n";
	for (int i = 0; i < numStudents; i++)
	{
		ros->parseThenAdd(studentData[i]);
	}
	cout << "Displaying all students:\n";
	ros->print_All();

	cout << "Removing A3:\n";
	
	if (ros->remove("A3")) {
		ros->print_All();
		numStudents--;
	}
	else cout << "Student not found!\n";

	cout << "Removing A3:\n";
	if (ros->remove("A3")) ros->print_All();
	else cout << "Student with this ID was not found.\n";

	cout << "Printing avergae days in courses:\n";
	for (int i = 0; i < numStudents; i++) {
		ros->printAveragedaysInCourse(ros->getStudentAt(i)->getID());
	}
	ros->printInvalidEmails();

	ros->printByDegreeProgram(SOFTWARE);

	system("pause");
	return 0;

}