/***************************************************************************
 * Name        : Calculator.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Calculator
 ***************************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include "Calculator.h"
using namespace std;

int Calculator::openParanthesis = 0;
int Calculator::closeParanthesis = 0;

// Function to read character from the input stream
char Calculator::getInput()
{
	char ch;
	cin >> ch;
	return ch;
}

//Function performs expression functionality as per requirement
double Calculator::expression()
{
	double output = term();
	char ch;
	ch = getInput();

	if(ch == '+' || ch == '-')
	{
		char temp = ch;
		ch = getInput();
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
			throw runtime_error("***** Invalid factor");
		else
		{
			cin.unget();
			ch = temp;
		}
		double expressionOutput = expression();
		if(ch == '+')
			output = output + expressionOutput;
		else
			output = output - expressionOutput;
	}
	else
	{
		if (ch == '*' || ch == '/' || ch == '=' || ch == '(' || ch == ')')
			cin.unget();
		else
		{
			cin.unget();
			ch = getInput();
			string e = to_string(int(output)) + string("***** Unexpected ") + ch;
			throw runtime_error(e.c_str());
		}
	}
	return output;
}

//Function performs term functionality as per requirement
double Calculator::term()
{
	double output = factor();
	char ch;
	ch = getInput();

	if(ch == '*' || ch == '/' || ch == '^')
	{
		char temp = ch;
		ch = getInput();
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
			throw runtime_error("***** Invalid factor");
		else
		{
			cin.unget();
			ch = temp;
		}
		double expressionOutput = term();

		if(ch == '^')
			output = power(output, expressionOutput);
		else if(ch == '*')
			output = output * expressionOutput;
		else
		{
			if(expressionOutput == 0)
				throw runtime_error("***** Division by zero");
			else
				output = output / expressionOutput;
		}
	}
	else
	{
		if (ch == '+' || ch == '-' || ch == '=' || ch == '(' || ch == ')')
			cin.unget();
		else
		{
			cin.unget();
			ch = getInput();
			//cout << output << endl;
			string e = to_string(int(output)) + string("***** Unexpected ") + ch;
			throw runtime_error(e.c_str());
		}
	}
	return output;
}

//Function performs factor functionality as per requirement
double Calculator::factor()
{
	double output = 0;
	char ch;
	ch = getInput();
	if(ch == '(')
	{
		openParanthesis++;
		output = expression();
		ch = getInput();
		if(ch != ')')
		{
			string e = string("***** Missing )");
			throw runtime_error(e.c_str());
		}
		else
		{
			closeParanthesis++;
			ch = cin.peek();
			if(ch == ')')
			{
				closeParanthesis++;
				if(closeParanthesis > openParanthesis)
				{
					cout << output << endl;
					string e = string("***** Unexpected )");
					throw runtime_error(e.c_str());
				}
				else
					closeParanthesis--;
			}
		}
	}
	else if(isdigit(ch))
	{
		cin.unget();
		cin >> output;
	}
	else if(ch == '+')
	{
		cin >> output;
	}
	else if(ch == '-')
	{
		ch = getInput();
		if(ch == '(')
		{
			openParanthesis++;
			output = expression();
			output = (-1) * output;
			ch = getInput();
			if(ch != ')')
			{
				string e = string("***** Missing )");
				throw runtime_error(e.c_str());
			}
			else
			{
				closeParanthesis++;
				ch = cin.peek();
				if(ch == ')')
				{
					closeParanthesis++;
					if(closeParanthesis > openParanthesis)
					{
						string e = string("***** Unexpected )");
						throw runtime_error(e.c_str());
					}
					else
						closeParanthesis--;
				}
			}
		}
		else if(isdigit(ch))
		{
			cin.unget();
			cin >> output;
			output = (-1)*(output);
		}
	}
	else
	{
		string e = string("***** Unexpected ") + ch;
		throw runtime_error(e.c_str());
	}
	return output;
}

//Function performs power functionality as per requirement
double Calculator::power(double output, double expressionOutput)
{
	return pow(output, expressionOutput);
}
