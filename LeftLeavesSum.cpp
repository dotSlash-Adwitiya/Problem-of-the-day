#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void count(TreeNode* root, int &cnt, bool flag){

  // * If its the leaf node, then we include the sum
  if(!root->left && !root->right){
      if(flag) cnt += root->val;
      return;
  }

  // * Just pass TRUE when traversing to the left part coz we want to include it in the sum 
  // * And FALSE when traversing to the right nodes
  if(root->left) count(root->left, cnt, true);
  if(root->right) count(root->right, cnt, false);        
}
int sumOfLeftLeaves(TreeNode* root) {
  int cnt = 0;
  if(!root->left && !root->right) return cnt;
  count(root, cnt, true);
  return cnt;
}