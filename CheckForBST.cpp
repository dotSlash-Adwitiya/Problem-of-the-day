#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

void helper(Node* root, vector<int> &ans, bool &flag){
  if(!root) return;
  helper(root->left, ans, flag);
  if(ans.size() != 0 && ans.back() == root->data)
      flag = false;
  ans.push_back(root->data);
  helper(root->right, ans, flag);
}

bool isBST(Node* root) {
  
  vector<int> ans;
  bool flag = true;
  helper(root, ans, flag);
  if(flag == false)
  return flag;
  
  for(int i = 0; i < ans.size()-1; i++){
      if(ans[i] >= ans[i+1])
      return false;
  }
  
  return true;
}