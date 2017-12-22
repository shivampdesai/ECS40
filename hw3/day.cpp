// Modified From: Sean Davis

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "day.h"
#include "appt.h"

using namespace std;

void Day::create(int day1, int monthz, int yearz)
{
  day = day1;
  month = monthz;
  year = yearz;
  apptCount = 0;
}  // create()


void Day::destroy()
{
  for(int i = 0; i < apptCount; i++)
  {
    appts[i]->destroy();
    delete appts[i];
  } // for each appointment
}  // destroy()


bool Day::equal(Day *day2) const
{
  return day == day2->day && month == day2->month
    && year == day2->year;
} // equal()


bool Day::lessThan(Day *day2) const
{
  return (year < day2->year)
    || (year == day2->year && month < day2->month)
    || (year == day2->year && month == day2->month
      && day < day2->day);
} // lessThan()


void Day::print() const
{
  cout << "Start End   Subject      Location" << endl;

  for(int i = 0; i < apptCount; i++)
    appts[i]->print();

  cout << endl; //<< "\n";
} // print90

void Day::read()
{
  int pos;
  Appointment *appointment = new Appointment;

  appointment->read();

  for(pos = apptCount - 1;
    pos >= 0 && appointment->lessThan(appts[pos]); pos--)
      appts[pos + 1] = appts[pos];

  appts[pos + 1] = appointment;
  apptCount++;
} // read()


void Day::subjectSearch(const char *subject) const
{
  for(int i = 0; i < apptCount; i++)
    if(appts[i]->equal(subject))
    {
      if (month <= 9)
      {
        if (day <= 9)
        {
          cout << setw(2) << right << month << "/" <<
            setw(2) << right << day << "/" << setw(4) << year << " ";
        } //day single digit
        else //month single digit and day double digits
        {
          cout << setw(2) << right << month <<
            "/" << setw(2) << day <<
            "/" << setw(4) << year << " ";
        } //month single digit and day double digits
      } //single digit months
      else //double digit months
      {
        if (day <= 9)
        {
          cout << setw(2) << month <<
            "/" << setw(2) << right << day <<
            "/" << setw(4) << year << " ";
        } //day single digit
        else //day is double digits
        {
          cout << setw(2) << month << "/" << setw(2) <<
            day << "/" << setw(4) << year << " ";
        } //day is double digits
      }//double digit months

      appts[i]->print();
    } // if appointment has the subject

} // subjectSearch()
