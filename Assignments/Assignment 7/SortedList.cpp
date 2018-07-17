/***************************************************************************
 * Name        : SortedList.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to SortedList
 ***************************************************************************/

#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
    sortedList.clear();
}

/**
 * Insert a new node at the beginning of the list.
 * @param value the new node's value.
 */
void SortedList::prepend(const long value)
{
	Node newNode(value);
	sortedList.push_front(newNode);
}

/**
 * Append a new node at the end of the list.
 * @param value the new node's value.
 */
void SortedList::append(const long value)
{
	Node newNode(value);
	sortedList.push_back(newNode);
}

/**
 * Insert a new node into the list at the
 * appropriate position to keep the list sorted.
 * @param value the value of the node to insert.
 */
void SortedList::inserts(const long value)
{
	Node newNode(value);
	list<Node>::iterator start = sortedList.begin();
	list<Node>::iterator end = sortedList.end();
    bool flag = false;
	while(start != end)
	{
		if(*start <= newNode)
		{
			start++;
		}
		else
		{
			sortedList.insert(start, newNode);
			flag = true;
			break;
		}
	}
	if(!flag)
		sortedList.push_back(newNode);
}
/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedList::remove(const int index)
{
	sortedList.pop_back();
}

/**
 * Reverse in place the order of the nodes of the list.
 */
void SortedList::reverse()
{
	list<Node>::iterator start = sortedList.begin();
	list<Node>::iterator end = sortedList.end();
	while((start != end))
	{
		start++;
		sortedList.insert(sortedList.begin(), *start);
		start = sortedList.erase(start);
	}
}

/**
 * Overloaded [] operator that returns
 * a reference to a Node element.
 * @param index the index of the element to return.
 * @return a reference to the element.
 */
Node& SortedList::operator[](const int index)
{
	list<Node>::iterator start = sortedList.begin();

	int count = index;
	while(count > 0)
	{
		count--;
		start++;
	}
	return *start;
}

bool SortedList::check() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}
