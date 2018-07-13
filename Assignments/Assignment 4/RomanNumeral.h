/*************************************************************************************************
 * Name        : RomanNumeral.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : Header file which contains all public and private member variables and functions.
 *************************************************************************************************/

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <iostream>
class RomanNumeral
{
private:
	int decimal; /* Private member variable that holds decimal value */
	std::string roman; /* Private member variable that holds roman value */
	/* Private member function that converts roman to a decimal value
	 * @Param - String containing roman value
	 */
	void to_decimal(std::string roman);
	/* Private member function that converts decimal to a roman value
	 * @Param - Integer containing decimal value
	 */
	void to_roman(int decimal); /* Private member function that converts decimal to a roman value */
public:
	RomanNumeral(); /* Default constructor */
	RomanNumeral(int decimal_value); /* Parameterized constructor for integer value */
	RomanNumeral(const std::string roman_value); /* Parameterized constructor for string value */

	/* Overloading function for + operator
	 * @param - Class object 1 for addition
	 * @param - Class object 2 for addition
	 */
	friend int operator +(const RomanNumeral& num1, const RomanNumeral& num2);

	/* Overloading function for - operator
	 * @param - Class object 1 for subtraction
	 * @param - Class object 2 for subtraction
	 */
	friend int operator -(const RomanNumeral& num1, const RomanNumeral& num2);

	/* Overloading function for * operator
	 * @param - Class object 1 for multiplication
	 * @param - Class object 2 for multiplication
	 */
	friend int operator *(const RomanNumeral& num1, const RomanNumeral& num2);

	/* Overloading function for / operator
	 * @param - Class object 1 for division
	 * @param - Class object 2 for division
	 */
	friend int operator /(const RomanNumeral& num1, const RomanNumeral& num2);

	/* Overloading function for == operator
	 * @param - Class object 1 for comparison
	 * @param - Class object 2 for comparison
	 */
	friend int operator ==(const RomanNumeral& num1, const RomanNumeral& num2);

	/* Overloading function for != operator
	 * @param - Class object 1 for comparison
	 * @param - Class object 2 for comparison
	 */
	friend int operator !=(const RomanNumeral& num1, const RomanNumeral& num2);

	/* Overloading function for << operator
	 * @param - Output stream
	 * @param - Class object to display in output
	 */
	friend std::ostream& operator <<(std::ostream& outs, const RomanNumeral& num);

	/* Overloading function for << operator
	 * @param - Input stream
	 * @param - Class object to read for input
	 */
	friend std::istream& operator >>(std::istream& ins, RomanNumeral& num);
};

#endif /* ROMANNUMERAL_H_ */
