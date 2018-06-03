/*
   Computes the average of all nonnegative elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all nonnegative elements in a, or 0 if there are none.
*/

double nnavg(int a[], int alen)
{
   int count=0;
   double sum=0;
   for(int i=0; i<alen; i++)
   {
      if(a[i] >= 0)
      {
         sum += a[i];
         count++;
      }
   }
   if(sum > 0)
      return (sum/count);
   return 0;
}
