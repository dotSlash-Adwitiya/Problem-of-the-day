#include<bits/stdc++.h>
using namespace std;

// * BRUTE FORCE Approach
// * T.C: O(Q*N)
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
  vector<int> xorAns;
  
  for(const auto &query : queries) {
      int left = query[0];
      int right = query[1];
      int x = 0;
      for(int i = left; i <= right; i++)
          x ^= arr[i];
      xorAns.push_back(x);
  }
  return xorAns;
}

// * OPTIMISED Approach
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
  vector<int> xorAns;
  
  for(int i = 1; i < arr.size(); i++)
      arr[i] ^= arr[i - 1];

  for(const auto &query : queries) {
      int left = query[0];
      int right = query[1];

      if(left != 0) xorAns.push_back(arr[left - 1] ^  arr[right]);
      else xorAns.push_back(arr[right]);
      
  }
  return xorAns;
}