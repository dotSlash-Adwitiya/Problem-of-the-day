#include<bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
  int cnt = 0;
  int hash[26] = {0};

  for(const char &ch : allowed) 
      hash[ch - 'a']++;
  
  for(const string &word : words){
      bool consistent = true;
      for(int i = 0; i < word.size(); i++){
          if(hash[word[i] - 'a'] == 0){
              consistent = false;
              break;
          }
      }
      if(consistent)
          cnt++;
  }
  return cnt;
}