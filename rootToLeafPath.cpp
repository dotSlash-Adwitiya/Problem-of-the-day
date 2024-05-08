#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node * left;
  int data;
  Node * right;
};

void helper(vector<vector<int>> &ans, vector<int> &v, Node *root) {
  if(!root)
      return;
  // * On the LEAF node, store the path till now, and remove the leaf node and RETURN.     
  if(!root->left && !root->right) {
      v.push_back(root->data);
      ans.push_back(v);
      v.pop_back();
      return;
  }
  v.push_back(root->data);
  
  helper(ans, v, root->left);
  helper(ans, v, root->right);

  // * While returning from the RIGHT CALL, remove ALL Elements
  v.pop_back();
}

vector<vector<int>> Paths(Node* root) {
  vector<vector<int>> ans;
  vector<int> v;
  
  if(!root)
      return ans;
  helper(ans, v, root);
  
  return ans;
}