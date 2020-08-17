/*
* Karl Mattson
* WGU C867
* 8/12/2020
*/

#pragma once
#include "degree.h"
#include "student.h"
#include <iostream>

using namespace std;

//Constructor
Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, 
                  int newAge, int newDaysInCourse1, int newDaysInCourse2, int newDaysInCourse3, DegreeProgram newDegree) {
   studentID = newStudentID;
   firstName = newFirstName;
   lastName = newLastName;
   emailAddress = newEmailAddress;
   age = newAge;
   daysInCourse[0] = newDaysInCourse1;
   daysInCourse[1] = newDaysInCourse2;
   daysInCourse[2] = newDaysInCourse3;
   degree = newDegree;
};

Student::Student() {
   studentID = "";
   firstName = "";
   lastName = "";
   emailAddress = "";
   age = 0;
   daysInCourse[0] =    0;
   daysInCourse[1] = 0;
   daysInCourse[2] = 0;
   degree = DegreeProgram::SOFTWARE;
};

//Getters
string Student::getStudentID() const {
   return studentID;
};

string Student::getFirstName() const {
   return firstName;
};

string Student::getLastName() const {
   return lastName;
};

string Student::getEmailAddress() const {
   return emailAddress;
};

int Student::getAge() const {
   return age;
};

int Student::getDaysInCourse1() const {
   return daysInCourse[0];
};

int Student::getDaysInCourse2() const {
   return daysInCourse[1];
};

int Student::getDaysInCourse3() const {
   return daysInCourse[2];
};

DegreeProgram Student::getDegreeProgram() const {
   return degree;
}

string Student::getDegreeString() const {
   switch (this->degree) {
   case DegreeProgram::SECURITY:
      return "SECURITY";
   case DegreeProgram::NETWORK:
      return "NETWORK";
   case DegreeProgram::SOFTWARE:
      return "SOFTWARE";
   default:
      return "INVALID VALUE";
   }

}

//Setters
void Student::setStudentID(string newID) {
   studentID = newID;
};

void Student::setFirstName(string newFirstName) {
   firstName = newFirstName;
};

void Student::setLastName(string newLastName) {
   lastName = newLastName;
};

void Student::setEmailAddress(string newEmailAddress) {
   emailAddress = newEmailAddress;
};

void Student::setAge(int newAge) {
   age = newAge;
};

void Student::setDaysInCourse1(int newDaysInCourse) {
   daysInCourse[0] = newDaysInCourse;
};

void Student::setDaysInCourse2(int newDaysInCourse) {
   daysInCourse[1] = newDaysInCourse;
};

void Student::setDaysInCourse3(int newDaysInCourse) {
   daysInCourse[2] = newDaysInCourse;
};

void Student::setDegree(DegreeProgram newDegree) {
   degree = newDegree;
};

//Functions
void Student::print() const {
   cout << studentID << "\t";
   cout << "First Name: " << firstName << "\t";
   cout << "Last Name: " << lastName << "\t";
   cout << "Age: " << age << "\t";
   cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";
   cout << "Degree Program: " << this->getDegreeString() << endl;
   cout << flush;
};
