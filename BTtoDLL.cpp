#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x){
      data = x;
      left = right = NULL;
  }
};

void insertAtTail(vector<int> &v, Node* &head){
  Node* ptr = head, *tail = ptr;
  for(int &ele: v){
      if(head == NULL){
          ptr = new Node(ele);
          head = ptr;
          tail = ptr;
      }
      else {
          tail = new Node(ele);
          ptr->right = tail;
          tail->left = ptr;
          ptr = ptr->right;
      }
  }
}
void inorder(Node* &root, vector<int> &v){
  if(!root) return;
  inorder(root->left, v);
  v.push_back(root->data);
  inorder(root->right, v);
}
Node* bToDLL(Node* root) {
  vector<int> in;
  inorder(root, in);
  Node* head = NULL;
  insertAtTail(in, head);
  return head;
}