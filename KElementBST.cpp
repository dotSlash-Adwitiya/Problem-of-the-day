#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
  public:
    T data;
    TreeNode<T> *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(T x) : data(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode<int> *root, vector<int> &in){
  if(!root) return;
  inorder(root->left, in);
  in.push_back(root->data);
  inorder(root->right, in);
}

int kthSmallest(TreeNode<int> *root, int k) {
  vector<int> inorderList;
  inorder(root, inorderList);
  for(int i = 0; i < inorderList.size(); i++){
      if(i + 1 == k)
          return inorderList[i];
  }
  return -1;
}