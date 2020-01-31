#pragma once
#include <string>
#include "People.h"
#include "Course.h"
#include<vector>

using namespace std;
class Student :public People
{
private:	
	int _year;
	vector<Course*> _courses;

public:
	Student(string fn, string ln, int i);

	int GetYear()const { return _year; }
	void AddCourse(Course *cs);

	vector<Course*> GetCourses()const { return _courses; }
	friend ostream& operator<<(ostream& os, const Student* d) ;

	~Student();
};

 