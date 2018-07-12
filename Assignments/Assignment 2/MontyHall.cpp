//============================================================================
// Name        : MontyHall.cpp
// Author      : Mustafa Bandukwala
// Version     : 1.0
// Description : C++program that simulates the Monty Hall Problem to
//               demonstrate empirically whether it’s better to stay with an
//               original door choice or to switch doors
//============================================================================

#include <iostream>
#include <cstdlib>      //srand, rand
#include <ctime>        //time

using namespace std;

int main() 
{
	int i, carLocation=0, firstChoice=0, openedDoor=0, secondChoice=0, countFirst=0, countSecond=0;
	string firstWins="", secondWins="";
	cout << "  #" << "     Car" << "     First" << "     Opened" << "     Second" << "     Win" << "     Win" << endl;
	cout <<       "       here" << "    choice" << "       door" << "     choice" << "   first" << "  second" << endl << endl;
	for(i=1; i<=100; i++)
	{
		carLocation = (rand() % 3) + 1;
		//cout << "carLocation : " << carLocation << endl;
		firstChoice = (rand() % 3) + 1;
		//cout << "firstChoice : " << firstChoice << endl;
		if( carLocation == firstChoice )
		{
			while(1)
			{
				openedDoor = (rand() % 3) + 1;
				if(openedDoor != carLocation)
					break;
			}
		}
		else
		{
			while(1)
			{
				openedDoor = (rand() % 3) + 1;
				if((openedDoor != carLocation) && (openedDoor != firstChoice))
					break;
			}
		}
		//cout << "openedDoor  : " << openedDoor << endl;
		if(carLocation == firstChoice)
		{
			while(1)
			{
				secondChoice = (rand() % 3) + 1;
				if((secondChoice != carLocation) && (secondChoice != openedDoor))
					break;
			}
		}
		else
		{
			secondChoice = carLocation;
		}
		//cout << "secondChoice : " << secondChoice << endl;
		if(carLocation == secondChoice)
		{
			secondWins = "yes";
			countSecond++;
		}
		else
		{
			firstWins = "yes";
			countFirst++;
		}
		if(i < 10)
		{
			cout << "  "<< i << "       " << carLocation << "         " << firstChoice << "          ";
			cout << openedDoor << "          " << secondChoice << "     " << firstWins << "        " << secondWins << endl;
		}
		else if(i >= 10 && i <= 99)
		{
			cout << " " << i << "       " << carLocation << "         " << firstChoice << "          ";
			cout << openedDoor << "          " << secondChoice << "     " << firstWins << "        " << secondWins << endl;
		}
		else
		{
			cout << i << "       " << carLocation << "         " << firstChoice << "          ";
			cout << openedDoor << "          " << secondChoice << "     " << firstWins << "        " << secondWins << endl;
		}
		firstWins = "";
		secondWins = "";
	}
	cout << endl;
	cout << " " << countFirst << " wins if stay with the first choice" << endl;
	cout << " " << countSecond << " wins if stay with the second choice" << endl << endl;
	cout << "Win ratio of switch over stay: " << static_cast<double>(countSecond)/countFirst << endl;
	return 0;
}
