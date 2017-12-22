// Author: Sean Davis
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "calendar.h"
#include "day.h"
#include "vector.h"
#include "DayOfWeek.h"

using namespace std;

Calendar::Calendar(): days(30)
{
} // create()


void Calendar::addAppointment()
{
  int pos, day, month, year;
  getDate(&day, &month, &year);
  Day obj(month, year, day);
  pos = days += obj;
  days[pos].addAppointment();
}  // addAppointment()


void Calendar::dateSearch() const
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);

  for(int i = 0; i < days.getCount(); i++)
    if(days[i] ==  dayTemp)
    {
      cout << days[i];
      return;
    } // if found matching date

  cout << "That date was not found.\n";
}  // dateSearch()


void Calendar::getDate(int *day, int *month, int *year) const
{
  while(true)
  {
    char line[80], line2[80], *ptr;
    cout << "\nPlease enter the month, day, and year (mm/dd/yyyy) >> ";

    if (! fgets(line, 80, stdin))
      cout << " is not a valid date.\nPlease try again.\n";
    else // User entered something
    {
      strtok(line, "\n");
      strcpy(line2, line);
      ptr = strtok(line, "/");

      if(ptr)
      {
        *month = atoi(ptr);
        ptr = strtok(NULL, "/");

        if(ptr)
        {
          *day = atoi(ptr);
          ptr = strtok(NULL, "\n");

          if(ptr)
            *year = atoi(ptr);
        } // if something before a second /
      } // if something before the first /

      if(*day >= 1 && *day <= 31 && *month >= 1 && *month <= 12
         && *year >= 1000 && *year <= 2017)
         break;

      cout << line2 << " is not a valid date.\nPlease try again.\n";
    } // else use entered something
  } // while invalid date
}  // getDate()


istream& operator>> (istream &is, Calendar &calendar)
{
  char line[80];
  int day, month, year, pos;
  is.getline(line, 80);  // get rid of label line;

  while(is.getline(line, 80, '/'))
  {
    month = atoi(line);
    is.getline(line, 80, '/');
    day = atoi(line);
    is.getline(line, 80, ',');
    year = atoi(line);
    Day obj(month, year, day);
    pos = calendar.days += obj;

    Appointment* appt = (is >> calendar.days[pos]);
    WeeklyAppointment* wappt = dynamic_cast <WeeklyAppointment*> (appt);

    if (wappt != NULL)
    {
      calendar.createSeries(*wappt, month, day, year);
    } // if it is a weekly Appointment

    
  } // while more lines in the file

  return is;
}  // operator>> ()


void Calendar::subjectSearch() const
{
  char subject[80];
  cout << "Please enter the subject >> ";
  fgets(subject, 80, stdin);

  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'

  cout << "Date                          Start End   Subject      Location\n";

  for(int i = 0; i < days.getCount(); i++)
    days[i].subjectSearch(subject);

  cout << "\n";
}  // subjectSearch()

void Calendar::createSeries(WeeklyAppointment &weekappt,
                            int month, int day, int year)
{
  ifstream is("DOW.dat", ios::binary);
  char sr[10];
  strcpy(sr, weekappt.getSeries());

  for (int ct = 0; ct < weekappt.getSeriesCount(); ct++)
  {
    DayOfWeek dayofweek(month, day, year);
    int dateNumber = (month - 1) * 31 + day - 1 + (year - 1990) * 372;
    is.seekg(dateNumber * sizeof(DayOfWeek));
    is.read((char*) &day, sizeof(DayOfWeek));

    for (int i = 0; sr[i] != '\0'; i++)
    {
      if (day == sr[i])
      {
        (days += weekappt);
      } // if the way is equal to the series
    } // for loop

    day = day + 7;

    if (day > 30)
    {
      month++;
      day = day - 30;
    } // if day > 30

    if (month > 12)
    {
      year++;
      month = month - 12;
    } // month > 12
  } // for loop
} // createSeries()
