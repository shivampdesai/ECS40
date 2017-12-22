#ifndef APPT_H
#define APPT_H

#include "time.h"

typedef struct {

Time startTime;
Time endTime;
char* subject;
char* location;

} Appointment;

void read(Appointment* appt);

void print(Appointment* appt);

bool lessThan(Appointment* appt1, Appointment* appt2);

void destroy(Appointment* appt);

bool equal (char* appt1, char* appt2);

#endif
