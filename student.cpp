#include "student.h"
#include <cctype>

Student::Student()                 // default constructor
: name(""), email(""), id(0), proj1(0), proj2(0), finalProj(0)
{}

// creates a Student with given id and name (NON-default constructor)
Student::Student(string theName, string theEmail, int theId)
: name(theName), email(theEmail), id(theId), proj1(0), proj2(0), finalProj(0)
{}

string Student::getName()const;     // return name of Student
{
    return name;
}

string Student::getEmail()const;     // return name of Student
{
    return email;
}

int Student::getId()const          // return Student id of Student
{
    return id;
}

int Student::getProj1()const        // return Test 1 score for Student
{
    return proj1;
}

int Student::getProj2()const
  // return Test 2 score for Student
{
    return proj2;
}

int Student::getFinalProj()const    // return Test 3 score for Student
{
    return finalProj;
}

void Student::setName(string newName)
{
    name = newName;
}

void Student::setEmail(string newEmail)
{
    email = newEmail;
}

void Student::setId(int newId)
{
    if (newId>0)
        id=newId;
    else
        cerr <<"Invalid Id input, no change made.\n" << endl;
}

void Student::setProj1(int projScore)
{
    if (projScore >= 0 && projScore <= 4)
        proj1 = projScore;
    else
        cerr << "Invalid project score input, no change made" << endl;
}

void Student::setProj2(int projScore)
{
    if (projScore >= 0 && projScore <= 4)
        proj2 = projScore;
    else
        cerr<< "Invalid project score input, no change made" << endl;
}

void Student::setFinalProj(int projScore)
{
    if (projScore >= 0 && projScore <= 4)
        finalProj = projScore;
    else
        cerr<< "Invalid project score input, no change made"<<endl;

}
