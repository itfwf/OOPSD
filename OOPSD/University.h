#pragma once
#include<vector>
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <string>
#include <sstream>
#include<boost/algorithm/string.hpp>

class University
{
private:
	const static string STUDENTS_FILE;
	const static string TEACHERS_FILE;

	vector<Student*> _students;
	vector<Teacher*> _teachers;
	vector<Course*>_courses;
	University(); // avoid create
	University(University const&); //avoid copy 

public:	
	void Init();

	static University& getInstance();
	int GetTotalStudents();
	int GetTotalTeachers();

	void AddStudent();
	void AddStudent(string, string, int);

	void AddTeacher();
	void AddTeacher(string, string);

	void SaveWork();//simulate saving on DB
	void ReloadWork(); //simulate reading from DB

	Student* SearchStudent(string& ) const;
	Teacher* SearchTeacher(string&) const;

	void PrintOptions();

	~University();//cleaning up
};

