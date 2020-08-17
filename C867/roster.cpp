#include "roster.h"
/*
* Karl Mattson
* WGU C867
* 8/12/2020
*/

#pragma once
#include "roster.h"
#include <iostream>
#include <string>

Roster::Roster() {
   classRosterArray = new Student*[0];
   rosterSize = 0;
}

Roster::~Roster() {
   delete[] classRosterArray;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, 
   int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

   //Create temporary array
   Student** tempClassRosterArray = new Student*[rosterSize + 1];

   //Copy existing array into temp array
   for (int i = 0; i < rosterSize; i++) {
      tempClassRosterArray[i] = classRosterArray[i];
   }

   //Create new Student
   int* newDays = new int[3];
   newDays[0] = daysInCourse1;
   newDays[1] = daysInCourse2;
   newDays[2] = daysInCourse3;
   Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, newDays, degreeProgram);
   delete[] newDays;

   //Increment roster size
   rosterSize++;

   //Add pointer to new item to the roster
   tempClassRosterArray[rosterSize - 1] = newStudent;

   //Delete old array
   delete[] classRosterArray;

   //Assign new array
   classRosterArray = tempClassRosterArray;
}

void Roster::remove(string studentID) {

   int copiesFound = 0;

   //Find how many copied to delete
   for (int i = 0; i < rosterSize; i++) {
      if (classRosterArray[i]->getStudentID() == studentID) {
         copiesFound++;
      }
   }

   //Exit if student ID not found
   if (copiesFound == 0) {
      cout << "Student ID not found." << endl;
      return;
   }

   //Create temporary array
   Student** tempClassRosterArray = new Student * [rosterSize - copiesFound];

   //Copy existing array into temp array, filtering for the given studentID
   for (int i = 0, j = 0; i < rosterSize; i++) {
      if (classRosterArray[i]->getStudentID() != studentID) {
         tempClassRosterArray[j++] = classRosterArray[i];
      }
   }

   //Decrement roster size
   rosterSize = rosterSize - copiesFound;

   //Delete old array
   delete[] classRosterArray;

   //Assign new array
   classRosterArray = tempClassRosterArray;
}

void Roster::printAll() const {
   for (int i = 0; i < rosterSize; i++) {
      classRosterArray[i]->print();
      //cout << endl;
   }
}

void Roster::printAverageDaysInCourse(string studentID) const {
   Student* studentPtr = nullptr;
   
   //Find student id in array
   for (int i = 0; i < rosterSize; i++) {
      if ((*classRosterArray[i]).getStudentID() == studentID) {
         studentPtr = classRosterArray[i];         
         break;
      }
   }

   if (studentPtr == nullptr) {
      cout << "Student ID not found" << endl;
   }
   else {
      int* dayArray = new int[3];
      dayArray = (*studentPtr).getDaysInCourse();
      cout << "Average days in course: " << ((dayArray[0] + dayArray[1] + dayArray[2]) / 3) << endl;
   }
}

void Roster::printInvalidEmails() const {
   string testEmail = "";
   int atPos = 0;
   int dotPos = 0;
   int spacePos = 0;
   for (int i = 0; i < rosterSize; i++) {
      atPos = 0;
      dotPos = 0;
      spacePos = 0;
      testEmail = classRosterArray[i]->getEmailAddress();
      atPos = testEmail.find("@");
      dotPos = testEmail.find(".", atPos);
      spacePos = testEmail.find(" ");
      if (dotPos < 1 || atPos < 1 || spacePos > 0) {
         cout << testEmail << endl;
      }
   }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
   for (int i = 0; i < rosterSize; i++) {
      if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
         classRosterArray[i]->print();
      }
   }
}

int Roster::getRosterSize() {
   return rosterSize;
}

Student** Roster::getClassRosterArray() {
   return classRosterArray;
}
