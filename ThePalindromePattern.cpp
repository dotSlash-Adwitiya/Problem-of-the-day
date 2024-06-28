#include<bits/stdc++.h>
using namespace std;

string pattern(vector<vector<int>> &arr) {
  int n = arr.size();
  int endRow = n-1, idx = 0;
  string ans = "";
  for(int startRow = 0; startRow <= endRow; startRow++) {
      bool isPalindrome = true;
      int startCol = 0, endCol = n-1;
      while(startCol <= endCol) {
          if(arr[startRow][startCol] != arr[startRow][endCol]){
              isPalindrome = false;
              // cout << startRow <<startCol << " " <<  startRow << endCol << endl;
              break;
          }
          startCol++;
          endCol--;
          // cout << startRow <<startCol << " " <<  startRow << endCol << endl;
      }
      if(isPalindrome){
          idx = startRow;
          ans += to_string(idx);
          ans += " ";
          ans += "R";
          // cout << "Tgsigs"<< endl;
          return ans;
      }
  }
  
  //  * Traversing on Columns
  int startCol = 0, endCol = n - 1;
  for(int startCol = 0; startCol <= endCol; startCol++) {
      int startRow = 0, endRow = n-1;
      bool isPalindrome = true;
      while(startRow <= endRow) {
          if(arr[startRow][startCol] != arr[endRow][startCol]){
              isPalindrome = false;
              // cout << startRow <<startCol << " " <<  startRow << endCol << endl;
              break;
          }
          startRow++;
          endRow--;
          // cout << startRow <<startCol << " " <<  startRow << endCol << endl;
      }
  
      if(isPalindrome){
          idx = startCol;
          ans += to_string(idx);
          ans += " ";
          ans += "C";
          // cout << "Tgsigs"<< endl;
          return ans;
      }
  }
  return "-1";
}