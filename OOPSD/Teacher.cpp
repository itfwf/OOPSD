#include "Teacher.h"

Teacher::Teacher(string fn, string ln): People(fn,ln)
{
}

ostream& operator<<(ostream& out, const Teacher* d)
{
	out << "Teacher: \n";
	out << "First Name: " << d->GetFirstName();
	out << "\nLast Name: " << d->GetLastName();
	out << "____\n";
	return out;
}




