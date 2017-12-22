// Modified From: Sean Davis

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>

#include "time.h"

using namespace std;

bool Time::lessThan(const Time *time2) const
{
  return hour < time2->hour
    || (hour == time2->hour && minute < time2->minute);
} // lessThan()


void Time::print() const 
{
  if (hour <= 9)
  {
    if (minute <= 9)
      cout << "0" << hour << ":" << "0" << minute << " ";
    else // if minute already has a 0 at end like 10
      cout << "0" << hour << ":" << setw(2) << minute << " ";
  } //makes to 01 for 01 to 09
  
  else //hour greater than 9
  {
    if (minute <= 9)
      cout << setw(2) << hour << ":" << "0" << minute  << " ";
    else // if minute already has a 0 at end like 10 
      cout << setw(2) << hour << ":" << setw(2) << minute << " ";
  } // hour greater than 9

} // print()


void Time::read()
{
  char *ptr;

  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  ptr = strtok(NULL, ",");

  if(strchr(ptr, 'A'))
  {
    if (hour == 12)
      hour = 0;
  } //12 AM becomes 00:00

  if (strchr(ptr, 'P'))
  {
    if (hour == 12)
      hour = 12;
    else //12 PM should stay 12
      hour += 12;
  } //adds 12 to hour unless 12 PM

} // read()
