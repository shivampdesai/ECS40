#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void findz(vector<string> &input, istream& is);
vector<string> erase(vector<string> &input, istream& is);
vector<string> replace(vector<string> &input,   istream& is);
vector<string> insertd(vector<string> &input,   istream &is);
vector<string> deletel(vector<string> &input,   istream& is);
vector<string> copypaste(vector<string> &in,   istream& is);
vector<string> move(vector<string> &in,   istream& is);

int main(int argc, char **argv)
{
  ifstream src(argv[1]); // switch these
  ifstream com(argv[2]); // two
  ofstream dest(argv[3]);

  string srcLine;
  char c;
  vector<string> output;
  string find;
  string buffer;

  while (getline(src, srcLine))
  {
    output.push_back(srcLine);
  } //adding lines to vector of string

  while(com >> c) //do while inf >> c instead
  {
    //cout << c << endl;
      switch(c)
      {
      case 'I':
        output = insertd(output, com);
        break;
      case 'R':
        output = replace(output, com);
        break;
      case 'F':
        findz(output, com);
        break;
      case 'D':
        output = deletel(output, com);
        break;
      case 'E':
        output = erase(output, com);
        break;
      case 'C':
        output = copypaste(output, com);
        break;
      case 'M':
        output = move(output, com);
        break;
      default:
        break;
       } // string
       //cout << c << endl;
       //getline(com, buffer);
  } // while loop

  for(vector<string>::const_iterator itr = output.begin();
     itr != output.end(); ++itr)
  {
      dest << *itr << endl;
  } //for loop

  dest.close();
  com.close();
  src.close();
  return 0;
} // main

void findz(vector<string> &input, istream& is)
{
  string com;
  is >> com;
  cout << com << " ";
  int line = 0;

  for(vector<string>::const_iterator itr = input.begin();
  itr != input.end(); ++itr)
  {
      int t = itr->find(com);

      if (t != -1)
        cout << line << " ";
      line++;
  } // for loop

  cout << endl;
} // find


vector<string> erase(vector<string> &input, istream& is)
{

  string buffer;
  string s;
  getline(is, s);
  s.erase(0, 1);

  vector<string> final;
  int len = s.length();
  int pos;
  //cout << s << endl;
  for(vector<string>::const_iterator itr = input.begin();
     itr != input.end(); ++itr)
  {
    buffer.assign(*itr);

    if (buffer.find(s) < buffer.length())
    {
      pos = buffer.find(s);
      buffer.erase(pos, len);
    } //if shorter

    final.push_back(buffer);
  } //for loop

  return final;

} // erase

vector<string> insertd(vector<string> &input, istream &is)
{
  string buffer;

  int line = 0;
  int pos;
  string change;

  int targetLine;
  is >> targetLine >> pos;

  getline(is, change);
  change.erase(0, 1);

  vector<string> final;

  for(vector<string>::const_iterator itr = input.begin();
     itr != input.end(); ++itr)
  {
    buffer.assign(*itr);

    if (line == targetLine)
      buffer.insert(pos, change); // needs to be final string (parse)

    final.push_back(buffer);
    line++;
  } //for loop

  return final;
} //insert

vector<string> replace(vector<string> &input, istream& is)
{
  int startpos; //parse this
  int endpos; // parse this
  int targetLine;
  string change;
  //FIGURE OUT HOW TO GET STARTPOS AND ENDPOS
  is >> targetLine >> startpos >> endpos;
  getline(is, change);
  change.erase(0, 1);

  int len = (endpos - startpos);
  vector<string> final;
  string buffer;
  int line = 0;


  for(vector<string>::const_iterator itr = input.begin();
     itr != input.end(); ++itr)
  {
  buffer.assign(*itr);

      if (line == targetLine)
      {
        buffer.replace(startpos, len, change);
      } //if same

      final.push_back(buffer);
      line++;
  } //for loop

  return final;
} //replace

vector<string> deletel(vector<string> &input, istream& is)
{
  int start; //FIGURE OUT HOW TO GET THIS
  int end; //FIGURE OUT HOW TO GET this
  int line = 0;
  is >> start >> end;
  vector<string> final;
  string buffer;

  for(vector<string>::const_iterator itr = input.begin();
     itr != input.end(); ++itr)
  {
    buffer.assign(*itr);

      if (line >= start && line <= end)
        buffer.erase(buffer.begin(), buffer.end());

      //cout << buffer.length() << endl;
      if (buffer.length() > 0)
        final.push_back(buffer);
      line++;
  } //for loop

  return final;

} //delete

vector<string> copypaste(vector<string> &in, istream& is)
{
  int start, end, dest, line1 = 0, line2 = 0;
  is >> start >> end >> dest;
  vector<string> f, final, c;
  string buffer1, buffer2, buffer3;

  for(vector<string>::const_iterator i1 = in.begin(); i1 != in.end(); ++i1)
  {
    buffer1.assign(*i1);

    if (line1 >= start && line1 <= end)
      c.push_back(buffer1);

    f.push_back(buffer1);
    line1++;
  } //for loop

  for(vector<string>::const_iterator i2 = f.begin(); i2 != f.end(); ++i2)
  {
    buffer2.assign(*i2);

    if (line2 == dest)
    {
      for(vector<string>::const_iterator i3 = c.begin(); i3 != c.end(); ++i3)
      {
        buffer3.assign(*i3);
        final.push_back(buffer3);
      } //for loop
    } // if same

    final.push_back(buffer2);
    line2++;
  } //for loop

  return final;
} //copy and paste

vector<string> move(vector<string> &in, istream& is)
{
  int start, end, dest, line1 = 0, line2 = 0;
  is >> start >> end >> dest;
  vector<string> f, final, c;
  string buffer1, buffer2, buffer3;

  for(vector<string>::const_iterator i1 = in.begin(); i1 != in.end(); ++i1)
  {
    buffer1.assign(*i1);

    if (line1 >= start && line1 <= end)
      c.push_back(buffer1);
    else //else
      f.push_back(buffer1);

    line1++;
  } //for loop

  for(vector<string>::const_iterator i2 = f.begin(); i2 != f.end(); ++i2)
  {
    buffer2.assign(*i2);

    if (line2 == dest)
    {
      for(vector<string>::const_iterator i3 = c.begin(); i3 != c.end(); ++i3)
      {
        buffer3.assign(*i3);
        final.push_back(buffer3);
      } //for loop
    } //if same

    final.push_back(buffer2);
    line2++;
  } //for loop

  return final;
} //move
