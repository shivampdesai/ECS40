// Modified From: Sean Davis

#ifndef DAY_H
#define	DAY_H

#include "appt.h"

class Day
{
  short day;
  short month;
  short year;
  Appointment *appts[8];
  short apptCount;

public:
    void create(const int day1, const int monthz, const int yearz);
    void destroy();
    bool equal(Day *day2) const;
    bool lessThan(Day *day2) const;
    void print() const;
    void read();
    void subjectSearch(const char *subject) const;

}; // class Day;


#endif	// DAY_H
