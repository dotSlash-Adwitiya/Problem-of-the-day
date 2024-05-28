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

int minimumCost(int n, int w, vector<int> &cost) {
  int minCost = INT_MAX, currCost = 0, currKgs = 0;
  helper(cost, 0, w, currCost, minCost);
  
  return (minCost == INT_MAX ? -1 : minCost);
}