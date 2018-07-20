/**********************************************************************************
 * Name        : Test.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains main function to test Calculator functionality
 **********************************************************************************/

#include <iostream>
#include <cstring>
#include "Calculator.h"
using namespace std;

int main()
{
	bool pointFound = false;
	Calculator calculate;
	cout << "Expression? ";
	char ch = cin.peek();

	while (ch != '.')
	{
		try
		{
			cout << calculate.expression() << endl;
		}
		catch(exception &e)
		{
			int index = 0, findPoint = 0;
			pointFound = false;
			string errorValue = e.what();
			while(errorValue[findPoint] != '\0')
			{
				if(errorValue[findPoint] == '.')
				{
					pointFound = true;
					break;
				}
				findPoint++;
			}
			if(!pointFound)
			{
				while(errorValue[index] != '*')
				{
					if(errorValue[index] == '0')
						index++;
					cout << errorValue[index];
					index++;
				}
				if(index > 0)
					cout << endl;
				while(errorValue[index] != '\0')
				{
					cout << errorValue[index];
					index++;
				}
				string str;
				getline(cin,str,'\n');
				cout << endl;
			}
		}

		if(pointFound)
			break;
		cout << endl << "Expression? ";
		cin.clear();
		fflush(stdin);
		ch = cin.peek();
		if (ch == '=')
			cin >> ch;
	}
	cout << endl << "Done!";
}
