/*********************************************************************************
 * Name        : BinarySearchTree.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to BinarySearchTree
 *********************************************************************************/

#include <string>
#include <time.h>
#include <chrono>
#include "BinarySearchTree.h"

using namespace std;
using namespace std::chrono;

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() : comparisonCount(0), probeCount(0), elapsedTime(0), root(nullptr)
{

}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree()
{
	clear();
}

/**
 * Getter.
 * @return pointer to the root of the tree.
 */
BinaryNode *BinarySearchTree::get_root() const
{
	return root;
}

/**
 * Public gettere.
 * @return the height of the tree.
 */
int BinarySearchTree::height() const
{
	return height(root);
}

/**
 * Compute the height of a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return the height.
 */
int BinarySearchTree::height(const BinaryNode *ptr) const
{
	if(ptr == nullptr)
		return -1;
	if(height(ptr->left) > height(ptr->right))
		return (1 + height(ptr->left));
	else
		return (1 + height(ptr->right));
}

/**
 * Find the minimum data item in a subtree.
 * @return the minimum data item in the tree
 *         or nullptr if the tree is empty.
 * @throw an error message if an error occurred.
 */
int BinarySearchTree::find_min() const throw(string)
{
	if (is_empty()) throw(string("Empty tree"));
		return find_min(root)->data;
}

/**
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 137
 * Find the minimum data item in a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return pointer to the node containing the smallest data item
 *         or nullptr if the subtree is empty.
 */
BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
	if(ptr != nullptr)
	{
		while(ptr->left != nullptr)
			ptr = ptr->left;
	}
	return ptr;
}

/**
 * Find the maximum data item in a subtree.
 * @return pointer to the maximum data item in the tree
 *         or nullptr if the tree is empty.
 * @throw an error message if an error occurred.
 */
int BinarySearchTree::find_max() const throw(string)
{
	if (is_empty()) throw(string("Empty tree"));
		return find_max(root)->data;
}

/**
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 137
 * Find the maximum data item in a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return pointer to the node containing the largest data item
 *         or nullptr if the subtree is empty.
 */
BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
	if(ptr != nullptr)
	{
		while(ptr->right != nullptr)
		{
			ptr = ptr->right;
		}
	}
	return ptr;
}

/**
 * Public method to empty a subtree.
 */
void BinarySearchTree::clear()
{
	clear(root);
}

/**
 * Empty a subtree.
 * @param ptr pointer to the root node of the subtree.
 */
void BinarySearchTree::clear(BinaryNode* &ptr)
{
	if(ptr != nullptr)
	{
		clear(ptr->left);
		clear(ptr->right);
		delete ptr;
		ptr = nullptr;
	}
}

/**
 * @return true if and only if the tree is empty.
 */
bool BinarySearchTree::is_empty() const
{
	if(root == nullptr)
		return true;
	return false;
}

/**
 * Search for a data item in a subtree.
 * @param data the data to search for.
 * @param ptr pointer to the root node of the subtree.
 * @return true if and only if data is in the tree.
 */
bool BinarySearchTree::contains(const int data)
{
	return contains(data, root);
}

/**
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 136
 * Search for a data item in the tree.
 * @param data the data to search for.
 * @return true if and only if data is in the tree.
 */
bool BinarySearchTree::contains(const int data, BinaryNode *ptr)
{
	while(ptr != nullptr)
	{
		comparisonCount++; // One for while loop
		comparisonCount++; // One for if-else conditions
		if(ptr->data == data)
			return true;
		else if(ptr->data > data)
		{
			probeCount++;
			ptr = ptr->left;
		}
		else if(ptr->data < data)
		{
			probeCount++;
			ptr = ptr->right;
		}
	}
	return false;
}

/**
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 138
 * Insert a data item into a subtree
 * and set the new root of the subtree.
 * @param data the data to insert into the tree.
 */
void BinarySearchTree::insert(const int data)
{
    insert(data, root);
}

/*
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 136
 * Insert a data item into a subtree
 * and set the new root of the subtree.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
	comparisonCount++;
    if (ptr == nullptr)
    {
        ptr = new BinaryNode(data);
    }
    else
    {
    	comparisonCount++;
    	if (data < ptr->data)
    	{
    		probeCount++;
    		insert(data, ptr->left);
    	}
    	else if (data > ptr->data)
    	{
    		probeCount++;
    		insert(data, ptr->right);
		}
	}
}

/**
 * Reference:-
 * Book: Data Structures and Algorithms Analysis in C++, 4th edition
 * Author: Mark Allen Weiss
 * Page: 140
 * Remove a data item from a subtree
 * and set the new root of the subtree.
 * Do nothing if the data item is not found.
 * @param data the data to remove.
 */
void BinarySearchTree::remove(const int data)
{
	remove(data, root);
}

/*
 * Reference:-
 * Book: Data Structures Using C++, 2nd edition
 * Author: D.S. Malik
 * Page: 625-626
 * Protected method to remove a data item from a subtree
 * and set the new root of the subtree.
 * Do nothing if the data item is not found.
 * @param data the data to remove.
 * @param ptr pointer to the root node of the subtree.
 */
void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
    if (ptr == nullptr)
    	return;

    if (data < ptr->data)
        remove(data, ptr->left);
    else if (data > ptr->data)
        remove(data, ptr->right);
    else if ((ptr->left != nullptr) && (ptr->right != nullptr))
    {
        ptr->data = find_min(ptr->right)->data;
        remove(ptr->data, ptr->right);
    }
    else
    {
        BinaryNode *oldNode = ptr;
        if(ptr->left != nullptr)
        	ptr = ptr->left;
        else
        	ptr = ptr->right;
        delete oldNode;
    }
}

void BinarySearchTree::reset()
{
	comparisonCount = 0;
	probeCount = 0;
	elapsedTime = 0;
}

long BinarySearchTree::get_probe_count() const
{
	return probeCount;
}

long BinarySearchTree::get_comparison_count() const
{
	return comparisonCount;
}
long BinarySearchTree::get_elapsed_time() const
{
	return elapsedTime;
}

void BinarySearchTree::increment_elapsed_time(long msec)
{
	elapsedTime += msec;
}
