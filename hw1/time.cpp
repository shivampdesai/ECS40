#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "time.h"

//parses the time stored in the array to find the hour and minute
void read(Time* time1)//@205
{
	char* parsedHour;
	char* parsedMinute;
	char* parsedNonUsed;
	char* parsedConversion;
	//const char conversion[100];
	//char conversion;
	parsedHour = strtok(NULL,":");
  time1->hour = atoi(parsedHour);
  parsedMinute = strtok(NULL,":");
	time1->minute = atoi(parsedMinute);
	parsedNonUsed = strtok(NULL, " ");
	parsedConversion = strtok(NULL, ",");
	
	//conversion = atoi(parsedConversion);
	if (strcmp(parsedConversion,"PM") == true)
	{
		time1->hour = time1->hour + 12;
	}
	//FIXME:need to account for AM and PM
}


//prints the hour and minute stored in the time pointer
void print(Time* time1)//@330
{

	printf("%d:%d ", time1->hour, time1->minute);
	//printf("\n");
}


//checks if time1 is less than time2 and returns either true or false
bool lessThan(Time* time1, Time* time2)
{

	if (time1->hour > time2->hour)
  	{
    		return false;
  	}
  	else if (time1->hour < time2->hour)
  	{
   		return true;
  	}
  	else
  	{
    		if (time1->minute < time2->minute)
    		{
      			return true;
    		}
    		else
    		{
      			return false;
    		}
  	}

}
