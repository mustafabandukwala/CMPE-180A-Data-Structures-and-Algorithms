/***************************************************************************
 * Name        : BinaryNode.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to BinaryNode
 ***************************************************************************/

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
    /**
     * Constructor.
     * @param data the data item.
     */
    BinaryNode(const int data);

    /**
     * Constructor.
     * @param data the data item.
     * @param left the left link.
     * @param right the right link.
     */
    BinaryNode(const int data, BinaryNode *left, BinaryNode *right);

    /**
     * Destructor.
     */
    virtual ~BinaryNode();

    int data;
    int height;  // node height

    BinaryNode *left;
    BinaryNode *right;
};


#endif // BINARY_TREE_PRINTER_H
