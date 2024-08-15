#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

// * Went to the last node by applying recursion, and while returning, added a carry.
// * T.C: O(N), S.C:O(N)
// * We can also do this by reversing all nodes in 1st step and LAST STEP.
// * Which will take O(n) time and O(1) space.  
void add(Node* &node, int &carry){
  if(node->next == nullptr){
      carry = node->data + 1;
      if(carry != 0){
          int digit = carry % 10;
          carry /= 10;
          node->data = digit;
          return;
      }else {
          node->data = carry;
          return;
      }
  }
  add(node->next, carry);
  if(carry != 0){
          carry += node->data;
          int digit = carry % 10;
          carry /= 10;
          node->data = digit;
  }
}

Node* addOne(Node* head) {
  int carry = 0;
  add(head, carry);
  if(carry != 0){
      Node* newNode = new Node(carry);
      newNode->next = head;
      head = newNode;
  }
  return head;
}