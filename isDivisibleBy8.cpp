#include<bits/stdc++.h>
using namespace std;

int DivisibleByEight(string s){
  
  int first = (s[s.size()-1]) - '0';
  
  // * If the size is one , then there's only 1 possiblity !
  if(s.size() == 1){
      if(s[0] != '8')
          return false;
      return true;
  }
  
  int sec = (s[s.size()-2]) - '0';
  
  // * If size is two, then we can simply 
  if(s.size() == 2){
      first = (s[s.size()-1]) - '0';
      sec = (s[s.size()-2]) - '0';
      
      sec = sec * 10 + first;
      
      return (sec % 8 == 0 ? 1 : -1);
  }
  
  int third = (s[s.size()-3]) - '0';
  
  
  third = third * 10 + sec;
  third = third * 10 + first;
  
  return ((third % 8  == 0) ? 1 : -1);
}