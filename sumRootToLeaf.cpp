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


// & T.C : O(N), SC: O(N) (As recursion utilise the internal stack)
void calculate(TreeNode* root, int &sum, int &currSum) {
  if(!root->left && !root->right){
      sum += currSum * 10 + root->val;
      return;
  }
  
  currSum = currSum * 10 + root->val;
  if(root->left)
      calculate(root->left, sum, currSum);
  // currSum /= 10  // * YOU MADE AN ERROR HERE!
  // * You don't have to divide by 10, coz the currSum's value won't be carried to the previous call!

  if(root->right)
      calculate(root->right, sum, currSum);
}

int sumNumbers(TreeNode* root) {
  int sum = 0, currSum = 0;
  calculate(root, sum, currSum);
  return sum;
}