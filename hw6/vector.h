#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "calendar.h"
#include "day.h"

template<typename T>
class Vector
{
  T *array;
  int count;
  int size;
public:
  Vector();
  Vector(int sz);
  ~Vector();
  int getCount() const;
  const T& operator[] (int index) const;
  T& operator[] (int index);
  int operator+= (const T& obj);
}; //class Vector


#include "vector.cpp"

#endif
