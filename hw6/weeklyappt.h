#ifndef WEEKLYAPPT_H
#define WEEKLYAPPT_H

#include <iostream>
#include "appt.h"

using namespace std;

class WeeklyAppointment : public Appointment
{
  char series[8];
  int seriesCount;
public:
  WeeklyAppointment();
  WeeklyAppointment(WeeklyAppointment &rhs);
  using Appointment::clone();
  virtual WeeklyAppointment* clone() const
  { return (new WeeklyAppointment(*this)); }
  istream& read(istream& is);
  ostream& write(ostream& os);
  char* getSeries();
  int getSeriesCount();
  virtual write(ostream &os);
}; //  class WeeklyAppointment

#endif
