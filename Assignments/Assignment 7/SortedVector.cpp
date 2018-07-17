/*****************************************************************************
 * Name        : SortedVector.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to SortedVector
 *****************************************************************************/

#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
    sortedVector.clear();
}

void SortedVector::prepend(const long value)
{
	Node newNode(value);
	sortedVector.insert(sortedVector.begin(), newNode);
}

/**
 * Append a new node at the end of the vector.
 * @param value the new node's value.
 */
void SortedVector::append(const long value)
{
	Node newNode(value);
	sortedVector.push_back(newNode);
}

/**
 * Insert a new node into the vector at the
 * appropriate position to keep the vector sorted.
 * @param value the value of the node to insert.
 */
void SortedVector::inserts(const long value)
{
	Node newNode(value);
    vector<Node>::iterator start = sortedVector.begin();
    vector<Node>::iterator end = sortedVector.end();
    bool flag = false;
	while(start != end)
	{
		if(*start <= newNode)
		{
			start++;
		}
		else
		{
			sortedVector.insert(start, newNode);
			flag = true;
			break;
		}
	}
	if(!flag)
		sortedVector.push_back(newNode);
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedVector::remove(const int index)
{
	vector<Node>::iterator start = sortedVector.begin();
	int count = index;
	while(count > 0)
	{
		count--;
		start++;
	}
	sortedVector.erase(start);
}

/**
 * Reverse in place the order of the nodes of the vector.
 */
void SortedVector::reverse()
{
	vector<Node>::iterator start = sortedVector.begin();
	vector<Node>::iterator end = sortedVector.end();
	while((start != end))
	{
		start++;
		sortedVector.insert(sortedVector.begin(), *start);
		start = sortedVector.erase(start);
	}
}

bool SortedVector::check() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal to the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}
