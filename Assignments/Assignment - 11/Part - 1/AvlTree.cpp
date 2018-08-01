/************************************************************************
 * Name        : AvlTree.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to AvlTree
 ************************************************************************/

#include <iostream>
#include "AvlTree.h"

using namespace std;

/**
 * Default constructor
 */
AvlTree::AvlTree() : BinarySearchTree()
{

}

/**
 * Destructor.
 */
AvlTree::~AvlTree()
{

}

/**
 * Compute the height of a subtree.
 * Overrides the base class method.
 * @param ptr pointer to the root node of the subtree.
 * @return the height of the subtree.
 */
int AvlTree::height(const BinaryNode *ptr) const
{
    if(ptr == nullptr)
    	return -1;
    return (ptr->height);
}

/**
 * Insert a data item into a subtree
 * and set the new root of the subtree.
 * Overrides the base class method.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::insert(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

/**
 * Rremove a data item from a subtree
 * and set the new root node of the subtree.
 * Do nothing if the data item is not found.
 * Overrides the base class method.
 * @param data the data to remove.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

/**
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 155
 * Rebalance the tree if necessary.
 * @param ptr pointer to the node to balance.
 * @return pointer to the balanced node.
 */
BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
    if (ptr == nullptr)
    	return ptr;

    if (height(ptr->left) - height(ptr->right) > 1)
    {
        if (height(ptr->left->left) >= height(ptr->left->right))
        {
            ptr = single_right_rotation(ptr);
            cout << "    --- Single right rotation at node " << ptr->data << endl;
        }
        else
        {
            ptr = double_left_right_rotation(ptr);
            cout << "    --- Double left-right rotation at node " << ptr->data << endl;
        }
    }
    else if (height(ptr->right) - height(ptr->left) > 1)
    {
        if (height(ptr->right->right) >= height(ptr->right->left))
        {
            ptr = single_left_rotation(ptr);
            cout << "    --- Single left rotation at node " << ptr->data << endl;
        }
        else
        {
            ptr = double_right_left_rotation(ptr);
            cout << "    --- Double right-left rotation at node " << ptr->data << endl;
        }
    }

    ptr->height = (max(height(ptr->left), height(ptr->right)) + 1);

    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

/*
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 156
 * Case 1 (outside left-left): Rebalance with a single right rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{
	BinaryNode *BN = k1;

	BN = k1->right;
	k1->right = BN->left; //The left subtree of temp becomes the right subtree of k2
	BN->left = k1;

	if(height(k1->left) > height(k1->right))
		k1->height = height(k1->left) + 1;
	else
		k1->height = height(k1->right) + 1;

	return BN;
}

/*
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 156
 * Case 2 (outside right-right): Rebalance with a single left rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{
	BinaryNode *BN = k2;

	BN = k2->left;
	k2->left = BN->right; //The right subtree of temp becomes the left subtree of k2
	BN->right = k2;

	if(height(k2->left) > height(k2->right))
		k2->height = height(k2->left) + 1;
	else
		k2->height = height(k2->right) + 1;

	return BN;
}

/*
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 157
 * Case 3 (inside left-right): Rebalance with a double left-right rotation.
 * @param k3 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{
	BinaryNode *BN;
	BN = k3->left;
	k3->left = single_left_rotation(BN);
	return single_right_rotation(k3);
}

/*
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 157
 * Case 4 (inside right-left): Rebalance with a double left rotation.
 * @param k1 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
	BinaryNode *BN;
	BN = k1->right;
	k1->right = single_right_rotation(BN);
	return single_left_rotation(k1);
}

/**
 * Paranoid check of whether a tree node is balanced.
 * @param ptr pointer to the node to check.
 * @return the height of the node if balanced, -1 if the node is null,
 *         or -2 if unbalanced.
 */
int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
