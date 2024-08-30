#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<vector<int> > &board){
  // * Upper Diagonal
  for(int i = row, j = col; i >= 0 and j >= 0; j--,i--)
      if(board[i][j] == -1) // * Queen exists
          return false;
  // * Same row
  for(int j = col; j >= 0; j--)
      if(board[row][j] == -1)
          return false;
          
  // * Lower Diagonal
  for(int i = row, j = col; i < board.size() and j >= 0; j--,i++)
      if(board[i][j] == -1) // * Queen exists
          return false;
  
  return true;
}

void place(int col, int n, vector<vector<int>> &board, vector<vector<int>> &queens, vector<int> &temp){
  if(col == n){
      queens.push_back(temp);
      return;
  }
  
  // * Row is OBVIOUSLY ALWAYS GOING TO START WITH 0
  // * Hence, we don't take it in recursion
  for(int row = 0; row < n; row++){
      if(isValid(row, col, board)){
          temp.push_back(row + 1);
          board[row][col] = -1;
          place(col + 1, n, board, queens, temp);
          board[row][col] = 0;
          temp.pop_back();
      }
  }
}

vector<vector<int>> nQueen(int n) { 
  vector<vector<int>> board(n, vector<int> (n, 0)), queens;
  vector<int> temp;
  place(0, n, board, queens, temp);
  
  return queens;
}