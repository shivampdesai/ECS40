#ifndef INDEXPAGER_H
#define INDEXPAGER_H

#include <iostream>
#include <algorithm>
#include <map>
#include <set>

#include "pager.h"

class IndexPager : public Pager
{
  typedef map<string, int> WordInt;
  typedef multimap<int, int> IntLine;
public:
  virtual void read(istream &is);
}; // class IndexPager

#endif
