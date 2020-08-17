/*
* Karl Mattson
* WGU C867
* 8/12/2020
*/

#pragma once
#include "student.h"

class Roster {
   public:
      Roster();
      ~Roster();
      void add(string studentID, string firstName, string lastName, string emailAddress, 
         int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
      void remove(string studentID);
      void printAll() const;
      void printAverageDaysInCourse(string studentID) const;
      void printInvalidEmails() const;
      void printByDegreeProgram(DegreeProgram degreeProgram);
      int getRosterSize();
      Student** getClassRosterArray();

   private:
      Student** classRosterArray;
      int rosterSize;
};