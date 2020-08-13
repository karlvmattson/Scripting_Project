#include <string>
#include "degree.h"
using namespace std;

class Student {
   public:
      //Getters
      string         getStudentID();
      string         getFirstName();
      string         getLastName();
      string         getEmailAddress();
      int            getAge();
      int            getDaysInCourse();
      DegreeProgram  getDegreeProgram();

      //Setters
      void           setStudentID(string newID);
      void           setFirstName(string newFirstName);
      void           setLastName(string newLastName);
      void           setEmailAddress(string newEmailAddress);
      void           setAge(int newAge);
      void           setDaysInCourse(int newDaysInCourse);
      void           setDegree(DegreeProgram newDegree);

      //Constructor
      Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[3], DegreeProgram degree);
      Student();

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

