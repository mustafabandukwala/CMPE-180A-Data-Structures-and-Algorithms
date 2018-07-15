/*******************************************************************************************
 * Name        : Book.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which implements all constructor, member function, overload operators.
 *******************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Book.h"

using namespace std;

/* Default constructor */
Book::Book()
{
	//Do nothing as string variables are pre-initialized
}

/* Parameterized constructor */
Book::Book(string isbn, string last, string first, string title, string category)
{
	this->isbn = isbn;
	this->last = last;
	this->first = first;
	this->title = title;
	this->category = category;
}

/* Destructor */
Book::~Book()
{
	//Do nothing
}

/* Accessor function that returns isbn */
string Book::get_isbn() const
{
	return isbn;
}

/* Accessor function that returns last name */
string Book::get_last() const
{
	return last;
}

/* Accessor function that returns first name */
string Book::get_first() const
{
	return first;
}

/* Accessor function that returns title */
string Book::get_title() const
{
	return title;
}

/* Accessor function that returns category */
string Book::get_category() const
{
	return category;
}

/* Overloading function for >> operator */
std::istream& operator >>(std::istream& ins, const vector<string>& catalog)
{
	string word;
	getline(ins, word);

	istringstream line(word);
	vector <string> record;

	while (line)
	{
		string s;
		if (!getline( line, word, ',' ))
			break;
		record.push_back( word );
	}
	return ins;
}

/* Overloading function for << operator */
std::ostream& operator <<(std::ostream& outs, const Book& output)
{
	outs << "Book{ISBN="<< output.isbn     << ", "
		  << "last="     << output.last 	   << ", "
		  << "first="    << output.first    << ", "
		  << "title="    << output.title    << ", "
		  << "category=" << output.category << "}";
	return outs;
}

/* Overloading function for << operator */
std::ostream& operator <<(std::ostream& outs, const vector<Book>& catalog)
{
	outs << "Book{ISBN="     << catalog[0].get_isbn()     << ", "
		  << "last="     	    << catalog[0].get_last() 	   << ", "
		  << "first="    	    << catalog[0].get_first()    << ", "
		  << "title="    	    << catalog[0].get_title()    << ", "
		  << "category=" 	    << catalog[0].get_category() << "}" << endl;
	return outs;
}
