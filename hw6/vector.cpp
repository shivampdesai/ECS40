#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "vector.h"
#include "day.h"
#include "calendar.h"


template<typename T>
Vector<T>::Vector()
{
} //default constructor

template<typename T>
Vector<T>::Vector(int sz) //: count(0), size(sz)
{
  array = new T[sz];
  count = 0;
  size = sz;
} // constructor

template<typename T>
Vector<T>::~Vector()
{
  delete[] array;
} // destructor

template<typename T>
int Vector<T>::getCount() const
{
  return count;
} // getCount()

template<typename T>
const T& Vector<T>::operator[] (int index) const
{
  return array[index];
} // operator[]

template<typename T>
T& Vector<T>::operator[] (int index)
{
  return array[index];
} // operator[]

template<typename T>
int Vector<T>::operator+= (const T& object)
{
  int pos;

  for(pos = 0;
     pos < getCount() && ! (object == array[pos]); pos++);

  if(pos == getCount()) // not found
  {
    if (getCount() == size)
      //resize
      {
        T *temp = new T[size * 2];

        for(int i = 0; i < getCount(); i++)
          temp[i] = array[i];

        delete [] array;
        array = temp;
        size *= 2;
      } //resize

    for(pos = getCount() - 1;
      pos >= 0 && object < array[pos]; pos--)
        array[pos + 1] = array[pos];

    array[++pos] = object;  // copy the new day into pos + 1
    count++;
  } // if not found

  return pos;
} // operator+=
