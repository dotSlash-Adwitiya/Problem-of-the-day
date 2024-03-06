#include<bits/stdc++.h>
using namespace std;

// * RABIN KARP ALGORITHM, Solved in 25-30 mins
// * TC : O(N), SC : O(1)
vector <int> search(string pattern, string text)
{
  vector<int> v;
  int i = 0, j = 0;
  int ans = -1;
  while(i <= text.size() - pattern.size()) {
      
      // * If first char is matched
      if(text[i] == pattern[j]){
        
          // * Store the idx temporarily, coz its a possible ans
          int idx = i;
          ans = i;
          
          while(j < pattern.size() && text[idx] == pattern[j]){
              idx++;
              j++;
          }
          
          // * If traversed till the last index, Pattern is FOUND !
          if(j == pattern.size())
              v.push_back(ans+1);
              
          j = 0;
      }    
      i++;
  }
  
  return v;
}