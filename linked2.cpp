/*
 * This program creates a node list of students that stores their name, id, and gpa.
 * Author: Paige Wiley
 * Date: 1-27-2023
 */
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void add(Node* newNode, Node* current, Node* previous, Node* & head);
void print(Node* current);
void deleteNode(Node* current, int number, Node* previous, Node* & head);
void findAverage(Node* current, float average, int nodeNum);

int main(){
  bool running = true;
  Node* head = new Node();
  head = NULL;

  while(running){
    //read in user input
    char input[10];
    cout << "Enter a command: (ADD, PRINT, DELETE, AVERAGE, QUIT)" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');

    if(strcmp(input, "ADD") == 0){//user wants to add
      Student* newStudent = new Student();
    
      //get name
      char name[20];
      cout << "What is the student's name?" << endl;
      cin.get(name, 20);
      cin.ignore(20, '\n');
      newStudent->setName(name);
    
      //get ID:
      int id = 0;
      cout << "What is the student's ID?" << endl;
      cin >> id;
      cin.ignore(20, '\n');
      newStudent->setId(id);

      //get GPA:
      float gpa = 0;
      cout << "What is the student's GPA?" << endl;
      cin >> gpa;
      cin.ignore(10, '\n');
      newStudent->setGpa(gpa);
  
      Node* newNode = new Node(newStudent);
      add(newNode, head, NULL, head);

    }else if(strcmp(input, "PRINT") == 0){//print the list
      print(head);
    }else if(strcmp(input, "DELETE") == 0){//delete a node/student
      cout << "What is the student's ID?" << endl;
      int id = 0;
      cin >> id;
      cin.ignore(20, '\n');
      deleteNode(head, id, NULL, head); 

      
    }else if(strcmp(input, "QUIT") == 0){//quit the program
      running = false;


    }else if(strcmp(input, "AVERAGE") == 0){//find average gpa of all students
      float average = 0;
      int nodeNum = 0;
      findAverage(head, average, nodeNum);
    }
  }

  return 0;
}


void add(Node* newNode, Node* current, Node* previous, Node* & head){
  if(head == NULL &&
     head == current){//first item in list
    head = newNode;
    current = newNode;
  }else if(current == NULL &&
	   previous != NULL){
    previous->setNext(newNode);

  }else{//sort by id
    if(newNode->getStudent()->getId() > current->getStudent()->getId()){//if new node goes before a node
      if(previous != NULL &&
	 previous != head){//not the head
	previous->setNext(newNode);
      }else if(previous == NULL){//previous is the head node
	head = newNode;
      }
      newNode->setNext(current);
    }else{//recursion
      
      add(newNode, current->getNext(), current, head);
    }
  }
}

void print(Node* current){
  if(current == NULL){
    cout << "Nothing to print" << endl;
  }else{
    cout << current->getStudent()->getName() << ", " << current->getStudent()->getId() << ", " << current->getStudent()->getGpa()<< endl;
  
    if(current->getNext() != NULL){
      print(current->getNext());
    }
  }
}


void deleteNode(Node* current, int number, Node* previous, Node* & head){
  if(current->getStudent()->getId() == number){
    if(previous != NULL){
      previous->setNext(current->getNext());
    }else{//deleting head
      head = current->getNext();
    }
    delete current;
  }else{
    if(current->getNext() != NULL){
      deleteNode(current->getNext(), number, current, head);
    }else {
      cout << "No ID matches" << endl;
    }
  }
  
}


void findAverage(Node* current, float average, int nodeNum){
  if(current != NULL){//if there is data to average
    nodeNum++;
    average += current->getStudent()->getGpa();
    if(current->getNext() != NULL){//still more nodes
      findAverage(current->getNext(), average, nodeNum);
    }else{
      average /= nodeNum;
      cout << "Average GPA: " << average << endl;
    }
  }else{
    cout << "No data to calculate." << endl;
  }
}
