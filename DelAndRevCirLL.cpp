#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* reverse(Node* head) {
  // cout << "How many time is this called? " << endl; 
  if(!head) return head;
  if(head->next == head)
      return head;
  
  Node* ptr = head, *nextPtr = head->next, *prevPtr = head;
  while(prevPtr->next != head)
      prevPtr = prevPtr->next;
  
  // cout << "LstNOdE: " << prevPtr->data << endl;
  
  while(nextPtr != head) {
      ptr->next = prevPtr;
      prevPtr = ptr;
      ptr = nextPtr;
      if(ptr == head && nextPtr == head)
          break;
      nextPtr = nextPtr->next;
  }
  ptr->next = prevPtr;
  return ptr;
}

// Function to delete a node from the circular linked list
Node* deleteNode(Node* head, int key) {
  if(head->next == head){
      if(key == head->data)
          return NULL;
      return head;
  }
      
  Node* prevPtr = head, *ptr = head->next;
  if(key == head->data){
      while(ptr->next != head)
          ptr = ptr->next;
      ptr->next = prevPtr->next;
      head = prevPtr->next; // * Update new HEAD
      prevPtr->next = NULL;
      delete prevPtr;
  } else {
      while(ptr != head){
          if(key == ptr->data){
              prevPtr->next = ptr->next;
              ptr->next = NULL;
              delete ptr;
              break;
          } 
          prevPtr = ptr;
          ptr = ptr->next;
      }
  }
  return head;
}