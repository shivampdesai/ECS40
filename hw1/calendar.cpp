#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "day.h"
#include "calendar.h"


//allocates 30 days in calendar, makes size 30 and count = 0
void create(Calendar* calendar)
{
	calendar->days  =  (Day*)malloc(30 * sizeof(Day));
	calendar->size = 30;
	calendar->count = 0;
}


//reads through appt.csv line by line and parses the input through it.
void readFile(Calendar* Calendar)
{
  FILE* fp;
  fp = fopen("appts.csv", "r");
	char buf[80];
	char* parsedMonth;
	char* parsedDay;
	char* parsedYear;
	Day dayTemp;
	fgets(buf, 80, fp);
	while (fgets(buf, 80, fp) != NULL)
	{
		parsedMonth = strtok(buf, "/");
		short month = atoi(parsedMonth);
		parsedDay = strtok(NULL, "/");
		short day = atoi(parsedDay);
		parsedYear = strtok(NULL, ",");
		short year = atoi(parsedYear);
		create(&dayTemp, day, month, year);
		for (int i = 0; i < Calendar->count; ++i)
		{
			if (equal(&dayTemp, &Calendar->days[i]) == false)
				break;
		}
		for (int j = (Calendar->count) - 1 ; j >= 0; j--)
		{
			if (Calendar->count == Calendar->size)
				resize(Calendar);
			if (lessThan(&dayTemp, &Calendar->days[j]) == false)
			{
				Calendar->days[j + 1] = dayTemp;
				Calendar->count++;//increments count to account for new number
				break;
			}
		}
		read(Calendar->days);
	}
	fclose(fp);
}


//allocates an array of days that is twice as large as the current array and
//copies the old array to the new array
void resize(Calendar* Cal)
{

	Day* newDays = (Day*)malloc(2 * sizeof(Cal->days));
	for (int i = 0; i < Cal->count; ++i)//or count
		newDays[i] = Cal->days[i];
	free(Cal->days);
	Cal->days = newDays;

}


//reads and range checks for a valid date
bool getDate(short* month, short* day, short* year)//change to void
{
	if (*year > 1000 && *year < 2017)//1000
	{
		if (*month > 1 && *month < 12)
		{
			if (*day > 0 && *day < 31)
			{
				return true;
			}
			else//days are out of bounds
				return false;
		}
		else// months are out of bounds
			return false;
	}
		return false;//years are out of bonds
}


//creates a new day and uses equal for every day in the calendar pointer to
//find the corresponding day
void dateSearch(Calendar* calendar)
{

	Day dayTemp;
	char buf[20];
	printf("Please enter the month, day, and year (mm/dd/yyyy)\n>>");
	scanf("%s", buf);//need &?
	char* parsedPart = strtok(buf, "/");
	short month = atoi(parsedPart);
	parsedPart = strtok(NULL, "/");
	short day = atoi(parsedPart);
	parsedPart = strtok(NULL, ",");
	short year = atoi(parsedPart);
	if (getDate(&month, &day, &year) == false)
	{
		printf("%d/%d/%d is not a valid date.\nPlease try again.\n\n", month, day, year);
		printf("Please enter the month, day, and year (mm/dd/yyyy)\n>>");
		scanf("%s", buf);
	}
	create(&dayTemp, month, day, year);
	for (int i = 0; i <= calendar->count; ++i)//took away =
	{
		if (equal(&(calendar->days[i]), &dayTemp) == false)
		{
			print(&dayTemp);//day.cpp
		}
	}
}



//calls subjectSearch() in day.cpp with the address of the day and the subject
//string as parameters
void subjectSearch(Calendar* calendar)
{

	char sub[80];
	printf("Please enter the subject >> ");
	scanf("%s", sub);//need &?
	for (int i = 0; i <= calendar->count; i++)//should try count instead of size?

		subjectSearch(&calendar->days[i], sub);

}


//passes the address of the calendar to the destroy function in day.cpp
void destroy(Calendar* calendar)
{

	for (int i = 0; i < calendar->count; ++i)
		destroy(calendar[i].days);

}
