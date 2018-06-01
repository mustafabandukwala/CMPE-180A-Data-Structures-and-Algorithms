/*
  Write a function that converts US time with hours, minutes, seconds,
  am/pm to "decimal time". In decimal time, the day has ten "hours",
  of 100 "minutes" each, and each "minute" has 100 "seconds". Return
  a floating-point number whose integral part is the decimal hours
  and whose fractional part are 0.01 * decimal minutes + 0.0001 *
  decimal seconds. Round to the nearest decimal second. If the inputs
  are invalid, return -1.
*/

#include <math.h>
double decimal_time(int hours, int minutes, int seconds, bool pm)
{
	double totalTime=0;
	if(hours <= 0 || hours > 12)
		return -1;
	if(minutes < 0 || minutes > 59)
		return -1;
	if(seconds < 0 || seconds > 59)
		return -1;
	if(pm && hours != 12)
		hours += 12;
	else if(!pm && hours == 12)
	   hours = 0;
		
		return ((round((static_cast<double>(hours*3600 + minutes*60 + seconds)*100000)/86400))/10000);
}
