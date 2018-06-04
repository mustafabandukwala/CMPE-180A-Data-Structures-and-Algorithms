/**
   This program reads in the name of a file from stdin.
   Then it opens the file and reads all lines of the file.
   Each line has the form 

   label abbreviation value

   The label and abbreviation are nonempty strings without spaces. 
   The value is a floating-point number. 

   Print out the label and abbreviation with the smallest and 
   largest value, in a left-justified, field of width 50, 
   followed by the value in a right-justified field of width 10, with
   three digits after the decimal point. 
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
   cout << "Input file:" << endl;
   string input_file;
   cin >> input_file;
   ifstream in(input_file);
   
   double tempValue, smallestValue, largestValue;
   string tempLabel, smallestLabel, largestLabel;
   string finalString;
   string tempAbbreviation, smallestAbbreviation, largestAbbreviation;
   in >> tempLabel;
   in >> tempAbbreviation;
   in >> tempValue;
   smallestValue = tempValue;
   smallestLabel = tempLabel;
   smallestAbbreviation = tempAbbreviation;
   largestValue = tempValue;
   largestLabel = tempLabel;
   largestLabel = tempAbbreviation;
   
   while (!in.eof())
   {
      in >> tempLabel;
      in >> tempAbbreviation;
      in >> tempValue;
      if(tempValue < smallestValue)
      {
         smallestLabel = tempLabel;
         smallestAbbreviation = tempAbbreviation;
         smallestValue = tempValue;
      }
      if(tempValue > largestValue)
      {
         largestLabel = tempLabel;
         largestAbbreviation = tempAbbreviation;
         largestValue = tempValue;
      }
   }
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   finalString = smallestLabel + " " + smallestAbbreviation;
   cout.width(50);
   cout.fill(' ');
   cout << std::left << finalString;
   cout.width(12);
   cout.fill(' ');
   cout << std::right << smallestValue << endl;
   finalString = largestLabel + " " + largestAbbreviation;
   cout.width(50);
   cout.fill(' ');
   cout << std::left << finalString;
   cout.width(12);
   cout.fill(' ');
   cout << std::right << largestValue << endl;
   in.close();
   return 0;
}
