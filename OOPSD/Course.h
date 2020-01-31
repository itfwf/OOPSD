#pragma once
#include<string>

using namespace std;
class Course
{
private:
    string _name;
    int _credits;

public:
    Course(string name, int credits);

    inline string GetName()const { return _name; }
};

