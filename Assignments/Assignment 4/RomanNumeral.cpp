/*******************************************************************************************
 * Name        : RomanNumeral.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which implements all constructor, member function, overload operators.
 *******************************************************************************************/

#include <iostream>
#include <vector>
#include <string.h>
#include "RomanNumeral.h"

using namespace std;

/* Default constructor */
RomanNumeral::RomanNumeral()
{
	roman = "";
	decimal = 0;
}

/* Parameterized constructor for integer value */
RomanNumeral::RomanNumeral(int decimal_value)
{
	decimal = decimal_value;
	to_roman(decimal);
}

/* Parameterized constructor for string value */
RomanNumeral::RomanNumeral(const std::string roman_value)
{
	roman = roman_value;
	to_decimal(roman);
}

/* Overloading friend function for + operator*/
int operator +(const RomanNumeral& num1, const RomanNumeral& num2)
{
	return(num1.decimal + num2.decimal);
}

/* Overloading friend function for - operator*/
int operator -(const RomanNumeral& num1, const RomanNumeral& num2)
{
	return(num1.decimal - num2.decimal);
}

/* Overloading friend function for * operator*/
int operator *(const RomanNumeral& num1, const RomanNumeral& num2)
{
	return(num1.decimal * num2.decimal);
}

/* Overloading friend function for / operator*/
int operator /(const RomanNumeral& num1, const RomanNumeral& num2)
{
	return(num1.decimal / num2.decimal);
}

/* Overloading friend function for == operator*/
int operator ==(const RomanNumeral& num1, const RomanNumeral& num2)
{
	return(num1.decimal == num2.decimal);
}

/* Overloading friend function for != operator*/
int operator !=(const RomanNumeral& num1, const RomanNumeral& num2)
{
	return(num1.decimal != num2.decimal);
}

/* Overloading friend function for << operator*/
std::ostream& operator <<(std::ostream& outs, const RomanNumeral& num)
{
	outs << "[" << num.decimal << ":" << num.roman << "]";
	return outs;
}

/* Overloading friend function for >> operator*/
std::istream& operator >>(std::istream& ins, RomanNumeral& num)
{
	ins >> num.roman;
	num.to_decimal(num.roman);
	return ins;
}

/* Private member function that converts roman to a decimal value */
void RomanNumeral::to_decimal (std::string romanNumerals)
{
	int i = 0;
	int result = 0;
	vector<int> romanArary;
	while (romanNumerals[i] != '\0')
	{
		switch (romanNumerals[i])
		{
		case 'M':
			romanArary.push_back(1000);
			//result += 1000;
			break;
		case 'D':
			romanArary.push_back(500);
			//result += 500;
			break;
		case 'C':
			romanArary.push_back(100);
			//result += 100;
			break;
		case 'L':
			romanArary.push_back(50);
			//result += 50;
			break;
		case 'X':
			romanArary.push_back(10);
			//result += 10;
			break;
		case 'V':
			romanArary.push_back(5);
			//result += 5;
			break;
		case 'I':
			romanArary.push_back(1);
			//result += 1;
			break;
		}
		i++;
	}
	if (i > 1)
	{
		for (int j = 0; j < romanArary.size(); j++)
		{
			if(j != romanArary.size() - 1)
			{
				if (romanArary[j] < romanArary[j+1])
				{
					result = result + romanArary[j+1] - romanArary[j];
					j++;
				}
				else
				{
					result += romanArary[j];
				}
			}
			else
			{
				result += romanArary[j];
			}
		}
	}
	decimal = result;
}

/* Private member function that converts decimal to a roman value */
void RomanNumeral::to_roman (int decimal)
{
	vector < int >romanNumberArary;
	vector < string > romanStringArary;
	std::string romanString;
	if (decimal > 10)
	{
		romanNumberArary.push_back (decimal % 10);
		decimal = decimal - (decimal % 10);
		if (decimal > 100)
		{
			romanNumberArary.push_back (decimal % 100);
			decimal = decimal - (decimal % 100);
			if (decimal > 1000)
			{
				romanNumberArary.push_back (decimal % 1000);
				decimal = decimal - (decimal % 1000);
			}
		}
	}
	romanNumberArary.push_back (decimal);
	for (int i = romanNumberArary.size () - 1; i >= 0; i--)
	{
		switch (i)
		{
		case 3:
			while (romanNumberArary[i] > 0)
			{
				romanStringArary.push_back ("M");
				romanNumberArary[i] = romanNumberArary[i] - 1000;
			}
			break;
		case 2:
			switch (romanNumberArary[i])
			{
			case 100:
				romanStringArary.push_back ("C");
				break;
			case 200:
				romanStringArary.push_back ("C");
				romanStringArary.push_back ("C");
				break;
			case 300:
				romanStringArary.push_back ("C");
				romanStringArary.push_back ("C");
				romanStringArary.push_back ("C");
				break;
			case 400:
				romanStringArary.push_back ("C");
				romanStringArary.push_back ("D");
				break;
			case 500:
				romanStringArary.push_back ("D");
				break;
			case 600:
				romanStringArary.push_back ("D");
				romanStringArary.push_back ("C");
				break;
			case 700:
				romanStringArary.push_back ("D");
				romanStringArary.push_back ("C");
				romanStringArary.push_back ("C");
				break;
			case 800:
				romanStringArary.push_back ("D");
				romanStringArary.push_back ("C");
				romanStringArary.push_back ("C");
				romanStringArary.push_back ("C");
				break;
			case 900:
				romanStringArary.push_back ("C");
				romanStringArary.push_back ("M");
				break;
			}
			break;
			case 1:
				switch (romanNumberArary[i])
				{
				case 10:
					romanStringArary.push_back ("X");
					break;
				case 20:
					romanStringArary.push_back ("X");
					romanStringArary.push_back ("X");
					break;
				case 30:
					romanStringArary.push_back ("X");
					romanStringArary.push_back ("X");
					romanStringArary.push_back ("X");
					break;
				case 40:
					romanStringArary.push_back ("X");
					romanStringArary.push_back ("L");
					break;
				case 50:
					romanStringArary.push_back ("L");
					break;
				case 60:
					romanStringArary.push_back ("L");
					romanStringArary.push_back ("X");
					break;
				case 70:
					romanStringArary.push_back ("L");
					romanStringArary.push_back ("X");
					romanStringArary.push_back ("X");
					break;
				case 80:
					romanStringArary.push_back ("L");
					romanStringArary.push_back ("X");
					romanStringArary.push_back ("X");
					romanStringArary.push_back ("X");
					break;
				case 90:
					romanStringArary.push_back ("X");
					romanStringArary.push_back ("C");
					break;
				}
				break;
				case 0:
					switch (romanNumberArary[i])
					{
					case 1:
						romanStringArary.push_back ("I");
						break;
					case 2:
						romanStringArary.push_back ("I");
						romanStringArary.push_back ("I");
						break;
					case 3:
						romanStringArary.push_back ("I");
						romanStringArary.push_back ("I");
						romanStringArary.push_back ("I");
						break;
					case 4:
						romanStringArary.push_back ("I");
						romanStringArary.push_back ("V");
						break;
					case 5:
						romanStringArary.push_back ("V");
						break;
					case 6:
						romanStringArary.push_back ("V");
						romanStringArary.push_back ("I");
						break;
					case 7:
						romanStringArary.push_back ("V");
						romanStringArary.push_back ("I");
						romanStringArary.push_back ("I");
						break;
					case 8:
						romanStringArary.push_back ("V");
						romanStringArary.push_back ("I");
						romanStringArary.push_back ("I");
						romanStringArary.push_back ("I");
						break;
					case 9:
						romanStringArary.push_back ("I");
						romanStringArary.push_back ("X");
						break;
					}
					break;
		}
	}
	for (const auto &copyString : romanStringArary)
		romanString += copyString;
	roman = romanString;
}
