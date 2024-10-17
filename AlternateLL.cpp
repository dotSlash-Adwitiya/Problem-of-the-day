#include<bits/stdc++.h>
using namespace std;


struct Node {
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    next = nullptr;
  }
};

vector<Node*> alternatingSplitList(struct Node* head) {
  if(!head) return {};
  
  Node* ptr = head;
  vector<Node*> ans;
  
  Node* head1 = NULL, *tail = head1;
  while(ptr){
      if(!head1){
        head1 = new Node(ptr->data);
        tail = head1;
      } 
      else {
          Node* newNode = new Node(ptr->data);
          tail->next = newNode;
          tail = tail->next;
      }
      ptr = ptr->next;
      if(ptr) ptr = ptr->next;
  }
  
  ans.push_back(head1);
  if(head->next) ptr = head->next;
  else return ans;
  
  Node* head2 = NULL;
  tail = head2;
  while(ptr){
      if(!head2){
        head2 = new Node(ptr->data);
        tail = head2;
      } 
      else {
          Node* newNode = new Node(ptr->data);
          tail->next = newNode;
          tail = tail->next;
      }
      ptr = ptr->next;
      if(ptr) ptr = ptr->next;
  }
  ans.push_back(head2);
  return ans;
}