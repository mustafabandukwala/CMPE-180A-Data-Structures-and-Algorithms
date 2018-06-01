#include <cstdlib>
#include <iostream>

using namespace std;

/*
  The Chevalier de Blasé, a notorious 17th century gambler, wanted to
  know whether he had higher odds of winning a dice game with four
  dice, where a win meant a pair of 5s and a pair of 6s, or a game
  with six dice, where a win meant four sixes (and two dice
  that are not a six).

  Help him out by writing a simulation that "throws" virtual dice
  with a random number generator.
*/

/*
  Return a random number between 1 and 6.
*/
int die_toss()
{
   return 1 + rand() % 6;
}

/*
  Return true if you got a pair of 5s and 6s.
*/
int game1_wins(int a, int b, int c, int d)
{
	int countFive=0, countSix=0;
	if(a == 5)
		countFive++;
	else if(a == 6)
		countSix++;
	if(b == 5)
		countFive++;
	else if(b == 6)
		countSix++;
	if(c == 5)
		countFive++;
	else if(c == 6)
		countSix++;
	if(d == 5)
		countFive++;
	else if(d == 6)
		countSix++;
	if((countFive == 2 && countSix == 2))
		return 1;
	else
		return 0;
}

/*
  Return true if you got four 6s.
*/
int game2_wins(int a, int b, int c, int d, int e, int f)
{
	int count=0;

	if(a == 6)
		count++;
	if(b == 6)
		count++;
	if(c == 6)
		count++;
	if(d == 6)
		count++;
	if(e == 6)
		count++;
	if(f == 6)
		count++;
	return (count == 4);
}

/*
  Play game 1 for the given number of iterations and return the
  number of wins.
*/
int game1(int iterations)
{
	int wins=0;
	for(int i=1; i<=iterations; i++)
	{
		if(game1_wins(die_toss(), die_toss(), die_toss(), die_toss()))
			wins++;
	}
	return wins;
}

/*
  Play game 2 for the given number of iterations and return the
  number of wins.
*/
int game2(int iterations)
{
	int wins=0;
	for(int i=1; i<=iterations; i++)
	{
		if(game2_wins(die_toss(), die_toss(), die_toss(), die_toss(), die_toss(), die_toss()))
			wins++;
	}
	return wins;
}
