#include <iostream>
#include <algorithm>
#include <map>
#include <set>

#include "pager.h"
#include "indexpager.h"

void IndexPager::read(istream &is)
{

  string input, x;
  int line = 0;
  vector <string> all;
  vector <int> lines;
  WordInt wordint;
  IntLine intline;
  vector<string> words;

  int wordKey = 0;
  WordInt::const_iterator i8;

  while (getline(is, input))
  {
    for(string::const_iterator itr1 = input.begin(); itr1 != input.end(); ++itr1)
    {
      if (isalpha(*itr1) && !isspace(*itr1))
      {
        x += *itr1;
      }
      else
      {
        if (!x.empty())
        {
          if (wordint.find(x) == wordint.end())
          {
            wordint.insert(WordInt::value_type(x, wordKey));
            intline.insert(IntLine::value_type(wordKey, line));
            words.push_back(x);
          }
          else
          {
            i8 = wordint.find(x);
            intline.insert(IntLine::value_type(i8->second, line));
          }
          wordKey++;
        }
        x.clear();
      }
    }
    line++;
  }

  sort(words.begin(), words.end());

  string s;
  string num;
  int index = 0, wordi = 0;
  vector<int> numbers;

  WordInt::const_iterator i3;
  while (i3 != wordint.end())
  {
    i3 = wordint.find(words[wordi]);
    string s(i3->first);
    s.append(" ");

     for (IntLine::const_iterator i4 = intline.find(i3->second); i4 != intline.upper_bound(i3->second); i4++)
     {
        numbers.push_back(i4->second);
     }

     if (numbers[index] == numbers[index+1] - 1)
     {
       num.append(intToString(numbers[index]));
       num.append("-");
       num.append(intToString(numbers[index + 1]));
       s.append(num);
     }

     for(vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); ++i)
     {
       s.append(intToString(*i));
       if (i != (numbers.end() - 1))
        s.append(", ");
     }
     s.append(".");
     text.insert(text.end(), s);
     s.clear();
     numbers.clear();
     wordi++;
  }

} //read
