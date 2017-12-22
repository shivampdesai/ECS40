#ifndef APPT_H
#define	APPT_H
// Author: Sean Davis
#include <iostream>
#include "time.h"
#include "weeklyappt.h"

using namespace std;

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
  static int count;
public:
  Appointment();
  Appointment(const Appointment &appt);
  ~Appointment();
  void addAppointment();
  bool operator== (const char *subject) const;
  static int getCount();
  bool operator< (const Appointment &appointment2) const;
  friend ostream& operator<< (ostream &os, const Appointment &appointment);
  friend istream& operator>> (istream &is, Appointment &appointment);
  virtual Appointment* clone() const { return (new Appointment(*this)); }
  virtual istream& read(istream& is);
  virtual ostream& write(ostream& os);
}; // class Appoiintment
#endif	// APPT_H
