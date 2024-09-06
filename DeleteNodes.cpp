#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
  unordered_set<int> st;

  ListNode* ptr = head, * prev = NULL;

  for(const auto &ele: nums)
      st.insert(ele);

  while(ptr){
      if(st.count(ptr->val)){ // * If its in set, delete it.
          if(ptr == head) { // * HEAD CASE
              head = head->next;
              delete ptr;
              ptr = head;
          } else {
              prev->next = ptr->next;
              delete ptr;
              ptr = prev->next;
          }
      } else {
          prev = ptr;
          ptr = ptr->next;
      }
  }
  return head;
}