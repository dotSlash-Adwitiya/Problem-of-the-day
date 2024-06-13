#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;

int padovanSequenceR(int n) {
  if(n == 0 || n == 1 || n == 2)
      return 1;
  return padovanSequenceR(n-2) + padovanSequenceR(n-3);
}

int padovanSequence(int n)
{
  
  vector<int> dp(n + 1,0);
  
  dp[0] = dp[1] = dp[2] = 1;
  
  for(int i = 3; i <= n; i++) {
      dp[i] = (dp[i-2] + dp[i-3])%mod;
  }
  
  return dp[n];
}


