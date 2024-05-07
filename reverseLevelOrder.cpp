#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

vector<int> reverseLevelOrder(Node *root)
{
    if(!root)
        return {};
    
    vector<int> ans;
    queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty()){
        Node* ele = q.front();
        ans.push_back(ele->data);
        q.pop();
        
        if(ele->right)
            q.push(ele->right);
        if(ele->left)
            q.push(ele->left);
    }
    
    // Final reverse
    reverse(ans.begin(), ans.end());
    
    // reverse(ans.begin(), ans.end());
    return ans;
}