#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix) 
{
  int r = matrix.size(), c = matrix[0].size();
  int startCol = 0, startRow = 0, endCol = c - 1, endRow = r - 1;
  vector<int> spiral;
  int cnt = 0;
  while(cnt < r*c) {
      
      for(int i = startCol; i <= endCol && cnt < r*c; i++){
          int ele = matrix[startCol][i];
          spiral.push_back(ele);
  
          cnt++;
      }
      startRow++;
      for(int i = startRow; i<= endRow && cnt < r*c; i++){
          int ele = matrix[i][endCol];
          spiral.push_back(ele);    

          cnt++;
      }
      endCol--;
      
      for(int i = endCol; i >= startCol && cnt < r*c; i--){
          int ele = matrix[endRow][i];
          spiral.push_back(ele);    
          cnt++;
      }
      endRow--;
      
      for(int i = endRow; i >= startRow && cnt < r*c; i--){
          int ele = matrix[i][startCol];
          spiral.push_back(ele);    
          cnt++;
      }
      startCol++;
  }
  
  return spiral;
}