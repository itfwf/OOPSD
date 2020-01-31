#pragma once
#include<string>
#include <stdexcept>
#include<iostream>

using namespace std;
class People
{
private:
	string _firstName;
	string _lastName;
	string _email;

public:
	People(string fn, string ln);

	inline string GetFirstName() const { return _firstName; }
	inline string GetLastName() const { return _lastName; }
	inline string GetEmail() const { return _email; }
	inline string GetFullName() const { return _firstName + " " +_lastName; }

	};

