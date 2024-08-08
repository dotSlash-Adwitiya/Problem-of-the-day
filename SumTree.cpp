#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

int helper(Node* root){
  if(!root) return 0;
  int leftSum = helper(root->left);
  int rightSum = helper(root->right);
  if(!root->left && !root->right)
      return root->data;
  if(leftSum + rightSum == root->data)
      return leftSum + rightSum + root->data;
  return 0;
}

bool isSumTree(Node* root) {
  if(helper(root) - root->data == root->data)
      return true;
  return false;
}