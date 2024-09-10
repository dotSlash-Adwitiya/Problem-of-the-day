#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int GCD(int x, int y) {
  while (y != 0) {
      int remainder = x % y;
      x = y;
      y = remainder;
  }
  return x;
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
  ListNode * ptr = head;

  while(ptr and ptr->next){
      int node1 = ptr->val;
      int node2 = ptr->next->val;
      int gcd = GCD(node1, node2);
      
      ListNode* newNode = new ListNode(gcd);
      ListNode* nextNode = ptr->next;
      ptr->next = newNode;
      newNode->next = nextNode;
      ptr = nextNode;
  }
  return head;
}