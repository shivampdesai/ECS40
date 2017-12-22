#ifndef CALENDAR_H
#define CALENDAR_H

#include "day.h"

typedef struct {
  Day* days;
  int size;
  int count;
} Calendar;

void create(Calendar* calendar);

void readFile(Calendar* calendar);

void resize(Calendar* Cal);

void dateSearch(Calendar* calendar);

bool getDate(short* month, short* day, short* year);

void subjectSearch(Calendar* calendar);

void destroy(Calendar* calendar);

#endif
