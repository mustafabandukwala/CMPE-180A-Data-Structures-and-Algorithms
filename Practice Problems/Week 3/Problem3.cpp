#include <iostream>
#include <cstring>

using namespace std;

/*
  Repeats a string n times and places it into a buffer, filling
  it up as much as possible, and providing a terminating 0. 
  Use strncpy. 
  @param str a string
  @param n an integer
  @param result a character array to hold the result
  @param sz the size of result
*/
void repeat(const char* str, int n, char result[], int sz)
{
   string tempStr;
	char repeatedString[sz];
	int i;
	//Concatenate str, n number of times into tempStr
	while(n > 0)
	{
	   tempStr.append(str);
	   n--;
	}
	//Copy the string tempStr to repeatedString
	for(i = 0; i < sz-1; i++)
	{
	   repeatedString[i] = tempStr[i];
	}
	repeatedString[i] = '\0';
	//Copy the string tempStr to result till size sz
	strncpy(result, repeatedString, sz);
}

int main()
{
   char results[28];
   char* r2 = results;
   char* r1 = results + 10;
   char* r4 = results + 21;
   char* r3 = results + 22;
   char* r5 = results + 26;
   strcpy(r5, "x");
   repeat("Hello", 2, r1, 11);
   repeat("Goodbye", 3, r2, 10);
   repeat("Goodbye", 3, r3, 4);
   repeat("HI", 10, r4, 1);
   cout << r1 << endl;
   cout << "Expected: HelloHello" << endl;   
   cout << r2 << endl;
   cout << "Expected: GoodbyeGo" << endl;
   cout << r3 << endl;
   cout << "Expected: Goo" << endl;
   cout << "\"" << r4 << "\"" << endl;
   cout << "Expected: \"\"" << endl;
   cout << "\"" << r5 << "\"" << endl;
   cout << "Expected: \"x\"" << endl;

   return 0;
}
