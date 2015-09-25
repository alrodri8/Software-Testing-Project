//
//  main.cpp
//  Phase_1
//
//  Created by Humberto Salinas on 9/24/15.
//  Copyright (c) 2015 _Humberto Salinas_. All rights reserved.
//
#include <iostream>
#include <string>
#include <list>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Student class
class Student {
private:
	string UID;					// UID
	string Email;				// Email Address
	string Name;				// Full Name
	int Essay1_grade;	// Essay 1 Grade
	int Essay2_grade;	// Essay 2 Grade
	int Project_grade;	// Project Grade

public:
	// Class constructor
	Student(string uid, string email, string name, int essay1_grade, int essay2_grade, int project_grade)
	{
		UID = uid;
		Email = email;
		Name = name;
		Essay1_grade = essay1_grade;
		Essay2_grade = essay2_grade;
		Project_grade = project_grade;
	} // end constructor

	// Set UID
	void setUID(string uid)
	{
		UID = uid;
	}

	// Set Email
	void setEmail(string email)
	{
		Email = email;
	}

	// Set Name
	void setName(string name)
	{
		Name = name;
	}

	// Set Essay 1 Grade
	void setEssay1_Grade(int grade)
	{
		if (grade <= 4) {
			Essay1_grade = grade;
		}
	}

	// Set Essay 2 Grade
	void setEssay2_Grade(int grade)
	{
		if (grade <= 4) {
			Essay2_grade = grade;
		}
	}

	// Set Project Grade
	void setProject_Grade(int grade)
	{
		if (grade <= 4) {
			Project_grade = grade;
		}
	}

	// Get UID
	string getUID()
	{
		return UID;
	}

	// Get Email
	string getEmail()
	{
		return Email;
	}

	// Get Name
	string getName()
	{
		return Name;
	}

	// Get Essay 1 Grade
	int getEssay1_Grade()
	{
		return Essay1_grade;
	}

	// Get Essay 2 Grade
	int getEssay2_Grade()
	{
		return Essay2_grade;
	}

	// Get Project Grade
	int getProject_Grade()
	{
		return Project_grade;
	}
};
// end Student class.

// Search list of students for student with given text for Email, UID or Name.
// Returns null if none are found.
Student* find_student(list<Student>& students, string text)
{
	// Traverse entire list until student is found.
	for (list<Student>::iterator sPtr = students.begin(); sPtr != students.end(); ++sPtr)
	{
		if (sPtr->getEmail() == text || sPtr->getUID() == text || sPtr->getName() == text) {
			return &*sPtr;
		}
	}
	return NULL;		// Return null if no student is found.
}

void print_students(list<Student>& students)
{
	// Print each student on a line.
	for (list<Student>::iterator sPtr = students.begin(); sPtr != students.end(); ++sPtr)
	{
		cout << "UID: " << sPtr->getUID() << endl;
		cout << "Name: " << sPtr->getName() << endl;
		cout << "Email: " << sPtr->getEmail() << endl;
		cout << "Essay 1: " << sPtr->getEssay1_Grade() << endl;
		cout << "Essay 2: " << sPtr->getEssay2_Grade() << endl;
		cout << "Term Project: " << sPtr->getProject_Grade() << endl << endl;
	}
}

void add_student(list<Student>& students)
{
	string name = "";
	string UID = "";
	string email = "";
	int essay1 = 0, essay2 = 0, term = 0;

	string empty = "";
	getline(cin, empty);

	cout << "Enter Name: ";
	getline(cin, name);

	cout << "Enter UID: ";
	getline(cin, UID);

	cout << "Enter Email: ";
	getline(cin, email);

	cout << "Grade of Essay 1: \n";
	cin >> essay1;
	cout << "Grade of Essay 2: \n";
	cin >> essay2;
	cout << "Grade of Term project: \n";
	cin >> term;

	Student student = Student(UID, email, name, essay1, essay2, term);

	students.push_back(student);
}

void add_student_from_file(list<Student>& students, string tempId, string tempEmail, string tempName, int tempEssay1, int tempEssay2, int tempFinal)
{
	Student newStudent = Student(tempId, tempEmail, tempName, tempEssay1, tempEssay2, tempFinal);
	students.push_back(newStudent);
}

void remove_student(list<Student>& students)
{
	string UID;
	cout << "Which student would you like to remove? \n";
	cout << "Enter the UID of student you would like to remove: \n";
	cin >> UID;

	for (list<Student>::iterator sPtr = students.begin(); sPtr != students.end(); ++sPtr)
	{
		if (sPtr->getUID() == UID)
		{
			students.erase(sPtr);
			break;
		}
	}
}

void update_student(list<Student>& students)
{
	string text;
	int option;
	cout << "Enter the USF ID of the student you would like to update: \n";
	cin >> text;

	//Find Student with particular USF ID
	Student* one = find_student(students, text);

	if (one != NULL)
	{
		cout << "What field would you like to update? \n Enter a number to continue\n";
		cout << "0 - Essay 1 grade\n";
		cout << "1 - Essay 2 grade\n";
		cout << "2 - Term Project grade\n";
		cout << "3 - USF ID\n";
		cout << "4 - Name\n";
		cout << "5 - Email\n" << endl;

		cin >> option;
		do {
			switch (option) {
			case 0:
			{
				int grade;
				cout << "What is the new grade? ";
				cin >> grade;
				one->setEssay1_Grade(grade);
			}
			break;
			case 1:
			{
				int grade;
				cout << "What is the new grade? ";
				cin >> grade;
				one->setEssay2_Grade(grade);
			}
			break;
			case 2:
			{
				int grade;
				cout << "What is the new grade? ";
				cin >> grade;
				one->setProject_Grade(grade);
			}
			break;
			case 3:
			{
				string id;
				cout << "What is the new USF ID? ";
				cin >> id;
				one->setUID(id);
			}
			break;
			case 4:
			{
				string name;
				cout << "What is the new name? ";
				cin >> name;
				one->setName(name);
			}
			break;
			case 5:
			{
				string email;
				cout << "What is the new email? ";
				cin >> email;
				one->setEmail(email);
			}
			break;
			}

			cout << "What field would you like to update? \n Enter a number to continue\n";
			cout << "0 - Essay 1 grade\n";
			cout << "1 - Essay 2 grade\n";
			cout << "2 - Term Project grade\n";
			cout << "-1 - Exit updating \n" << endl;

			cin >> option;
		} while (option >= 0);
	}
	else
	{
		cout << "STUDENT NOT FOUND";
	}
}

// Main method ran on execution.
int main()
{
	int const MAX_STR = 9999;
	list<Student> students;
	string UID = "abc";

	Student S1("abs", "abc@", "humberto", 0, 0, 0); //List of students

	Student S2(UID, "abcd@", "hum", 0, 1, 2);

	students.push_back(S1);
	students.push_back(S2);

	FILE* inFile = NULL;
	inFile = fopen("student.txt", "r");

	// in case no input or output file existed
	if (inFile == NULL)
	{
		cout << "Could not open input.txt" << endl;
		return -1;
	}

	//Input students from file!!!
	Student newStudent();
	char str[MAX_STR];
	int count;
	int tempEssay1;
	int tempEssay2;
	int finalGrade;
	fgets(str, MAX_STR, inFile);
	sscanf(str, "%d", &count);
	fgets(str, MAX_STR, inFile);
	while (str != NULL && count > 0)
	{
		string tempId(str);
		tempId.erase(remove(tempId.begin(), tempId.end(), '\n'), tempId.end());
		
		fgets(str, MAX_STR, inFile);
		string tempName(str);
		tempName.erase(remove(tempName.begin(), tempName.end(), '\n'), tempName.end());
		
		fgets(str, MAX_STR, inFile);
		string tempEmail(str);
		tempEmail.erase(remove(tempEmail.begin(), tempEmail.end(), '\n'), tempEmail.end());

		fgets(str, MAX_STR, inFile);
		sscanf(str, "%d", &tempEssay1);
		
		fgets(str, MAX_STR, inFile);
		sscanf(str, "%d", &tempEssay2);

		fgets(str, MAX_STR, inFile);
		sscanf(str, "%d", &finalGrade);

		add_student_from_file(students, tempId, tempEmail, tempName, tempEssay1, tempEssay2, finalGrade);
		count--;
		fgets(str, MAX_STR, inFile);	//Skip blank lines
		fgets(str, MAX_STR, inFile);		
	}


	int option; // Variable for storing selected option

	cout << "Software Testing Class Roll\nEnter a number to continue\n";
	cout << "0 - Print Student Roll\n";
	cout << "1 - Add Student\n";
	cout << "2 - Delete Student\n";
	cout << "3 - Retrieve Student\n";
	cout << "4 - Update Student\n" << endl;

	cin >> option;

	do {
		switch (option) {
		case 0:
			print_students(students);
			break;
			// Add Student
		case 1:
			add_student(students);
			break;
			// Remove Student
		case 2:
			remove_student(students);
			break;
			// Retrieve Student
		case 3:
		{
			string text;
			cout << "Enter the UID, name, or email of student: ";
			cin >> text;
			Student* one = find_student(students, text);
			cout << "USF ID: " << one->getUID() << endl;
			cout << "Name: " << one->getName() << endl;
			cout << "Email: " << one->getEmail() << endl;
			cout << "Essay 1 Grade: " << one->getEssay1_Grade() << endl;
			cout << "Essay 2 Grade: " << one->getEssay2_Grade() << endl;
			cout << "Term Project Grade: " << one->getProject_Grade() << endl;
			cout << endl;
		}
		break;
		case 4:
			update_student(students);
			break;
		}

		cout << "Software Testing Class Roll\nEnter a number to continue\n";
		cout << "0 - Print Student Roll\n";
		cout << "1 - Add Student\n";
		cout << "2 - Delete Student\n";
		cout << "3 - Retrieve Student\n";
		cout << "4 - Update Student\n";
		cout << "Enter -1 to exit program and write info to file." << endl;

		cin >> option;

	} while (option >= 0);

	//output to file, overloading exisiting input file
	int totalStudent = 0;
	for (list<Student>::iterator count1 = students.begin(); count1 != students.end(); ++count1)
		++totalStudent;
	ofstream out("students.txt");
	out << totalStudent;
	out << '\n';
	for (list<Student>::iterator sPtr = students.begin(); sPtr != students.end(); ++sPtr)
	{
		out << sPtr->getUID();
		out << '\n';
		out << sPtr->getName();
		out << '\n';
		out << sPtr->getEmail();
		out << '\n';
		out << sPtr->getEssay1_Grade();
		out << '\n';
		out << sPtr->getEssay2_Grade();
		out << '\n';
		out << sPtr->getProject_Grade();
		out << '\n';
		out << '\n';
	}
	out.close();

	return 0;
}
