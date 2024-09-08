#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int countNodes(ListNode* &head){
  ListNode* temp = head;
  int cnt = 0;
  while(temp){
      temp = temp->next;
      cnt++;
  }
  return cnt;
}

// * BETTER THAN ONLY 13% solutions (BY CREATING NEW NODES)
vector<ListNode*> splitListToParts(ListNode* head, int k) {
  int n = countNodes(head);
  int parts = k;
  int mod = n % k;
  vector<ListNode*> ans;

  ListNode* ptr = head;
  while(ptr and mod--){ // * STARTING N%K NODES
      int num = (n / k) + 1;
      ListNode *temp = NULL, *head2 = NULL;
      while(ptr and num--){ // * ADD N/K + 1 Nodes
          ListNode* newNode = new ListNode(ptr->val);
          if(temp == NULL){
              temp = newNode;
              head2 = temp;
          }
          else{
              temp->next = newNode;
              temp = temp->next;
          }
          ptr = ptr->next;
      }
      parts--;
      ans.push_back(head2);
  }

  while(ptr and parts){
      int num = (n / k);
      ListNode *temp = NULL, *head2 = NULL;
      while(ptr and num--){ // * ADD N/K + 1 Nodes
          ListNode* newNode = new ListNode(ptr->val);
          if(temp == NULL){
              temp = newNode;
              head2 = temp;
          }
          else{
              temp->next = newNode;
              temp = temp->next;
          }
          ptr = ptr->next;
      }
      parts--;
      ans.push_back(head2);
  }
  while(parts--) ans.push_back(NULL);
  return ans;
}

// * BETTER THAN 25% solutions (in top) (without creating NEW NODES)
vector<ListNode*> splitListToParts(ListNode* head, int k) {
  int n = countNodes(head);
  int parts = k;
  int mod = n % k;
  vector<ListNode*> ans;

  ListNode* ptr = head;
  while(ptr and mod--){ // * STARTING N%K NODES
      int num = (n / k) + 1;
      ListNode *prev = NULL, *head2 = ptr;
      while(ptr and num--){ // * ADD N/K + 1 Nodes
          prev = ptr;
          ptr = ptr->next;
      }
      parts--;
      prev->next = NULL; // * CUT THE current LINKED LIST
      ans.push_back(head2); // * And push it
  }

  while(ptr and parts){ // * 
      int num = (n / k);
      ListNode *prev = NULL, *head2 = ptr;
      while(ptr and num--){ // * ADD N/K + 1 Nodes
          if(head2 == NULL)
              head2 = ptr;
          prev = ptr;
          ptr = ptr->next;
      }
      prev->next = NULL; // * CUT THE current LINKED LIST
      ans.push_back(head2); // * And push it
      parts--;
  }
  while(parts--) ans.push_back(NULL);
  return ans;
}