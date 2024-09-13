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
