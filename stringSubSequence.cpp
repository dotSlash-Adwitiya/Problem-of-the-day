#include<bits/stdc++.h>
using namespace std;

int mod = int(1e9) + 7;
// * Recursive Solution
void helper(string &s1, string &s2, string &temp, int idx, int &cnt){
  if(idx == s1.size()){
      if(s2 == temp)
          cnt = ((cnt+1)%mod);
      return;
  }
  
    
  temp += s1[idx];
  helper(s1, s2, temp, idx + 1, cnt);
  temp.pop_back();
  
  helper(s1, s2, temp, idx+1, cnt);
}

int countWays(string s1, string s2) {
  int cnt = 0;
  string temp = "";
  helper(s1, s2, temp, 0, cnt);
  return cnt;
}