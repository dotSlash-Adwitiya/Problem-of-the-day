#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

void helper(Node* root, int n, int &ans) {
    if(!root)
        return;
    if(root->key <= n && root->key > ans)
        ans = root->key;
    
    helper(root->left, n, ans);
    helper(root->right, n, ans);
}

int findMaxForN(Node* root, int n) {
    int ans = -1;
    helper(root, n, ans);
    return ans;
}