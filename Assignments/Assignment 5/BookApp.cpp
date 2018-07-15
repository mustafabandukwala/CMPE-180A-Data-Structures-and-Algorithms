/*******************************************************************************************
 * Name        : RomanNumeral.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : Main file which performs all book operations.
 *******************************************************************************************/

#include "Book.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

/*
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, const vector<Book>& catalog);

/*
 * Function performs linear search called by search by word.
 * Use a linear search.
 * @param caller value.
 * @param value contains the string on which linear search will be performed.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found.
 */
int linearSearch(const string caller, const string value, const vector<Book>& catalog);

/*
 * Search the book as per the passed value.
 * Calls linearSearch function with appropriate values.
 * @param word which contains the string value to perform search operation.
 */
void searchByWord(string word);

/*
 * Insert new entry in the book Vector.
 * @param newEntry which contains the new Book object to be added in tht Book Vector.
 */
void insertIntoVector(Book& newEntry);

/*
 * Removes entry from the book Vector.
 * @param record the ISBN value.
 */
void removeFromVector(string record);

const string INPUT_FILE_NAME = "commands.in";

vector<Book> catalog;  // book catalog

/*
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
	// Open the input file.
	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	cout << endl;

	char command;

	/*
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{
		string word;
		input >> command;

		switch (command)
		{
		case '+':
		{
			if (!getline(input, word))
				break;

			istringstream line(word);
			vector <string> record;

			while (line)
			{
				string s;
				if (!getline( line, word, ',' ))
					break;
				record.push_back( word );
			}
			for(unsigned int i = 0; i < record[0].length(); i++)
			{
				if(record[0][i] == ' ')
					record[0].erase(i,1);
			}
			Book newEntry(record[0], record[1], record[2], record[3], record[4]);

			/* Call insertIntoVector function to insert value into the Book Vector */
			insertIntoVector(newEntry);
		}
		break;

		case '-':
		{
			input.get(command);
			if(command == ' ')
			{
				if (!getline(input, word))
					break;

				istringstream line(word);
				vector <string> record;

				while (line)
				{
					string s;
					if (!getline(line, word))
						break;
					record.push_back(word);
				}

				/* Call removeFromVector function to remove values from the Book Vector */
				removeFromVector(record[0]);
			}
		}
		break;

		case '?':
		{
			string word;
			if(!getline(input, word))
			   break;

			/* Call searchByWord function to search by input string */
			searchByWord(word);
		}
		break;

		/* Invalid Case */
		case '$':
			cout << "$ *** Invalid command ***" << endl << endl;
			break;
		}
	}
}

/* Find the book in the catalog with the given ISBN */
int find(const string isbn, const vector<Book>& catalog)
{
	int first = 0;
	int last = catalog.size() - 1;
	int mid;
	bool found = false;
	while(first <= last && !found)
	{
		mid = (first + last) / 2;
		if (catalog[mid].get_isbn() == isbn)
			found = true;
		else if (catalog[mid].get_isbn() > isbn)
			last = mid -1;
		else
			first = mid + 1;
	}
	cout << "? Book with ISBN " << isbn << ":" << endl;
	if (found)
	{
		cout << catalog[mid] << endl << endl;
	}
	else
		cout << endl;
	return 0;
}

/* Function performs linear search called by search by word */
int linearSearch(const string caller, const string value, const vector<Book>& catalog)
{
	if(caller == "author")
		cout << "? Books by author " << value << ":" << endl;
	else
		cout << "? Books in category " << value << ":" << endl;

	for(unsigned int i = 0; i < catalog.size(); i++)
	{
		if(caller == "author")
		{
			if(catalog[i].get_last() == value)
			{
				cout << catalog[i];
				cout << endl;
			}
		}
		else if(caller == "category")
		{
			if(catalog[i].get_category() == value)
			{
				cout << catalog[i];
				cout << endl;
			}
		}
	}
	cout << endl;
	return 0;
}

/* Search the book as per the passed value */
void searchByWord(string word)
{
	if(word.length() < 2)
	{
		cout << "? All books in the catalog:" << endl;
		for(unsigned int i = 0; i < catalog.size(); i++)
		{
			cout << catalog[i];
			cout << endl;
		}
		cout << endl;
	}
	if(word.length() > 2)
	{
		istringstream line(word);
		vector <string> record;

		while (line)
		{
			string s;
			if (!getline(line, word, '='))
				break;
			record.push_back( word );
		}

		for(unsigned int i = 0; i < record[0].length(); i++)
		{
			if(record[0][i] == ' ')
				record[0].erase(i,1);
		}

		if(record[0] == "isbn")
		{
			find(record[1], catalog);
		}
		else if(record[0] == "author")
		{
			linearSearch(record[0], record[1], catalog);
		}
		else if(record[0] == "category")
		{
			linearSearch(record[0], record[1], catalog);
		}
	}
}

/* Insert new entry in the book Vector */
void insertIntoVector(Book& newEntry)
{
	bool flag = false, duplicate = false;
	unsigned int i;
	if(catalog.size() == 0)
	{
		catalog.push_back(newEntry);
		cout << "+ Inserted at index 0: " << newEntry << endl << endl;
	}
	else
	{
		for(i = 0; i < catalog.size(); i++)
		{
			if(newEntry.get_isbn() < catalog[i].get_isbn())
			{
				catalog.insert(catalog.begin() + i, newEntry);
				flag = true;
				break;
			}
			if(newEntry.get_isbn() == catalog[i].get_isbn())
			{
				flag = true;
				duplicate = true;
				break;
			}
		}
		if(!flag)
		{
			catalog.push_back(newEntry);
			flag = false;
		}
		if(!duplicate)
			cout << "+ Inserted at index "<< i <<": " << newEntry << endl << endl;
		else
		{
			cout << "+ Inserted at index "<< i <<": " << newEntry << endl;
			cout << "*** Duplicate ISDN ***" << endl << endl;
		}
	}
}

/* Removes entry from the book Vector */
void removeFromVector(string record)
{
	bool flag = false;
	for(unsigned int i = 0; i < catalog.size(); i++)
	{
		if(record == catalog[i].get_isbn())
		{
			cout << "- Removed ";
			cout << catalog[i] << endl;
			cout << endl;
			flag = true;
			catalog.erase(catalog.begin() + i);
			break;
		}
	}
	if(!flag)
	{
		cout << "- Removed ";
		cout << "Book{ISBN="  << record << ", "
			  << "last="     	 << ", "
			  << "first="    	 << ", "
			  << "title="    	 << ", "
			  << "category=" 	 << "none}" << endl;
		cout << "*** Book not found ***" << endl << endl;
	}
}
