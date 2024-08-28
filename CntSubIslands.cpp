#include<bits/stdc++.h>
using namespace std;

bool island = false;
void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis, int n, int m){
  // * Mark as visited
  vis[i][j] = 1;
  
  // * It is only considered a LAND if its 1 in both grids.
  if(grid1[i][j] != grid2[i][j]) 
      island = false;
  
  int delRow[] = {0, 0, 1, -1};
  int delCol[] = {1, -1, 0, 0};

  for(int k=0; k<4; k++){
      int nrow = i + delRow[k];
      int ncol = j + delCol[k];
      if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid2[nrow][ncol] == 1 && !vis[nrow][ncol])
          dfs(nrow, ncol, grid1, grid2, vis, n, m);
  }
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
  int count = 0;
  int n = grid2.size();
  int m = grid2[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));

  for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
          if(grid2[i][j] == 1 && !vis[i][j]){
              // assuming it is a sub-island
              island = true;
              dfs(i, j, grid1, grid2, vis, n, m);
              // if dfs does not mark island false then increment count
              if(island) count++;
          }
      }
  }
  return count;
}