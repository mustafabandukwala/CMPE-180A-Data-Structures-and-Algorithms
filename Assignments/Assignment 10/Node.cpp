/*********************************************************************
 * Name        : Node.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Node
 *********************************************************************/

#include "Node.h"
#include "Element.h"

//Default Constructor for Node
Node::Node()
{
   Element();
   next = NULL;
}

Node::~Node()
{

}

//Constructor for node with input element object
Node::Node(const Element element)
{
   this->element = element;
   next = NULL;
}

