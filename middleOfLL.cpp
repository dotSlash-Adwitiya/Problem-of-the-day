#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Node {
      int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node *next) : data(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
  ListNode * slow = head, * fast = head;

  while(fast) {
      if(fast->next == NULL)
          break;

      slow = slow->next;
      fast = fast->next;
      
      if(fast)
          fast = fast->next;
  }
  return slow;
}

// * PoTD Again: 12-Sept-2024
int getMiddle(Node *head) {
  if(!head) return 0;
      
  Node* slow = head, *fast = head;
  
  while(fast != NULL && fast->next != NULL){
      fast = fast->next->next;
      slow = slow->next;
  }
  return slow->data;
}