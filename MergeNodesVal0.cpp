#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// * Approach - 1: By creating a NEW LIST
ListNode* mergeNodes(ListNode* head) {
  ListNode *ptr = head;
  ListNode* newHead = NULL, *temp = newHead;
  while(ptr){
      int sum = 0;
      while(ptr && ptr->val != 0){
          sum += ptr->val;
          ptr = ptr->next;
      }
      if(sum){

          if(newHead == NULL){
              newHead = new ListNode(sum);
              temp = newHead;
          }
          else{
              temp->next = new ListNode(sum);
              temp = temp->next;
          }
      }
      ptr = ptr->next;
  }
  return newHead;
}

// * Approach-2: Merginng the nodes, w/o creating a new node. 
ListNode* mergeNodes(ListNode* head) {
  ListNode *currPtr = head, *prevPtr = NULL;
  
  // * Edge case (not neccessary)
  // * As the question specifiecs, there's no such TC with consecutive 0s
  if(!head || head->next == 0)
      return head;

  // * Initial configuration: Find the 1st non-zero node
  currPtr = head->next;
  delete head;
  head = currPtr;
  // * Initial Config end

  while(currPtr) {
      int sum = 0;
      // * Add all the non-zero nodes, and delete during traversal
      while(currPtr && currPtr->val != 0){
          sum += currPtr->val;
          ListNode* temp = currPtr;
          currPtr = currPtr->next;
          delete temp;
      }
      // * Update current node's value with sum
      currPtr->val = sum;

      // * If this is a 2nd 0
      if(prevPtr == NULL){
          prevPtr = currPtr;
          head = prevPtr;
      } else {
          prevPtr->next = currPtr;
          prevPtr = currPtr;
      }
      currPtr = currPtr->next;
      prevPtr->next = NULL;
  }
  return head;
}