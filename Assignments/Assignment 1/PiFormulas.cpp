//============================================================================
// Name        : PiFormulas.cpp
// Author      : Mustafa Bandukwala
// Version     : 1.0
// Description : This program will compute the value of Pi using several
//               formulas and an infinite series.
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	/* ********************************************* *
	 * Implementation of Ramanujan’s Formulas for Pi *
	 * ********************************************* */

	/* Double type variables used to calculate Ramanujan’s Formulas for Pi */
	double pi=0.0, pi15=0.0, pi16=0.0, pi18=0.0, pi22=0.0, pi31=0.0;

	/* Setting the precision to print various Ramanujan’s Formulas for Pi up to 15 decimal places */
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(15);

	/* Calculate Pi using the built-in atan function */
	pi = 4 * atan(1);
	cout << "pi   = " << pi << " = 4*arctan(1)" << endl << endl;

	/* Calculate accurate value of Pi till 15 decimal places using Ramanujan’s Formulas */
	pi15 = (12 / sqrt(130)) * log(((2 + sqrt(5)) * (3 + sqrt(13))) / sqrt(2));
	cout << "Ramanujan's pi formulas: " << endl;
	cout << "pi15 = " << pi15 << endl;

	/* Calculate accurate value of Pi till 16 decimal places using Ramanujan’s Formulas */
	pi16 = (24 / sqrt(142)) * log((sqrt((10 + (11 * sqrt(2))) / 4)) + (sqrt(((10 + 7 * sqrt(2)) / 4))));
	cout << "pi16 = " << pi16 << endl;

	/* Calculate accurate value of Pi till 18 decimal places using Ramanujan’s Formulas */
	pi18 = (12 / sqrt(190)) * log((2 * sqrt(2) + sqrt(10)) * (3 + sqrt(10)));
	cout << "pi18 = " << pi18 << endl;

	/* Calculate accurate value of Pi till 22 decimal places using Ramanujan’s Formulas */
	pi22 = (12 / sqrt(310)) * log(((3 + sqrt(5)) * (2 + sqrt(2)) * ((5 + (2 * sqrt(10))) + sqrt(61 + (20 * sqrt(10))))) / 4);
	cout << "pi22 = " << pi22 << endl;

	/* Calculate accurate value of Pi till 31 decimal places using Ramanujan’s Formulas */
	pi31 = (4 / sqrt(522)) * log((pow(((5 + sqrt(29)) / sqrt(2)), 3.0)) * ((5 * sqrt(29)) + (11 * sqrt(6))) * (pow((sqrt((9 + (3 * sqrt(6)))) / (sqrt(4)) + (sqrt((5 + (3 * sqrt(6)))) / (sqrt(4)))), 6.0)));
	cout << "pi31 = " << pi31 << endl << endl;

	/* ************************************************ *
	 * Implementation of Euler’s convergence towards Pi *
	 * ************************************************ */

	/* Float type variables used to calculate Euler’s convergence towards Pi */
	float eulerSum=0.0, endPoint=0.0, term=1.0;
	/* Integer type to calculate number of iterations */
	int iterations=1;

	/* Defining the end point as each term in Euler's series should be > 10^-8 */
	endPoint = pow(10, -8);

	/* 1. Calculate Euler's sum by adding terms as long as each term is > 10^-8
	 * 2. To compute the square of the next integer, add the next odd number to the square of the previous integer */
	while((1 / term) > endPoint)
	{
		eulerSum = eulerSum + (1 / term);
		term = term + (2 * iterations) + 1;
		iterations++;
	}

	/* Setting the precision to print Euler's infinite sum for
	 * Pi*Pi/6 and it's converged value up to 7 decimal places */
	cout.precision(7);
	cout << "Euler's infinite sum for pi*pi/6 = " << (pi * pi)/6 << endl;
	cout << "                      Converged to " << eulerSum << " after " << iterations << " iterations" << endl << endl;
	cout << "Euler's estimate for pi = " << sqrt(eulerSum * 6) << endl;

	/* Setting the precision to calculate error up to 10 decimal places by subtracting
	 * Euler's value of Pi from actual value of Pi obtained using atan function */
	cout.precision(10);
	cout << "                  error = " << pi - sqrt(eulerSum * 6);

	return 0;
}
