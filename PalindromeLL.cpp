#include<bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

bool isPalindrome(string str) {
  int i = 0, j = str.size() - 1;
  while(i < j) {
      if(str[i++] != str[j--])
          return false;
  }
  return true;
}

bool compute(Node* head) {
  Node* ptr = head;
  string pal = "";
  
  while(ptr != NULL) {
      pal += ptr->data;
      ptr = ptr->next;
  }
  return isPalindrome(pal);
}

// * PoTD: 25-Sept-2024
int sizeOfLL(Node* head) {
  int cnt = 0;
  Node* ptr = head;
  while(ptr != nullptr) {
      cnt++;
      ptr = ptr->next;
  }
  return cnt;
}

Node* reverseLinks(Node* &head) {
  Node* prevPtr = nullptr, *currPtr = head, *fastPtr = head->next;
  
  while(currPtr != nullptr) {
      currPtr->next = prevPtr;
      prevPtr = currPtr;
      currPtr = fastPtr;
      if(fastPtr == nullptr)
          break;
      fastPtr = fastPtr->next;
  }
  return prevPtr;
}

bool isPalindrome(Node *head) {   
  if(!head || !head->next)
      return 1;
  
  //* Find size of LL
  int n = sizeOfLL(head)/2, cnt = 0;
  // cout << "size of LL : " << n << endl;
  
  
  //* Traverse till size + 1
  Node* firstPtr = head, *prevPtr = nullptr;
  while(cnt != n) {
      cnt++;
      prevPtr = firstPtr;
      firstPtr = firstPtr->next;
  }
  prevPtr->next = nullptr;

  
  //* Reverse all nodes after half of the LL is over
  Node* lastPtr = reverseLinks(firstPtr);
  
  // cout << "Last Ptr data : " << lastPtr->data << endl;
  firstPtr = head;
  while(firstPtr != nullptr && lastPtr != nullptr) {
      if(firstPtr->data != lastPtr->data)
          return false;
      firstPtr = firstPtr->next;
      lastPtr = lastPtr->next;
  }
  return true;
}