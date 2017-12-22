// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <string.h>
#include "DayOfWeek.h"

using namespace std;

DayOfWeek::DayOfWeek(int month1, int day1, int year1) : month(month1),
  day(day1), year(year1)
{
}  // DayOfWeek()


ostream& operator<< (ostream &os, const DayOfWeek &dow)
{
  char line[80], dayStr[3], yearStr[5];
  strcpy(line, dow.dayName);
  strcat(line, ", ");
  strcat(line, dow.monthName);
  strcat(line, " ");

  if (dow.day > 9)
  {
    dayStr[0] = dow.day / 10 + '0';
    dayStr[1] = dow.day % 10 + '0';
    dayStr[2] = '\0';
  } // if day > 9
  else // day < 10
  {
    dayStr[0] = dow.day + '0';
    dayStr[1] = '\0';
  } // else day < 10

  strcat(line, dayStr);
  strcat(line, ", ");

  if (dow.year <= 1999)
    yearStr[0] = dow.year / 1000 + '0';
  else // if <= 1999
    yearStr[0] = dow.year / 2000 + '0';

  yearStr[1] = ((dow.year / 100) % 10) + '0';
  yearStr[2] = ((dow.year / 10) - 100) % 10) + '0';
  yearStr[3] = ((((dow.year / 1000) % 100) % 10) + '0';

  yearStr[4] = '\0';
  strcat(line, yearStr);

  os << left << setw(30) << line << right;
  return os;
}  // operator<<()


istream& operator>> (istream &is, DayOfWeek &day)
{
  int dateNumber = (day.month - 1) * 31 + day.day - 1 +
  (day.year - 1990) * 372;
  is.seekg(dateNumber * sizeof(DayOfWeek));
  is.read((char*) &day, sizeof(DayOfWeek));
  return is;
}  // operator>>

bool DayOfWeek::operator== (char c)
{
  char dayOW[80];
  switch (c)
  {
    case 'M':
      strcat(dayOW, "Monday");
      break;
    case 'T':
      strcat(dayOW, "Tuesday");
      break;
    case 'W':
      strcat(dayOW, "Wednesday");
      break;
    case 'R':
      strcat(dayOW, "Thursday");
      break;
    case 'F':
      strcat(dayOW, "Friday");
      break;
    case 'S':
      strcat(dayOW, "Saturday");
      break;
    case 'U':
      strcat(dayOW, "Sunday");
      break;
  } // assigns dayOW based on character parameter

  if (strcmp(dayName, dayOW) == 0)
    return true;

  return false;
} // operator==
