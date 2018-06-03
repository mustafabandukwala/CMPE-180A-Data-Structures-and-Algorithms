#include <cstdlib>
#include <iostream>

using namespace std;

/*
  Returns a random number between 0 and 1.
*/
double rand_double()
{
   return rand() * 1.0 / RAND_MAX;
}

/*
  The "Las Vegas" method of finding the area of a circle works 
  as follows. Consider a square with side length r with a 
  quarter circle inscribed, like in this ASCII art:

r .....
  |    ....
  |        ...
  |   (x,y)   .
  |  *         .
  |            .
  +------------.
(0, 0)         r

  Take a machine gun and fire bullets into the square. If 
  a bullet lands inside the quarter circle, it's a hit. Otherwise
  it's a miss. The ratio of hits to tries is proportional to 
  the ratio of the areas of the quarter circle and the square. 

  Generate random points (x, y) in the square. Check whether they 
  are inside the circle. Return the ratio of hits to tries.

 */
double inside_quarter_circle(double radius, int tries)
{
	double hits=0;
	for(int i=1; i<=tries; i++)
	{
      double x=0, y=0;
      x = rand_double();
      y = rand_double();
      x = x * radius;
      y = y * radius;
      if((x*x + y*y) < (radius*radius))
         hits++;
	}
	return (hits/tries);
}

int main()
{
   srand(42);
   cout << inside_quarter_circle(1, 1000) << endl;
   cout << inside_quarter_circle(20, 1000) << endl;
   // Approximating PI
   cout << 4 * inside_quarter_circle(1, 10000000) << endl;
}
