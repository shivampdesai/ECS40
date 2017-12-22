#include "calendar.h"
#include "day.h"
#include "appt.h"
#include "time.h"

#include <stdio.h>
#include <stdlib.h>


//prints the menu and prompts the user for the choice
int getChoice()
{
	int choice = 0;
  printf("Calendar Menu\n0. Done\n1. Search for Date.\
	\n2. Search for Subject.\n");
  printf("\nYour choice >> ");
  while (scanf("%d", &choice) != 0)
	{
	  if (choice == 0)
		  exit(0);
		else if (choice > 2)
			exit(0);
		else
		{
			return choice;
		}
	}
	return 0;
}


//declares a calendar which is then passed to create and readfile.
//Based on the users response in getChoice(), either subjectSearch or
//dateSearch is called.
int main()
{
  Calendar calendar;
	create(&calendar);
	readFile(&calendar);
	while (true)
	{
		int ans = getChoice();
		if (ans == 1)
		{
			//printf("date search activates at this point\n");
			//exit(0
		  dateSearch(&calendar);
		}
		else if (ans == 2)
		{
			subjectSearch(&calendar);
		}
		else if (ans == 0)
		{
			break;
		}
		else if (ans > 2)
		{
			break;
		}
	}
	destroy(&calendar);
}
