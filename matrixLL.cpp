#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* right, *down;

  Node(int x){
      data = x;
      right = NULL;
      down = NULL;
  }
};

Node* constructLinkedMatrix(vector<vector<int>>& mat) {
  if (mat.empty() || mat[0].empty()) return nullptr;

  int rows = mat.size();
  int cols = mat[0].size();

  Node* nodeMatrix[rows][cols];

  for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
          nodeMatrix[i][j] = new Node(mat[i][j]);
      }
  }

  for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
          if (j + 1 < cols) {
              nodeMatrix[i][j]->right = nodeMatrix[i][j + 1]; // Link Right
          }
          if (i + 1 < rows) {
              nodeMatrix[i][j]->down = nodeMatrix[i + 1][j];  // Link down
          }
      }
  }


  return nodeMatrix[0][0];
}