/*
 * LinkedList Assignment
 *
 * File: Node.h
 * Description: Node definition
 *
 * Colby Waters
 * 1/15/2023
 */

/*
 * Node class that contains student information. Node is used as part of a LinkedList.
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node
{
public:
    // Default constructor
    Node();

    // Constructor that takes student
    Node(Student* pStudent);

    // Destructor
    ~Node();

    // Set next node pointer. This will be pointer to next element in linked list.
    void setNext(Node* pNode);

    // Get next node pointer. This is useful for traversing linked lists.
    Node* getNext();
    
    // Get student information for this node.
    
    Student* getStudent();
private:
    Student* mpStudent;  // Student info for this node.
    Node* mpNext;        // link to next Node
};

#endif
