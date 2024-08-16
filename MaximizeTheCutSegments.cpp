#include<bits/stdc++.h>
using namespace std;

// * Recursive Solution
// * T.C: Near about O(3ⁿ)
int f(int targetSum, int x, int y, int z) {
  
  if(targetSum == 0) return 0;
      
  if(targetSum < 0) return INT_MIN;
  
  int a = 1 + f(targetSum - x, x, y, z);
  
  int b = 1 + f(targetSum - y, x, y, z);
  
  int c = 1 + f(targetSum - z, x, y, z);
  
  return max(a,max(b,c));
}

int maximizeTheCuts(int n, int x, int y, int z)
{
  if(x == 1 || y == 1 || z == 1)
      return n;
  return f(n, x, y, z);
}

// * Memoization OPTIMIZATION - 2D DP
int f(int targetSum, int x, int y, int z, vector<int> &dp) {
  
  if(targetSum == 0) return 0;
      
  if(targetSum < 0) return INT_MIN;
  
  if(dp[targetSum] != -1) return dp[targetSum];
  
  // * 1 + f() indicates a UNIT OF segment to be added in the length.
  int seg1 = 1 + f(targetSum - x, x, y, z, dp);
  
  int seg2 = 1 + f(targetSum - y, x, y, z, dp);
  
  int seg3 = 1 + f(targetSum - z, x, y, z, dp);
  
  return dp[targetSum] = max({seg1, seg2, seg3});
}

int maximizeTheCuts(int n, int x, int y, int z)
{
  if(x == 1 || y == 1 || z == 1)
      return n;
  vector<int> dp(n + 1, -1);
  int ans = f(n, x, y, z, dp);
  return (ans < 0 ? 0 : ans);
}