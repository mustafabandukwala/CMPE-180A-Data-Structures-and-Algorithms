/*********************************************************************************
 * Name        : SortedLinkedList.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to SortedLinkedList
 *********************************************************************************/

#include "SortedLinkedList.h"

SortedLinkedList::SortedLinkedList() : head(nullptr)
{
}

/**
 * Insert a new node into the sorted linked list.
 * Uses the overloaded Node::operator > to compare nodes.
 * @param node points to the node to insert.
 */
void SortedLinkedList::insert(Node *node)
{
	Node *temp = head;
	Node *prev = head;
	if(temp == NULL)
	{
		head = node;
	}
	else if(*node < *head)
	{
		node->next = head;
		head = node;
	}
	else
	{
		while(temp != NULL && (*node > *temp))
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = node;
		node->next = temp;
	}
}

// Overloaded stream output insertion operator.
ostream& operator <<(ostream& outs, SortedLinkedList& list)
{
	Node* temp = list.head;
	while(temp != NULL)
	{
		outs << *temp;
		temp = temp->next;
	}
	return outs;
}
