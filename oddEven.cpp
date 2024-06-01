#include<bits/stdc++.h>
using namespace std;

string oddEven(string s) {
    // code here9.
  
  int hash[26] = {0};
  int even=0, odd=0;
  
  for(int i = 0; i < s.size(); i++)
      hash[s[i] - 'a']++;
  
  
  for(int i = 0; i < 26; i++){
      if(hash[i] != 0) {
          char ch = (char)i+1; // * i + 1, for mapping, 1st char with 1, and 26th char with z (because of 0-based indexing)
          if(ch % 2 == 0 && hash[i] % 2 == 0)
              even++;
          else if(ch % 2 != 0 && hash[i] % 2 != 0)
              odd++;
      }
  }
  
  return ((even + odd) % 2 == 0 ? "EVEN" : "ODD");
}