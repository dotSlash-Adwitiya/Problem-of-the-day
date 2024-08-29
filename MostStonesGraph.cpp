#include<bits/stdc++.h>
using namespace std;

void dfs(int idx, int n, vector<bool> &vis, vector<vector<int>> &stones){
  vis[idx] = true;

  for(int i = 0; i < n; i++) {
      if(!vis[i]){
          // * Same row, means two stones(nodes) have same X-coordinate
          if(stones[idx][0] == stones[i][0])
              dfs(i, n, vis, stones);
          
          // * Same column, means two stones(nodes) have same Y-coordinate
          if(stones[idx][1] == stones[i][1])
              dfs(i, n, vis, stones);
      }
  }
}

int removeStones(vector<vector<int>>& stones) {
  int n = stones.size();
  vector<bool> vis(n, false);
  int connectedComponents = 0;
  for(int i = 0; i < n; i++) {
      // * Traverse all Components
      if(!vis[i]){
          dfs(i, n, vis, stones);
          connectedComponents++; // * If this block is executed, it will fully explore 1 complete component
      }
  }
  return n - connectedComponents;
}