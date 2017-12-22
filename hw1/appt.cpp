#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "appt.h"
#include "time.h"//for read

//extracts the subject from the string, passes the address of time to read
//and copies location into location
void read(Appointment* appt)
{

  char* buf = NULL;
	char* parsedPart;// NULL didnt prevent seg fault
	char* parsedLocation;

	parsedPart = strtok(buf,",");
	appt->subject = (char*) malloc(sizeof((strlen(parsedPart))+1));
	strcpy(appt->subject, parsedPart);
	read(&appt->startTime);//time.cpp
	read(&appt->endTime);//time.cpp

	parsedLocation = strtok(NULL, "\n");
	appt->location = (char*) malloc(sizeof((strlen(parsedPart))+1));
	strcpy(appt->location, parsedLocation);

}


//checks if 2 appointments in a given day are equal
bool equal (char* appt1, char* appt2)
{

	if (strcmp(appt1, appt2) == 0)
	{
		return true;
	}
	else
		return false;

}


//passes address of starttime and endtime to print in time.cpp and prints
//the location
void print(Appointment* appt)
{

	print(&appt->startTime);//time.cpp
	print(&appt->endTime);
	printf("%s    %s", appt->subject, appt->location);

}


//checks is appointment 1 is earlier than appointment 2
bool lessThan(Appointment* appt1, Appointment* appt2)
{

	return (lessThan(&appt1->startTime, &appt2->startTime));

}


//deallocates memory for the subject and location for appointment
void destroy(Appointment* appt)
{

	free(&appt->subject);
	free(&appt->location);

}
