#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
 public :
    Student();                     // default constructor
    Student(string name, string email, int id, int proj1, int proj2, int finalProj); // construct an Student with given values
    string getName()const;          // return name of Student
    string getEmail()const;         // return email of Student
    int getId()const;               // return Student id of Student
    int getProj1()const;            // return project 1 score for Student
    int getProj2()const;            // return project 2 score for Student
    int getFinalProj()const;        // return final project score for Student

    void getData(istream &is);      // gets data from stream in expected format

    void setName(string newName);  // edit name
    void setEmail(string newEmail);// edit email
    void setId(int newId);         // edit id
    void setProj1(int projScore);  // edit project 1 grade
    void setProj2(int projScore);  // edit project 2 grade
    void setFinalProj(int projScore);  // edit final project grade
 private:
    string name;                    // the Student name
    int id;                         // the Student number
    string email;                   // the Student email
    int proj1, proj2, finalProj;    // the Student's 3 project scores
};

#endif // STUDENT_H_INCLUDED
