// Modified From: Sean Davis

#ifndef APPT_H
#define	APPT_H

#include "time.h"

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;

  public:
    void destroy();
    bool equal(const char *subjectz) const;
    bool lessThan(const Appointment *appointment2) const;
    void print() const;
    void read();


}; // class Appointment

#endif	// APPT_H
