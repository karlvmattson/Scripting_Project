/*
* Karl Mattson
* WGU C867
* 8/12/2020
*/

#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {
   public:
      //Constructor
      Student(string studentID, string firstName, string lastName, string emailAddress, 
         int age, int daysInCourse[3], DegreeProgram degree);
      Student();

      //Getters
      string         getStudentID() const;
      string         getFirstName() const;
      string         getLastName() const;
      string         getEmailAddress() const;
      int            getAge() const;
      int*           getDaysInCourse() const;
      DegreeProgram  getDegreeProgram() const;
      string         getDegreeString() const;

      //Setters
      void           setStudentID(string newID);
      void           setFirstName(string newFirstName);
      void           setLastName(string newLastName);
      void           setEmailAddress(string newEmailAddress);
      void           setAge(int newAge);
      void           setDaysInCourse(int newDaysInCourse[3]);
      void           setDegree(DegreeProgram newDegree);

      //Functions
      void           print() const;

   private:
      string         studentID;
      string         firstName;
      string         lastName;
      string         emailAddress;
      int            age;
      int            daysInCourse[3];
      DegreeProgram  degree;
};

