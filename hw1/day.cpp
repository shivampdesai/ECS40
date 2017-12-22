#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "day.h"
#include "appt.h"
#include "calendar.h"//added


//stores value of variables in their corresponding values in the day pointer
void create(Day* dayTemp, short day, short month, short year)
{
	dayTemp->day = day;
	dayTemp->month = month;
	dayTemp->year = year;
	dayTemp->apptCount = 0;
	
}


//checks if both the days are the same
bool equal(Day* day1, Day* day2)//this works
{

  if (day1->day == day2->day)
	{
		if (day1->month == day2->month)
		{
			if (day1->year == day2->year)
			{
			  return true;
			}
		}
	}
	else //day1 is not same as day2
	  return false;
	return false;
}


//checks if day1 is less than day2
bool lessThan(Day* day1, Day* day2)//may need backwards for loop
{
	if (day1->year < (day2->year))
		return true;
	else if (day1->year > (day2->year))
		return false;
	else //same year
	{
		if (day1->month < day2->month)
			return true;
		else if (day1->month < day2->month)
			return false;
		else //same month
		{
			if (day1->day < day2->day)
				return true;
			else
				return false;
		}
	}
	return true;
}


//allocates an appointment and passes its address of read() in appt.h
void read(Day* day)
{
	day->appts[day->apptCount] = (Appointment*)malloc(sizeof(Appointment));
	read(day->appts[day->apptCount]);
	for (int i = 0; i < day->apptCount; ++i)
	{
		if ((equal(&day[day->apptCount], &day[i])) == false)//false?
		{
			read(day->appts[i]);
			break;
		}
	}
	for (int j = (day->apptCount) - 1; j >= 0; j--)
	{
		if (lessThan(&day[day->apptCount], &day[j]))
		{
			day->appts[j + 1] = day->appts[day->apptCount];
			day->apptCount++;
			break;
		}
	}
}


//passes address of each appointment in day to print in appt.h
void print(Day* day)
{
	printf("Start End   Subject     Location\n");
	for (int i = 0; i <= day->apptCount; ++i)
	{

		print(day->appts[i]);
	}
}


//loops through the appts array and passes the subject and the string to
//equal()
void subjectSearch(Day* day, char* subject)
{
	printf("%s\n", subject);
	for (int i = 0; i < day->apptCount; ++i)
	{
		printf("%s\n", day->appts[i]->subject);
		if ((equal(day->appts[i]->subject, subject)) == 1)
			print(day->appts[i]);
	}

}


//passes address of each appointment to destroy in appt.h
void destroy(Day* day)
{

	for (int i = 0; i < day->apptCount; ++i)
		destroy(day->appts[i]);

}
