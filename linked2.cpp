#include <iostream>

using namespace std;

void add(Node* newNode, Node* head);

int main(){
  bool running = true;
  head = new Node();
  head = NULL;

  while(running){
    //read in user input
    char[10] input;
    cout << "Enter a command:" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');

    if(strcmp(input, "ADD") == 0){//user wants to add
      Student newStudent = new Student();
      newStudent->setName(name);
      newStudent->setId(id);
      //ask and assign student info

      Node newNode = new Node(newStudent);

      void add(newNode, head);
    }

  }

void add(Node* newNode, Node* current){
  if(current == NULL){//first item in list
    head = newNode;
  }else{//sort by id
    if(newNode->getId() > current->getId()){//if new node goes before a node

    }else{//recursion

    }

  }

