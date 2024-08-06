#include<bits/stdc++.h>
using namespace std;

int isValid(string str) {
int n = str.size();
  int dot = 0;
  string tmp = "";
  for (int i = 0; i < n; i++)
  {
      if (str[i] == '.')
      {
          dot++;
          if (tmp.empty() || (tmp[0] == '0' && tmp.size() > 1))
              return false;
          
          int num = stoi(tmp);
          
          if (num < 0 || num > 255) return false;
          
          tmp = "";
      }
      else tmp += str[i];
      
  }
  if (dot != 3)
      return false;
  if (tmp.empty() || (tmp[0] == '0' && tmp.size() > 1))
      return false;
  int num = stoi(tmp);
  if (num < 0 || num > 255)
      return false;
  return true;
}