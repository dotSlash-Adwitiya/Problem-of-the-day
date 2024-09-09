#include<bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void fillSpiral(vector<vector<int> > & matrix, ListNode * &head) {
  
  ListNode* ptr = head;
  int r = matrix.size(), c = matrix[0].size();
  int startCol = 0, startRow = 0, endCol = c - 1, endRow = r - 1;
  int cnt = 0;
  while(cnt < r*c) {
      
      for(int i = startCol; i <= endCol && cnt < r*c; i++){
          if(ptr) {
              matrix[startCol][i] = ptr->val;
              ptr = ptr->next;
          } 
          else matrix[startCol][i] = -1;
          cnt++;
      }
      startRow++;
      for(int i = startRow; i<= endRow && cnt < r*c; i++){
          if(ptr){
              matrix[i][endCol] = ptr->val;
              ptr = ptr->next;
          } else matrix[i][endCol] = -1;
          cnt++;
      }
      endCol--;
      
      for(int i = endCol; i >= startCol && cnt < r*c; i--){
          if(ptr){
              matrix[endRow][i] = ptr->val;
              ptr = ptr->next;
          } else matrix[endRow][i] = -1;     
          cnt++;
      }
      endRow--;
      
      for(int i = endRow; i >= startRow && cnt < r*c; i--){
          if(ptr){
              matrix[i][startCol] = ptr->val;
              ptr = ptr->next;
          } else matrix[i][startCol] = -1;
          cnt++;
      }
      startCol++;
  }
}
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
  
  // * Create an m*n matrix
  vector<vector<int>> spiral(m, vector<int> (n, 0));
  // * Fill spiral matrix with linkedlist data
  fillSpiral(spiral, head);

  return spiral;
}