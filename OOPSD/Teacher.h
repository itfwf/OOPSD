#pragma once
#include<string>
#include "People.h"
#include<fstream>
using namespace std;
class Teacher :public People
{
private:

public :
	Teacher(string fn, string ln);
	friend ostream& operator<<(ostream& os, const Teacher* d);
};

