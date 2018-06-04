#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

/*
  Return a pointer to the nth occurrence of a repeated character
  in the given string. For example, if str is "occurrence" and n is 2,
  return a pointer to the first r.
*/

const char* nthrep(const char* str, int n)
{
	int count = 0;
	char ch = '\0';
	const char *result = str;
	//Calculate the size of string
	while(str[count] != '\0')
		count++;
	//Find two consecutive characters of a string
	//and also check whether the repeated character
	//was different from the new found	
	for(int i = 0; i < count - 1; i++)
	{
		if(str[i] == str[i+1] && ch != str[i])
		{
		   ch = str[i];
			   n--;
			if(n == 0)
				break;
		}
		result++;
	}
	if(n > 0)
	   return NULL;
	return result;
}

int main()
{
   const char* p = "occurrence";
   const char* r = nthrep(p, 1);
   cout << r - p << endl;
   cout << "Expected: 1" << endl;
   r = nthrep(p, 2);
   cout << r - p << endl;
   cout << "Expected: 4" << endl;
   r = nthrep(p, 3);
   cout << boolalpha << (r == NULL) << endl;
   cout << "Expected: true" << endl;
   p = "abbaccccaddabbra";
   r = nthrep(p, 2);
   cout << r - p << endl;
   cout << "Expected: 4" << endl;
   r = nthrep(p, 3);
   cout << r - p << endl;
   cout << "Expected: 9" << endl;
}
