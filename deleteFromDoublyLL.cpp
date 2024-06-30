#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};

Node* deleteHead(Node* &head) {
  Node *ptr = head;
  head = head->next;
  head->prev = NULL;
  ptr->next = NULL;
  delete ptr;
  return head;
}

Node* deleteNode(Node* head, int x) {
  if(x == 1){
      deleteHead(head);
      return head;
  }
  
  // Traverse till xth node
  int cnt = 1;
  Node * currPtr = head, *prevPtr = NULL;
  while(currPtr && cnt != x){
      cnt++;
      prevPtr = currPtr;
      currPtr = currPtr->next;
  }
  if(currPtr) {
      Node* next2 = currPtr->next;
      if(next2){ // * If currPtr's Next IS NOT NULL
          next2->prev = prevPtr;
          prevPtr->next = next2;
          currPtr->next = NULL;
      }
      else prevPtr->next = NULL;
      
      // * Change currPtr's Link so it can be deleted (might not be neccessary)
      currPtr->prev = NULL;
      delete currPtr;
  } 
  return head;
}