#include<bits/stdc++.h>
using namespace std;

string reverseWords(string S)  { 
  string rev = "";
  
  for(int i = S.size() - 1; i >= 0; i--) {
      
      string temp = "";
      while(S[i] != '.' && i >= 0) temp += S[i--];
      
      reverse(temp.begin(), temp.end());
      
      rev = rev + temp;
      
      if(i != -1)
          rev += '.';
      
  }
  return rev;
} 