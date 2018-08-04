/*******************************************************************************************
 * Name        : BSTApp.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : Test the binary search tree and AVL tree implementations.
 * 				 The AVL tree is derived from the binary search tree.
 * 				 Create a tree of height 5 and then repeatedly delete the root.
 * 				 The AVL tree should remain balanced after each node insertion and deletion.
 *******************************************************************************************/

#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <iomanip>

#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;
using namespace std::chrono;
const bool DUMP = false;

/**
 * Run the test with a binary search tree.
 */
void testBST();

/**
 * Run the test with an AVL tree.
 */
void testAVL();

/**
 * Build a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param size of the tree.
 */
void buildTree(BinarySearchTree& tree, int size);

/**
 * Search in a binary tree.
 * @param tree the tree to test.
 * @param size of the tree.
 */
void searchInTree(BinarySearchTree& tree, int size);

/**
 * Print probeCount and comparisonCount statistics
 */
void statistics(BinarySearchTree& tree);

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n);


/**
 * Main.
 */
int main( )
{
    testBST();
    testAVL();
}

static const int VALUES[] =
{
		5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000
};

void testBST()
{
    cout << endl;
    cout << "**********************" << endl;
    cout << "* BINARY SEARCH TREE *" << endl;
    cout << "**********************" << endl;

    BinarySearchTree tree;

    for (int size : VALUES)
    {
    	cout << "--------------------------------------------------------------------------------------------" << endl;
    	cout << setw(50) << "N = " << commafy(size) << endl;
    	cout << "--------------------------------------------------------------------------------------------" << endl;
		cout << "---------" << endl;
		cout << "INSERTION" << endl;
		cout << "---------" << endl << endl;
		cout << "PROBE COUNTS" << setw(30) << "COMPARE COUNTS"
			 << setw(50) << "ELAPSED TIME (in microseconds)" << endl;

		tree.reset();
		buildTree(tree, size);

		cout << "------" << endl;
		cout << "SEARCH" << endl;
		cout << "------" << endl << endl;
		cout <<"PROBE COUNTS" << setw(30) << "COMPARE COUNTS"
			 << setw(50) << "ELAPSED TIME (in microseconds)" << endl;

		tree.reset();
		searchInTree(tree, size);
    }
}

void testAVL()
{
    cout << endl;
    cout << "************" << endl;
    cout << "* AVL TREE *" << endl;
    cout << "************" << endl;

    AvlTree tree;

    for (int size : VALUES)
    {
    	cout << "--------------------------------------------------------------------------------------------" << endl;
    	cout << setw(50) << "N = " << commafy(size) << endl;
    	cout << "--------------------------------------------------------------------------------------------" << endl;
		cout << "---------" << endl;
		cout << "INSERTION" << endl;
		cout << "---------" << endl << endl;
		cout << "PROBE COUNTS" << setw(30) << "COMPARE COUNTS"
			 << setw(50) << "ELAPSED TIME (in microseconds)" << endl;

		tree.reset();
		buildTree(tree, size);

		cout << "------" << endl;
		cout << "SEARCH" << endl;
		cout << "------" << endl << endl;
		cout << "PROBE COUNTS" << setw(30) << "COMPARE COUNTS"
			 << setw(50) << "ELAPSED TIME (in microseconds)" << endl;

		tree.reset();
		searchInTree(tree, size);
    }
}


void buildTree(BinarySearchTree& tree, int size)
{
    srand(time(NULL));

    for (int i = 1; i < size; i++)
    {
        int value = rand() % size;

        steady_clock::time_point start_time = steady_clock::now();

        tree.insert(value);

        steady_clock::time_point end_time = steady_clock::now();
        tree.increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());
    }

    statistics(tree);
}

void searchInTree(BinarySearchTree& tree, int size)
{
    srand(time(NULL));

    for (int i = 1; i < size; i++)
    {
        int value = rand() % size;

        steady_clock::time_point start_time = steady_clock::now();

        tree.contains(value);

        steady_clock::time_point end_time = steady_clock::now();
        tree.increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());
    }

    statistics(tree);
}

void statistics(BinarySearchTree& tree)
{
    cout << commafy(tree.get_probe_count());
    cout << setw(30) << commafy(tree.get_comparison_count());
    cout << setw(30) << commafy(tree.get_elapsed_time());
    cout << endl << endl;
}

string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
