#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* npx;

  Node(int x){
      data = x;
      npx = NULL;
  }
};

struct Node* XOR (struct Node *a, struct Node *b) {
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

struct Node *insert(struct Node *head, int data) {
  if(!head) return new Node(data);
  
  Node* root = new Node(data);
  root->npx = XOR(root,head);
  
  head = root; 
  return head;
}

vector<int> getList(struct Node *head) {
  vector<int>ans;
  Node* root = head;
  
  while(root->npx != NULL){
      ans.push_back(root->data);
      root = XOR(root,root->npx);
  }
  
  ans.push_back(root->data);
  return ans;
}
