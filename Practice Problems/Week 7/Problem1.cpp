----------------------------------------------------------------------------------------------------------------------------------------
ParseTime.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <cctype>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

/*
  Implement the following function to parse a string of the form
  xx:yy am or xx:yy pm and set the reference parameters hours and 
  minutes to military time (with hours between 0 and 23). \

  Here xx is either one or two digits between 1 and 12, and yy are
  two digits between 00 and 59. 

  If xx or yy are out of range (1-12 and 0-59 respectively), throw
  a std::range_error. 

  If the time string isn't long enough, throw an out_of_range exception.
  You can achieve that without any checking simply by calling
  string::at instead of string::operator[].

  If there is any other syntax error, throw a ParseError whose 
  what() message says "time not valid: " followed by the invalid 
  time string. 

  If you throw an exception, do not modify hours or minutes.
*/

class ParseError : public runtime_error
{
public:
   ParseError(const string& what);
};

ParseError::ParseError(const string& what) : runtime_error(what) {}

void parse_time(string time, int& hours, int& minutes)
{
   // Implementation without error checking
   bool flag = false;
   int length = time.length();
   if(length < 6) throw out_of_range(time);
   
   if(time[4] != ' ' && time[5] != ' ')
      flag = true;
   if(time[length-2] != 'a' && time[length-2] != 'p')
      flag = true;
   if(flag) throw ParseError("time not valid: " + time);
   int i = 1;
   if (isdigit(time[i]))
   {
      hours = 10 * (time[i - 1] - '0') + time[i] - '0';
      i++;
   } 
   else
   {
      hours = time[i - 1] - '0';
   }
   i += 2;
   minutes = 10 * (time[i - 1] - '0') + time[i] - '0';
   if((hours < 1 || hours > 12) || (minutes < 0 || minutes > 59)) throw range_error(time);
   i += 2;
   if (time[i] == 'a')
   {
      if (hours == 12)
         hours = 0;
   }
   else
   {
      if (hours != 12)
         hours += 12;
   }
}

----------------------------------------------------------------------------------------------------------------------------------------
Tester.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class ParseError : public runtime_error
{
public:
   ParseError(const string& what);
};

void parse_time(string time, int& hours, int& minutes);

void test(string time, int h, int m, string e)
{
   int hours = -1;
   int minutes = -1;
   try
   {
      parse_time(time, hours, minutes);
      cout << hours << ":" << minutes << endl;
      if (e == "") 
         cout << "Expected: " << h << ":" << m << endl;
      else
         cout << "Expected: " << e << endl;

   }
   catch (ParseError& ex) {
      cout << ex.what() << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (range_error& ex) {
      cout << "range_error" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (out_of_range& ex) {
      cout << "out_of_range" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (...)
   {
      cout << "Unexpected exception" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
}

int main()
{
   test("1:23 am", 1, 23, "");
   test("1:23 pm", 13, 23, "");
   test("12:23 pm", 12, 23, "");
   test("12:23 am", 0, 23, "");
   test("1:23 qm", -1, -1, "time not valid: 1:23 qm");
   test("1:23am", -1, -1, "time not valid: 1:23am");
   test("1:23 am ", -1, -1, "time not valid: 1:23 am");
   test("1:23", -1, -1, "out_of_range");
   test("1", -1, -1, "out_of_range");
   test("1:63 am", -1, -1, "range_error");
   test("0:13 am", -1, -1, "range_error");
   test("13:13 am", -1, -1, "range_error");

   return 0;
}
