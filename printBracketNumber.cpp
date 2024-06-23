#include<bits/stdc++.h>
using namespace std;

vector<int> bracketNumbers(string str) {
  stack<pair<char, int>> stk;
  vector<int> ans;
  
  int openCnt = 0;
  
  for(int i = 0; i < str.size(); i++) {
      if(str[i] == '('){
          openCnt++;
          stk.push({'(',openCnt});
          ans.push_back(openCnt);
      }
      else if(str[i] == ')') {
          if(!stk.empty()) {
              int closeCnt = stk.top().second;
              ans.push_back(closeCnt);
              stk.pop();
          }
      }
  }
  return ans;   
}