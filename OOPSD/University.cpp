#include "University.h"

const  string University::STUDENTS_FILE = "Data/students.txt";
const  string University::TEACHERS_FILE = "Data/teachers.txt";

University::University(){
}

void University::Init()
{
    _courses = {
        new Course("SCS1",6),
        new Course("SCS2",3),
        new Course("OOP",3),
        new Course("DE",4) 
    };
}

University& University::getInstance() {
	static University u;
	return u;
}
 int University::GetTotalStudents() {
     return _students.size();
 }
 int University::GetTotalTeachers() {
     return _teachers.size();
 }

 void University::AddStudent()
 {
     cout << "\nInserting a student\n";

     string fn, ln;
     int year;
     cout << "Enter first name: ";
     cin >> fn;
     cout << "Enter last name: ";
     cin >> ln;
     cout << "Enter year: ";
     cin >> year;
     _students.push_back(new Student(fn, ln, year));

     cout << "\n_____\n";
     cout << "Do you want to add courses?\n1: Yes\n0:No\n";
     int choise;
     cin >> choise;
     while (choise) {
         cout << "1: SCS1\n2: CS2\n3: OOP\n4: DE\n";
         cin >> choise;

         if (choise < 1 || choise>4)
             break;

         _students.back()->AddCourse(_courses[choise-1]);
     }

 }

 void University::AddStudent(string fn, string ln , int year)
 {
     _students.push_back(new Student(fn, ln, year));
 }

 void University::AddTeacher()
 {
     cout << "\nInserting a teacher\n";

     string fn, ln;
     cout << "Enter first name: ";
     cin >> fn;
     cout << "Enter last name: ";
     cin >> ln;
     _teachers.push_back(new Teacher(fn, ln));
 }

 void University::AddTeacher(string fn, string ln)
 {
     _teachers.push_back(new Teacher(fn, ln));
 }

 void University::SaveWork()
 {
     ofstream studentsFile(STUDENTS_FILE);
     ofstream teachersFile(TEACHERS_FILE);

     for (auto& student : _students)
         studentsFile <<
         student->GetFirstName() << " " <<
         student->GetLastName() << " " <<
         student->GetYear() << "\n";

     studentsFile.close();

     for (auto& teacher : _teachers)
         teachersFile << teacher->GetFirstName() << " " << teacher->GetLastName() << "\n";

     teachersFile.close();
 }

 void University::ReloadWork() {

     ifstream studentsFile(STUDENTS_FILE);
     ifstream teachersFile(TEACHERS_FILE);

     cout << "Reading students ..";
     string str;
     vector<string>strs;
     while (getline(studentsFile, str))
     {
         boost::split(strs, str, boost::is_any_of(" "));

         if (strs.size() != 3)
             throw exception("Error reading students file");
        
         AddStudent(strs[0], strs[1], stoi(strs[2]));
     }
     cout << "\nRestored: " << GetTotalStudents()<<" students";
     strs.clear();
     cout << "\nReading teachers ..";

     while (getline(teachersFile, str))
     {
         boost::split(strs, str, boost::is_any_of(" "));

         if (strs.size() != 2)
             throw exception("Error reading teachers file");

         AddTeacher(strs[0], strs[1]);
     }
     cout << "\nRestored: " << GetTotalTeachers() << " teachers\n";

 }

 Student* University::SearchStudent(string& name) const
 {
     for (auto& st : _students)     
         if (boost::algorithm::contains(st->GetFullName(), name))         
             return st;        
     
     return nullptr;
 }
 
 Teacher* University::SearchTeacher(string& name) const
 {
     for (auto& st : _teachers)     
         if (boost::algorithm::contains(st->GetFullName(), name))         
             return st;         
     
     return nullptr;
 }

 void University::PrintOptions() 
 {
     cout << "Welcome:\n";
     cout << "Your options:\n";
     cout << "Add a student: --> 1\n";
     cout << "Add a teacher: --> 2\n";
     cout << "Search a student: --> 3\n";
     cout << "Search a teacher: --> 4\n";
     cout << "Exit: --> PRESS ANY KEY\n";
     cout << "_______________\n\n";
 }

 University::~University()
 {
     cout << "\nI'm cleaning :D";

     for (auto& st : _students)
         delete st;

     _students.clear();

     for (auto& t : _teachers) 
         delete t;
     
     _teachers.clear();
 }

