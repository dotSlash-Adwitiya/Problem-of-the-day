#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
      data = x;
      next = NULL;
  }
};

int countNodesinLoop(struct Node *head) {
  Node * slow = head, *fast = head;
  
  while(fast and fast->next){
      fast = fast->next;
      if(fast->next)
          fast = fast->next;
      slow = slow->next;
      
      if(slow == fast){
          int cnt = 0;
          Node* ptr = slow->next;
          while(ptr != slow){
              ptr = ptr->next;
              cnt++;
          }
          return cnt + 1;
      }
  }
  return 0;
}