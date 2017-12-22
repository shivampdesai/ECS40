#include <iostream>
#include <string>
#include "weeklyappt.h"
#include "appt.h"

using namespace std;

WeeklyAppointment::WeeklyAppointment()
{
} //default constructor

WeeklyAppointment::WeeklyAppointment(WeeklyAppointment &rhs)
{
  strcpy(series, rhs.s);
  count = rhs.c;
} // copy constructor

istream& WeeklyAppointment::read(istream& is)
{
  read(is);
  char dayAppts[80];
  char seriesStr[80];

  is.getline(dayAppts, 80, ',');

  for (int i = 0; dayAppts[i] != '\0'; i++)
  {
    series[i] = dayAppts[i];
  } // assigns each character of dayAppts to day series in WeeklyAppointment

  is.getline(seriesStr, 80);
  seriesCount = atoi(seriesStr);
  return is;
} // read

char* WeeklyAppointment::getSeries()
{
  return series;
} // series accesor method

int getSeriesCount()
{
  return seriesCount;
} // count accesor method

ostream& WeeklyAppointment::write(ostream& os)
{
  Appointment* appt;
  WeeklyAppointment* wappt = dynamic_cast <WeeklyAppointment*> (appt);

  if (wappt != NULL)
  {
    cout << Appointment::write(ostream& os);
    cout << WeeklyAppointment::write(ostream& os);
  } // if
  else
  {
    cout << Appointment::write(ostream &os);
  } //else

  wappt.write(os) << left << setw(4) << series << right << seriesCount;
  return os;
} // write
