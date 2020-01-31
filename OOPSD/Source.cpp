#include<iostream>
#include "University.h"
#include "Source.h"

using namespace std;

int main() {
	int choise;
	bool isRunning = true;
	string name;

	University& u=University::getInstance();
	u.Init();
	u.PrintOptions();
	u.ReloadWork();

	while (isRunning)
	{
		cout << "\nEnter a number: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			u.AddStudent();
			break;	
		case 2:
			u.AddTeacher();
			break;
		case 3:
		{
			cin >> name;
			cout<< u.SearchStudent(name);
			break;
		}
		case 4:
		{
			cin >> name;
			cout << u.SearchTeacher(name);
			break;
		}
		default:
			cout << "\nSaving work ...";
			u.SaveWork();
			isRunning = false;
			break;
		}
	}

	return 0;
}