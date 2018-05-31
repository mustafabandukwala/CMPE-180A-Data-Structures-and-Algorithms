/*
   Computes the smallest of four values.
*/
int min(int a, int b, int c, int d)
{
   int result = a;
   if (b < result) result = b;
   if (c < result) result = c;
   if (d < result) result = d;
   return result;
}

/*
   Computes the average of the middle values of four given values
   (that is, without the largest and smallest value).
   Hint: Use the given min function. You may also want to define a
   max helper function or take advantage of the fact that max can be 
   computed from the min of the negative values.
*/
double middle(int a, int b, int c, int d)
{
	double middleAverage = 0.0;
	middleAverage = (static_cast<double>(a + b + c + d) - (min(a, b, c, d) - min(-a, -b, -c, -d)))/2;
	return middleAverage;
}
