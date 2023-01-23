#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(){
  name = new char[30];
  id = 0;
}

char* Student::getName(){
  return name;
}

int Student::getId(){
  return id;

}

void Student::setName(char* title){
  name = new char[30];
  strcpy(name, title);
}

void Student::setId(int number){
  id = number;
}
