/*
  Write a function that computes how many digits two positive 
  integers m and n have in common. For example, if m is 112358 and
  n is 179881, then the result is 2 because the numbers have the digits
  1 and 8 in common. It does not matter how often a digit occurs.

  Hint: This loop yields all digits of a positive number n:

  while (n > 0)  
  {
     int digit = n % 10;
     n = n / 10;
     // Process digit
  }
*/

int digitsInCommon(int m, int n)
{   
   int digit1=0, digit2=0, temp=0;
	int zero=0, one=0, two=0, three=0, four=0, five=0, six=0, seven=0, eight=0, nine=0;
	while (n > 0)
	{
		int digit1 = n % 10;
		n = n / 10;
		temp=m;
		while(temp > 0)
		{
			int digit2 = temp % 10;
			temp = temp / 10;
			if (digit1 == digit2)
			{
				switch(digit1)
				{
				case 0:
					zero = 1;
					break;
				case 1:
					one = 1;
					break;
				case 2:
					two = 1;
					break;
				case 3:
					three = 1;
					break;
				case 4:
					four = 1;
					break;
				case 5:
					five = 1;
					break;
				case 6:
					six = 1;
					break;
				case 7:
					seven = 1;
					break;
				case 8:
					eight = 1;
					break;
				case 9:
					nine = 1;
					break;
				}
			}
		}
	}
	return (zero + one + two + three + four + five + six + seven + eight + nine);
}
