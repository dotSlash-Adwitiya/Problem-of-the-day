#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node* left;
  int data;
  Node* right;
};

void preorderTraversal(Node* root, vector<int> &ans, int level){
  if(root==NULL){
      return;
  }
  
  if(ans.size() == level){
      ans.push_back(root->data);
  }
  
  preorderTraversal(root->left , ans, level+1);
  preorderTraversal(root->right, ans, level+1);
}

vector<int> leftView(Node *root)
{
  vector<int> ans;
  preorderTraversal(root, ans, 0);
  return ans;
}