#ifndef TIME_H
#define TIME_H

typedef struct {
short hour;
short minute;
} Time;

void read(Time* time1);

void print(Time* time1);

bool lessThan(Time* time1, Time* time2);

#endif
