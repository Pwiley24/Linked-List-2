#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void add(Node* newNode, Node* head, Node* previous);
void print(Node* current);

int main(){
  bool running = true;
  Node* head = new Node();
  head = NULL;

  while(running){
    //read in user input
    char input[10];
    cout << "Enter a command:" << endl;
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
  
      Node* newNode = new Node(newStudent);

      add(newNode, head, NULL);

    }else if(strcmp(input, "PRINT") == 0){//print the list
      print(head);
    }
  }

  return 0;
}


void add(Node* newNode, Node* current, Node* previous){
  if(current == NULL){//first item in list
    current = newNode;
  }else{//sort by id
    if(newNode->getStudent()->getId() > current->getStudent()->getId()){//if new node goes before a node
      if(previous != NULL){//not the head
	previous->setNext(newNode);
      }
      newNode->setNext(current);
    }else{//recursion
      add(newNode, current->getNext(), current);
    }
  }
}

void print(Node* current){
  cout << current->getStudent()->getId() << ", " << current->getStudent()->getName() << endl;
  if(current->getNext() != NULL){
    print(current->getNext());
  }
}
