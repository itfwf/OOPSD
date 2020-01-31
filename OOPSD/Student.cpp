#include "Student.h"

Student::Student(string fn, string ln, int i=1): People(fn,ln)
{
	if (i < 1 || i>6)
		throw invalid_argument("Year must be between (1-6)");

	_year = i;
}

void Student::AddCourse(Course *c)
{
	if (find(_courses.begin(), _courses.end(), c) == _courses.end())
		_courses.push_back(c);
	else
		cout << "\n"<<c->GetName()<<" already added!!\n";
}

Student::~Student()
{
	for (auto& c : _courses)
		delete c;

	_courses.clear();
}

ostream& operator<<(ostream& os, const Student* d)
{
	if (!d)
		return os << "Student not found!";

	os << "First Name: " << d->GetFirstName()
		<< "\n" << "Last Name: " << d->GetLastName()
		<< "\n" << "Year: " << d->GetYear() << "\n"
		<< "Email: " << d->GetEmail() << "\n";

	os << "\nCourses:\n";
	for (auto& c : d->GetCourses()) {
		os << c->GetName() << ", ";
	}
	return os << "\n";
}


