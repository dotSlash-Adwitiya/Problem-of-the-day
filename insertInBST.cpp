#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//* Iterative solution, gives TLE !
Node* insert(Node* node, int data) {
  Node* prev = NULL;
  
  while(node != NULL) {
      
      if(node->data == data) return;
      
      else if(node->data < data) {
          prev = node;
          node = node->right;
      }
          
      else {
          prev = node;
          node = node->left;
      }
  }
  Node* newNode = new Node(data);
  
  if(prev->data < data)
      prev->right = newNode;
  else 
      prev->left = newNode;

  return node;
}

//* Recursive (OPTIMISED Solution)
Node* insert(Node* node, int data) {

  //* If we've reached the end then create a newNode, and return it.
  if(!node) {
      Node* newNode = new Node(data);
      return newNode;
  }
  
  //* Right Recursive Call, the newNode will be attached in the Right of currentNode
  if(node->data < data)
      node->right = insert(node->right, data);
  
  //* Left Recursive Call, the newNode will be attached in the Left of currentNode
  else if(node->data > data)
      node->left = insert(node->left, data);
      
  return node;
}

int main()
{

  return 0;
}