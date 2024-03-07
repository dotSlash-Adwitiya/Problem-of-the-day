#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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