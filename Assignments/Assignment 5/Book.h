/*************************************************************************************************
 * Name        : Book.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : Header file which contains all public and private member variables and functions.
 *************************************************************************************************/

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

/**
 * The Book class.
 */
class Book
{
public:
	/**
	 * Book categories.
	 */
	enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

	/**
	 * Default constructor.
	 */
	Book();

	/**
	 * Parameterized Constructor.
	 */
	Book(string isbn, string last, string first, string title, string category);

	/**
	 * Destructor.
	 */
	~Book();

	/* Public member function that returns isbn */
	string get_isbn() const;

	/* Public member function that returns last name */
	string get_last() const;

	/* Public member function that returns first name */
	string get_first() const;

	/* Public member function that returns title */
	string get_title() const;

	/* Public member function that returns category */
	string get_category() const;

	/* Overloading function for << operator
	 * @param - Output stream
	 * @param - Class object to display the output
	 */
	friend std::ostream& operator <<(std::ostream& outs, const Book& output);

	/* Overloading function for << operator
	 * @param - Output stream
	 * @param - Vector object to display the output
	 */
	friend std::ostream& operator <<(std::ostream& outs, const vector<Book>& catalog);

	/* Overloading function for << operator
	 * @param - Input stream
	 * @param - Vector to read the input
	 */
	friend std::istream& operator >>(std::istream& ins, const vector<string>& catalog);


private:
	/* Private member variables */
	string isbn, last, first, title, category;
};

#endif
