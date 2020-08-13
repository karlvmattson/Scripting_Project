/*
* Karl Mattson
* WGU C867
* 8/12/2020
*/

#pragma once
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;


//University student system
int main() {
   DegreeProgram degree = DegreeProgram::SOFTWARE;
   Student testStudent = Student("A1", "Karl", "Mattson", "kmatts5@wgu.edu", 37, 30,40,50, degree);
   testStudent.print();

}