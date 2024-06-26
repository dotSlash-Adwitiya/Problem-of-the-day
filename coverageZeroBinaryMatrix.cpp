#include<bits/stdc++.h>
using namespace std;

bool checkValid(int i, int j, vector<vector<int>>& matrix){
  if(i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size())
      return true;
  return false;
}

int findCoverage(vector<vector<int>>& matrix) {
  int coverage = 0;
  int n = matrix.size();
  int m = matrix[0].size();
  for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
          if(checkValid(i-1,j, matrix)) {
              if(matrix[i][j] == 0 && matrix[i-1][j] == 1)
                  coverage++;
          } // * up direction
          if(checkValid(i,j+1, matrix)){
              if(matrix[i][j] == 0 && matrix[i][j+1] == 1)
                  coverage++;
          } // * right direction
          if(checkValid(i+1,j, matrix))  {
              if(matrix[i][j] == 0 && matrix[i+1][j] == 1)
                  coverage++;
          }// * down direction
          if(checkValid(i,j-1, matrix)) {
              if(matrix[i][j] == 0 && matrix[i][j-1] == 1)
                  coverage++;
          }// * left direction
              
      }
  }
  return coverage;
}