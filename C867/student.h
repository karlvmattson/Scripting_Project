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
      Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
      Student();

      //Getters
      string         getStudentID() const;
      string         getFirstName() const;
      string         getLastName() const;
      string         getEmailAddress() const;
      int            getAge() const;
      int            getDaysInCourse1() const;
      int            getDaysInCourse2() const;
      int            getDaysInCourse3() const;
      DegreeProgram  getDegreeProgram() const;
      string         getDegreeString() const;

      //Setters
      void           setStudentID(string newID);
      void           setFirstName(string newFirstName);
      void           setLastName(string newLastName);
      void           setEmailAddress(string newEmailAddress);
      void           setAge(int newAge);
      void           setDaysInCourse1(int newDaysInCourse);
      void           setDaysInCourse2(int newDaysInCourse);
      void           setDaysInCourse3(int newDaysInCourse);
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

