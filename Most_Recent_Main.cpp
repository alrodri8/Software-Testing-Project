//
//  main.cpp
//  Phase_1
//

#include <iostream>
#include <string>
#include <list>
#include <stdio.h>
#include <algorithm>
#include <fstream>

/*******************************************************************
   
   Add the line below if you want to compile in Visual Studios:
 
   #define _CRT_SECURE_NO_WARNINGS
 
********************************************************************/



using namespace std;

// Student class
class Student {
private:
	string UID;					// USF ID
	string Email;				// Email Address
	string Name;				// Full Name
	int Essay1_grade;       // Essay 1 Grade
	int Essay2_grade;       // Essay 2 Grade
	int Project_grade;      // Project Grade

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

	// Set USF ID
   void setUID(string uid)
   {
      string temp = uid;
      while (temp.length() < 10 && temp.length() > 10)
      {
         cout << “Your input is invalid, please enter only 10 characters of UID” << endl;
         cin >> temp;
      }	
      
      UID = temp; 	
   }

	// Set Email
   void setEmail(string email)
   {
      string temp = email;
      while (temp.length() <= 40 && temp.length() >= 0)
      {
         cout << “Your input is invalid, please enter only up to 40 characters of email” << endl;
         cin >> temp;
      }	
      
      Email = temp; 	
   }

	// Set Name
   void setName(string name)
   {
      string temp = name;
      while (temp.length() <= 40 && temp.length() >= 0)
      {
         cout << “Your input is invalid, please enter only up to 40 characters of name” << endl;
         cin >> temp;
      }	
      
      Name = temp; 	
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

	// Get USF ID
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
	return NULL; // Return null if no student is found.
}

//Print list of students currently in the class roll
void print_students(list<Student>& students)
{
	// Traverse the list
   // Print each student on a line
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

//Add a student to the clas roll
void add_student(list<Student>& students)
{
	string name = "";
	string UID = "";
	string email = "";
	int essay1 = 0, essay2 = 0, term = 0; //Initialize all variables

	string empty = "";
	getline(cin, empty);

	cout << "Enter Name: "; //Prompt User to enter name
	getline(cin, name);

	cout << "Enter UID: "; //Prompt User to enter USF ID
	getline(cin, UID);

	cout << "Enter Email: "; //Prompt User to enter email
	getline(cin, email);

	cout << "Grade of Essay 1(0 for F - 4 for A): \n"; //Prompt User to enter grade
	cin >> essay1;
	cout << "Grade of Essay 2(0 for F - 4 for A): \n";
	cin >> essay2;
	cout << "Grade of Term project(0 for F - 4 for A): \n";
	cin >> term;

	Student student = Student(UID, email, name, essay1, essay2, term); //Create student using Student constructor

	students.push_back(student); //Add list to the class roll list
}

// Add student from input file, as students are read in from student.txt file
// they are passed into this function to be added to the class roll
void add_student_from_file(list<Student>& students, string tempId, string tempEmail, string tempName, int tempEssay1, int tempEssay2, int tempFinal)
{
	Student newStudent = Student(tempId, tempEmail, tempName, tempEssay1, tempEssay2, tempFinal);
	students.push_back(newStudent);
}

// Remove a student from class roll list
void remove_student(list<Student>& students)
{
	string UID;
	cout << "Which student would you like to remove? \n"; //Prompt User to enter USF ID
	cout << "Enter the UID of student you would like to remove: \n";
	cin >> UID;

   //Traverse list until the entered USF matches a student's id in the list
	for (list<Student>::iterator sPtr = students.begin(); sPtr != students.end(); ++sPtr)
	{
		if (sPtr->getUID() == UID)
		{
			students.erase(sPtr); //Erase student from list if found
			break;
		}
	}
}

//Update any or all data fields of a student
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
		cout << "5 - Email\n" << endl; //Prompt the User to make a choice of field to update

		cin >> option;
		do {
			switch (option) {
			case 0:
			{
				int grade;
				cout << "What is the new grade? ";
				cin >> grade;
				one->setEssay1_Grade(grade); //Set new Essay 1 grade
			}
			break;
			case 1:
			{
				int grade;
				cout << "What is the new grade? ";
				cin >> grade;
				one->setEssay2_Grade(grade); //Set new Essay 2 grade
			}
			break;
			case 2:
			{
				int grade;
				cout << "What is the new grade? ";
				cin >> grade;
				one->setProject_Grade(grade); //Set new Project grade
			}
			break;
			case 3:
			{
				string id;
				cout << "What is the new USF ID? ";
				cin >> id;
				one->setUID(id); //Set new USF ID
			}
			break;
			case 4:
			{
				string name;
				cout << "What is the new name? ";
				cin >> name;
				one->setName(name); //Set new Name
			}
			break;
			case 5:
			{
				string email;
				cout << "What is the new email? ";
				cin >> email;
				one->setEmail(email); //Set new email
			}
			break;
			}
         
         cout << "What field would you like to update? \n Enter a number to continue\n";
         cout << "0 - Essay 1 grade\n";
         cout << "1 - Essay 2 grade\n";
         cout << "2 - Term Project grade\n";
         cout << "3 - USF ID\n";
         cout << "4 - Name\n";
         cout << "5 - Email\n";
         cout << "-1 - Exit updating \n" << endl; //Prompt user if he/she would like to cont. updating

			cin >> option;
		} while (option >= 0); //Continue to update fields until User enters -1 to exit
	}
	else
	{
		cout << "STUDENT NOT FOUND"; //Student is not found so display message
	}
}

// Main method ran on execution aka User Interface
int main()
{
	int const MAX_STR = 9999;
	list<Student> students;

	FILE* inFile = NULL;
	inFile = fopen("student.txt", "r"); //Open file to read in students

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
	while (str != NULL && count > 0) //Retrieve information
	{
		string tempId(str); //Get USF ID
		tempId.erase(remove(tempId.begin(), tempId.end(), '\n'), tempId.end());
		
		fgets(str, MAX_STR, inFile); //Get Name
		string tempName(str);
		tempName.erase(remove(tempName.begin(), tempName.end(), '\n'), tempName.end());
		
		fgets(str, MAX_STR, inFile); //Get Email
		string tempEmail(str);
		tempEmail.erase(remove(tempEmail.begin(), tempEmail.end(), '\n'), tempEmail.end());

		fgets(str, MAX_STR, inFile); //Get Essay 1
		sscanf(str, "%d", &tempEssay1);
		
		fgets(str, MAX_STR, inFile); //Get Essay 2
		sscanf(str, "%d", &tempEssay2);

		fgets(str, MAX_STR, inFile); //Get Project
		sscanf(str, "%d", &finalGrade);

		add_student_from_file(students, tempId, tempEmail, tempName, tempEssay1, tempEssay2, finalGrade); //Add student to list
		count--; //Decrease counter to eventually end while loop
		fgets(str, MAX_STR, inFile);	//Skip blank lines
		fgets(str, MAX_STR, inFile);		
	}
	fclose(inFile);

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
         //Retrieve Student
		}
		break;
		case 4:
			update_student(students);
			break;
         //Update Students
		}

      //Prompt User repetitively if he/she wants to make more adjustments to class roll
		cout << "Software Testing Class Roll\nEnter a number to continue\n";
		cout << "0 - Print Student Roll\n";
		cout << "1 - Add Student\n";
		cout << "2 - Delete Student\n";
		cout << "3 - Retrieve Student\n";
		cout << "4 - Update Student\n";
		cout << "Enter -1 to exit program and write info to file." << endl;

		cin >> option;

   } while (option >= 0);  //Continue to prompt user to enter option until User enters -1 to exit

	//output to file, overloading exisiting input file
	int totalStudent = 0;
	for (list<Student>::iterator count1 = students.begin(); count1 != students.end(); ++count1)
		++totalStudent;
	ofstream out("student.txt"); //Overwrite studen.txt file
	out << totalStudent; //Output number of students
	out << '\n';
	for (list<Student>::iterator sPtr = students.begin(); sPtr != students.end(); ++sPtr)
	{
		out << sPtr->getUID(); //Output USF ID
		out << '\n';
		out << sPtr->getName(); //Output Name
		out << '\n';
		out << sPtr->getEmail(); //Output Email
		out << '\n';
		out << sPtr->getEssay1_Grade(); //Output Essay 1 grade
		out << '\n';
		out << sPtr->getEssay2_Grade(); //Output Essay 2 grade
		out << '\n';
		out << sPtr->getProject_Grade(); //Output Project Grade
		out << '\n';
		out << '\n';
	}
	out.close(); //Close output file for storage

   ~students();
	return 0;
}
