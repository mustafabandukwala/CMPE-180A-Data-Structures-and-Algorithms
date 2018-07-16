/*********************************************************************************
 * Name        : SortedLinkedList.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to SortedLinkedList
 *********************************************************************************/

#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_

#include "Node.h"

/**
 * A singly-linked list of Node objects that is sorted
 * by the nodes' rows and columns.
 */
class SortedLinkedList
{
public:

    //Default Constructor
	SortedLinkedList();

    void insert(Node *node);

    // Overloaded stream output insertion operator.
    friend ostream& operator <<(ostream& outs, SortedLinkedList& list);

private:
    Node *head;  // pointer to the head of the linked list
};

#endif /* SORTEDLINKEDLIST_H_ */
