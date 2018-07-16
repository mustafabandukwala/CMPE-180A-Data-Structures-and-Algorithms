/*********************************************************************
 * Name        : Node.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Node
 *********************************************************************/

#include <math.h>
#include "Node.h"
#include "Coordinate.h"
#include "City.h"
#include <string>

int row = 0;
int col = 0;
bool flag = false;
// Default Constructor
Node::Node() : name(""), state(""), row(0), col(0), next(nullptr)
{
}

//Non-Default Constructor
Node::Node(Coordinate coordinate)
{
	convert_coordinate(coordinate);
	next = nullptr;
}

//Non-Default Constructor
Node::Node(City city)
{
	convert_coordinate(city);
	next = nullptr;
}

/**
 * Convert a coordinate's latitude and longitude
 * into a row and column, respectively, for printing.
 */
void Node::convert_coordinate(Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

/**
 * Convert a coordinate's latitude and longitude
 * into a row and column, respectively, for printing.
 */
void Node::convert_coordinate(City& city)
{
	convert_coordinate(city.get_coordinate());
    name = city.get_name();
    state = city.get_state();
}
/**
 * Overloaded > operator used to determine
 * where to insert a node into the linked list.
 * The list is sorted first by row and then by column.
 */
bool Node::operator >(const Node& other)
{
	if(this->row == other.row)
	{
		if(this->col > other.col)
			return true;
	}
	else
	{
		if(this->row > other.row)
			return true;
	}
	return false;
}

/**
 * Overloaded < operator used to determine
 * where to insert a node into the linked list.
 * The list is sorted first by row and then by column.
 */
bool Node::operator <(const Node& other)
{
	if(this->row == other.row)
	{
		if(this->col < other.col)
			return true;
	}
	else
	{
		if(this->row < other.row)
			return true;
	}
	return false;
}

// Overloaded stream output insertion operator.
ostream& operator <<(ostream& outs, const Node& node)
{
	if(row == node.row)
	{
		int count = node.col - col;
		if(count > 0)
		{
			while(count > 1)
			{
				cout << " ";
				count--;
			}
			if(node.name != "" && node.state != "")
			{
				cout << "*" << node.name << " " << node.state;
				int len = node.name.length() + node.state.length() + 1;
				col = node.col + len;
			}
			else
			{
				cout << "#";
				col = node.col;
			}
		}
	}
	else
	{
		while(node.row != row)
		{
			cout << endl;
			row++;
		}
		col = 0;
		int count = node.col - col;
		while(count > 1)
		{
			cout << " ";
			count--;
		}
		if(node.name != "" && node.state != "")
		{
			cout << "*" << node.name << " " << node.state;
			int len = node.name.length() + node.state.length() + 1;
			col = node.col + len;
		}
		else
		{
			cout << "#";
			col = node.col;
		}
	}

	if(!flag)
	{
		if(node.row == 48 && node.col == 89)
		{
			flag = true;
			row = 0;
			col = 0;
		}
	}
	return outs;
}
