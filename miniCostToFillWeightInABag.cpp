#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> cost, int idx, int w, int &currCost, int &minCost) {
  if(w == 0) {
      minCost = min(minCost, currCost);
      return;
  }
  
  if(idx == cost.size() || w < 0)
      return;
  
  if(cost[idx] == -1)
      return;
      
  for(int i = idx; i < cost.size(); i++) {
    
    int tempIdx = i+1;
      
    if(w >= tempIdx) {
        
        w = w - tempIdx;
        currCost = currCost + cost[i];
        
        helper(cost, i, w, currCost, minCost);

        // * Backtrack and reduce index's value and cost
        w = w + tempIdx;
        currCost = currCost - cost[i];
    }
  }
}

// * Optimized Using memoization :
int helperMemoized(const vector<int> &cost, int w, vector<int> &memo) {
  if (w == 0) return 0;
  
  if (w < 0) return INT_MAX;

  if (memo[w] != -1) return memo[w];
  
  int minCost = INT_MAX;

  for (int i = 0; i < cost.size(); i++) {
      if (cost[i] != -1) { // *Call only if the currIdx != -1
          int tempIdx = i + 1;
          int result = helperMemoized(cost, w - tempIdx, memo);
          if (result != INT_MAX) {
              minCost = min(minCost, result + cost[i]);
          }
      }
  }
  
  memo[w] = minCost;
  return minCost;
}


int minimumCost(int n, int w, vector<int> &cost) {
  int minCost = INT_MAX, currCost = 0, currKgs = 0;
  helper(cost, 0, w, currCost, minCost);
  
  return (minCost == INT_MAX ? -1 : minCost);
}
