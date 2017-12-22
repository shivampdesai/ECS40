#ifndef DAY_H
#define DAY_H

#include "appt.h"

typedef struct {

short day;
short month;
short year;
Appointment* appts[8];
short apptCount;
} Day;

void create(Day* dayTemp, short day, short month, short year);

bool equal(Day* day1, Day* day2);

bool lessThan(Day* day1, Day* day2);

void read(Day* day);

void print(Day* day);

void subjectSearch(Day* day, char* subject);

void destroy(Day* day);

#endif
