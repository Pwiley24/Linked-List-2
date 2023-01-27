#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>


using namespace std;

class Student{
 public:
  Student();
  int getId();
  char* getName();
  void setName(char*);
  void setId(int number);
  void setGpa(float number);
  float getGpa();

 private:
  char* name;
  int id;
  float gpa;
};

#endif
