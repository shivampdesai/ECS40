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
    for(string::const_iterator itr1 = input.begin(); 
      itr1 != input.end(); ++itr1)
    {
      if (isalpha(*itr1) && !isspace(*itr1))
      {
        x += *itr1;
      } //if
      else //else
      {
        if (!x.empty())
        {
          if (wordint.find(x) == wordint.end())
          {
            wordint.insert(WordInt::value_type(x, wordKey));
            intline.insert(IntLine::value_type(wordKey, line));
            words.push_back(x);
          } //if 
          else //else
          {
            i8 = wordint.find(x);
            intline.insert(IntLine::value_type(i8->second, line));
          } //else

          wordKey++;
        } //else

        x.clear();
      } //else

    } //else

    line++;
  } //else

  sort(words.begin(), words.end());

  string s;
  string num;
  int index = 0, wordi = 0;
  vector<int> numbers;

  //bool consecutive = false; //added
  //int prevIndex; //added//previous value
  //int count = 1;
  
  WordInt::const_iterator i3;

  while (i3 != wordint.end())
  {
    i3 = wordint.find(words[wordi]);
    string s(i3->first);
    s.append(" ");

     for (IntLine::const_iterator i4 = intline.find(i3->second); 
       i4 != intline.upper_bound(i3->second); i4++)
     {
        numbers.push_back(i4->second);
     } //for loop

     if (numbers[index] == numbers[index + 1] - 1)
     {
       num.append(intToString(numbers[index]));
       num.append("-");
       num.append(intToString(numbers[index + 1]));
       s.append(num);
     } //if same

     //while(consecutive == false)
     //{
       //prevIndex = numbers[index - 1]; //prevIndex takes the value before numbers[index]

       //if (prevIndex - numbers[index] == 1)
       //{
         //count++;
       //} //if the previous value minus current value is 1 that means its consecutive
       //else //not consecutive number found
       //{
         //count = 0;
       //} //no consecutives

       //if (count == 0)
       //{
         //num.append(intToString(numbers[index]));
         //num.append("-");
         //num.append(intToString(numbers[index + 1]));
         //s.append(num);
         //consecutive = true;
       //} //now that you know, that not consecutive then you can print

     //} //once not consecutive then you know you can print dash

     for(vector<int>::const_iterator i = numbers.begin(); 
       i != numbers.end(); ++i)
     {
       s.append(intToString(*i));

       if (i != (numbers.end() - 1))
        s.append(", ");

       else //added
         s.append("."); //added

     } //for loop

     text.insert(text.end(), s);
     s.clear();
     numbers.clear();
     wordi++;
  } //while loop

} //read
