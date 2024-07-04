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
