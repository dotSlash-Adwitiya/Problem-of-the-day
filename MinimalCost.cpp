#include<bits/stdc++.h>
using namespace std;

// * Recursive solution
int f(int i, int k, vector<int> &arr) {
  if(i == arr.size() - 1) return 0;

  int minCost = INT_MAX;
  for(int j = i + 1; j <= i + k and j < arr.size(); j++){
      int cost = abs(arr[j] - arr[i]) + f(j, k, arr);
      minCost = min(cost, minCost);
  }
  return minCost;
}
int minimizeCost(int k, vector<int>& arr) {
  return f(0, k, arr);
}

// * Memoization Optimization
int f(int i, int k, vector<int> &arr, vector<int> &dp) {
  if(i == arr.size() - 1) return 0;
  
  if(dp[i] != -1) return dp[i];
  
  int minCost = INT_MAX;
  for(int j = i + 1; j <= i + k and j < arr.size(); j++){
      int cost = abs(arr[j] - arr[i]) + f(j, k, arr, dp);
      minCost = min(cost, minCost);
  }
  return dp[i] = minCost;
}
int minimizeCost(int k, vector<int>& arr) {
  int n = arr.size();
  vector<int> dp(n, -1);
  return f(0, k, arr, dp);
}

// * Tabulation Optimization O(n*k) Time and O(n) space
int minimizeCost(int k, vector<int>& arr) {
  int n = arr.size();
  vector<int> dp(n, 0);
  
  for(int i = n-2; i >= 0; i--){
      int minCost = INT_MAX;
      for(int j = i + 1; j <= i + k and j < arr.size(); j++){
          int cost = abs(arr[j] - arr[i]) + dp[j];
          minCost = min(cost, minCost);
      }
      dp[i] = minCost;
  }
  
  return dp[0];
}