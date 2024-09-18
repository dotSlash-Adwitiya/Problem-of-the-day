#include<bits/stdc++.h>
using namespace std;

bool checkPair(char first, char second) {
  if(first == '(' && second == ')')
      return true;
  if(first == '{' && second == '}')
      return true;
  if(first == '[' && second == ']')
      return true;
  return false;
}

bool ispar(string x) {
  int n = x.size();
  stack<char> stk;
  
  for(int i = 0; i < n; i++) {
      if(x[i] == '(' || x[i] == '{' || x[i] == '[')
          stk.push(x[i]);
      else {
          if(stk.empty())
              return false;
              
          else {
              if(checkPair(stk.top(), x[i]) == true)
                  stk.pop();
              else return false;
          }
      }
  }
  if(!stk.empty())
      return false;
  return true;
}
