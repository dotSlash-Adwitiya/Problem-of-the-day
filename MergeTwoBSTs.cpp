#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

void inorder(Node* root, vector<int> &v){
  if(!root) return;
  inorder(root->left, v);
  v.push_back(root->data);
  inorder(root->right, v);
}

vector<int> merge(vector<int> &v1, vector<int> &v2){
  vector<int> ans;
  int i = 0, j = 0, n = v1.size(), m = v2.size();
  while(i < n && j < m){
      if(v1[i] <= v2[j]){
          ans.push_back(v1[i]);
          i++;
      }
      else {
          ans.push_back(v2[j]);
          j++;
      }
  }
  
  while(i < n)
          ans.push_back(v1[i++]);
  while(j < m)
          ans.push_back(v2[j++]);
  return ans;    
}

vector<int> merge(Node *root1, Node *root2) {
  vector<int> v1, v2;
  inorder(root1, v1);
  inorder(root2, v2);
  return merge(v1, v2);
}
