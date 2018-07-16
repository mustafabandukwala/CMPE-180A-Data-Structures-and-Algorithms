/*********************************************************************
 * Name        : Node.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Node
 *********************************************************************/

#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A linked list node.
 */
class Node
{
public:

    // Public pointer to the next node in the list.
    Node *next;

    // Default Constructor
    Node();

    //Non-Default Constructor
    Node(Coordinate);

    //Non-Default Constructor
    Node(City city);

    // Overloaded > operator.
    bool operator >(const Node& other);

    // Overloaded > operator.
    bool operator <(const Node& other);
    // Overloaded stream output insertion operator.
    friend ostream& operator <<(ostream& outs, const Node& node);

private:
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    int row;       // print row
    int col;       // print column

    void convert_coordinate(Coordinate& coordinate);
    void convert_coordinate(City& city);
};

#endif /* NODE_H_ */
