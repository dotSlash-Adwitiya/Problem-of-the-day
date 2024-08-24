#include<bits/stdc++.h>
using namespace std;

// * Recursion
int f(int idx, int W, vector<int>& wt, vector<int>& val){
  if(W < 0) return 0;
  
  if(idx == 0){
      if(W - wt[0] >= 0)
          return val[0];
      return 0;
  }
  
  int pick = 0, notPick = 0;
  
  if(W - wt[idx] >= 0)
      pick = val[idx] + f(idx - 1, W - wt[idx], wt, val);
  notPick = f(idx - 1, W, wt, val);
  
  return max(pick, notPick);
}
int knapSack(int W, vector<int>& wt, vector<int>& val) {
  int n = val.size();
  return f(n - 1, W, wt, val);
}

// * Memoization
int f(int idx, int W, vector<int>& wt, vector<int>& val, vector<vector<int>> &dp){
  if(W < 0) return 0;
  
  if(idx == 0){
      if(W - wt[0] >= 0)
          return val[0];
      return 0;
  }
  
  if(dp[idx][W] != -1) return dp[idx][W];
      
  
  int pick = 0, notPick = 0;
  
  if(W - wt[idx] >= 0)
      pick = val[idx] + f(idx - 1, W - wt[idx], wt, val, dp);
  notPick = f(idx - 1, W, wt, val, dp);
  
  return dp[idx][W] = max(pick, notPick);
}
int knapSack(int W, vector<int>& wt, vector<int>& val) {
  int n = val.size();
  vector<vector<int>> dp(n, vector<int>(W+1, -1));
  return f(n - 1, W, wt, val, dp);
}

// * Tabulation
int knapSack(int W, vector<int>& wt, vector<int>& val) {
  int n = val.size();
  vector<vector<int>> dp(n, vector<int>(W+1, 0));
  
  for(int cW = wt[0]; cW <= W; cW++)
  dp[0][cW] = val[0];
  
  for(int idx = 1; idx < n; idx++){
      for(int cW = 1; cW <= W; cW++){
            int pick = 0, notPick = 0;
          
          if(cW - wt[idx] >= 0)
              pick = val[idx] + dp[idx - 1][cW - wt[idx]];
          notPick = dp[idx - 1][cW];
          
          dp[idx][cW] = max(pick, notPick);
      }
  }
  
  return dp[n - 1][W];
}

int main()
{
    int n = 1, W = 0;
  //  vector<vector<int>> dp(n, vector<int> (m, -1));
}