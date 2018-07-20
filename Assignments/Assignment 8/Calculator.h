/***************************************************************************
 * Name        : Calculator.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Calculator
 ***************************************************************************/
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

class Calculator
{
    public:
        double expression(); //Function performs expression functionality as per requirement
        double term(); //Function performs term functionality as per requirement
        double factor(); //Function performs factor functionality as per requirement
        double power(double, double); //Function performs power functionality as per requirement
        char getInput(); // Function to read character from the input stream
        static int openParanthesis;
        static int closeParanthesis;
};

#endif /* CALCULATOR_H_ */
