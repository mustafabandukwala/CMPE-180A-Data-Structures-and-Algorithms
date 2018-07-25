/***************************************************************************
 * Name        : LinkedList.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to LinkedList
 ***************************************************************************/

#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {};

LinkedList::LinkedList(Node *head, Node *tail, const int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;

    this->size = size;
}

LinkedList::~LinkedList() {}

Node *LinkedList::get_head() const { return head; }
Node *LinkedList::get_tail() const { return tail; }
int   LinkedList::get_size() const { return size; }

void LinkedList::set(Node *head, Node *tail, int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;
    this->size = size;
}

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

    // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::reset()
{
    head = tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

void LinkedList::split(LinkedList& list1, LinkedList& list2)
{
   int list_size = size;

   for (int i = 0; i < list_size; i++)
   {
	  //Move the element in the even index number in one list and the remaining in the other
	  if ( i % 2 == 0)
		 list1.add(remove_head());
	  else
		 list2.add(remove_head());
   }
}

void LinkedList::concatenate(LinkedList& other_list)
{
	tail->next=other_list.head;
	this->set(this->head,other_list.get_tail(),size+other_list.size);
	other_list.reset();
}
