#include<bits/stdc++.h>
using namespace std;

int f(int row, vector<vector<int>>& grid, unordered_set<int> &ds) {
  if (row >= grid.size()) return 0;

  int maxScore = 0;
  bool skipRow = true;
  for (int col = 0; col < grid[0].size(); col++) {
      if (ds.find(grid[row][col]) == ds.end()) {
          skipRow = false;
          ds.insert(grid[row][col]);
          int score = grid[row][col] + f(row + 1, grid, ds);        
          maxScore = max(maxScore, score);
          ds.erase(grid[row][col]);
      }
  }

  if (skipRow) 
      maxScore = f(row + 1, grid, ds);

  return maxScore;
}
int maxScore(vector<vector<int>>& grid) {
    unordered_set<int> selectedValues;
    return f(0, grid, selectedValues);
}