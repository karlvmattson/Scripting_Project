/*
* Karl Mattson
* WGU C867
* 8/12/2020
*/

#pragma once
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


//University student system
int main() {
   //Declare variables
   const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                  "A5,Karl,Mattson,kmatts5@wgu.edu,37,30,15,10,SOFTWARE" };
   Roster* classRoster = new Roster();
   DegreeProgram degree = DegreeProgram::NETWORK;
   istringstream inputStream;
   string studentID = "";
   string firstName = "";
   string lastName = "";
   string email = "";
   string tmpString = "";
   int age = 0;
   int days1 = 0;
   int days2 = 0;
   int days3 = 0;

   for (string studentString : studentData) {
      inputStream.clear();
      inputStream.str(studentString);
      getline(inputStream, studentID, ',');
      getline(inputStream, firstName, ',');
      getline(inputStream, lastName, ',');
      getline(inputStream, email, ',');
      getline(inputStream, tmpString, ',');
      age = stoi(tmpString);
      getline(inputStream, tmpString, ',');
      days1 = stoi(tmpString);
      getline(inputStream, tmpString, ',');
      days2 = stoi(tmpString);
      getline(inputStream, tmpString, ',');
      days3 = stoi(tmpString);
      getline(inputStream, tmpString, ',');
      if (tmpString == "SOFTWARE") {
         degree = DegreeProgram::SOFTWARE;
      }
      else if (tmpString == "NETWORK") {
         degree = DegreeProgram::NETWORK;
      }
      else {
         degree = DegreeProgram::SECURITY;
      }
      classRoster->add(studentID, firstName, lastName, email, age, days1, days2, days3, degree);
   }

   //Print header
   cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << endl;
   cout << "C++" << endl;
   cout << "Student #001253438" << endl;
   cout << "Karl Mattson" << endl << endl;

   //Functions per project specification
   classRoster->printAll();
   classRoster->printInvalidEmails();

   ////loop through classRosterArray and for each element:
   for (int i = 0; i < classRoster->getRosterSize(); i++) {
      classRoster->printAverageDaysInCourse((classRoster->getClassRosterArray())[i]->getStudentID());
   }

   classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
   classRoster->remove("A3");
   classRoster->printAll();
   classRoster->remove("A3");
   ////expected: the above line should print a message saying such a student with this ID was not found.

   //5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
   delete classRoster;
}