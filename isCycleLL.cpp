#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


bool hasCycle(ListNode *head) {
  ListNode *slow = head, *fast = head;

  while(fast && fast->next != NULL){
      slow = slow->next;
      fast = fast->next;
      if(fast)
          fast = fast->next;
      if(slow == fast)
          return true;
  }
  return false;
}