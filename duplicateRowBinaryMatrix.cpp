#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
{ 
  vector<int> ans;
  
  map<vector<int>, int> ump;
  int rowNum = 0;
  
  for(auto & row: matrix) {
      vector<int> temp;
      for(int val : row) {
          temp.push_back(val);
      }
      if(ump.find(temp) != ump.end())
          ans.push_back(rowNum);
      else
          ump[temp] = rowNum;
      rowNum++;
  }
return ans;
} 