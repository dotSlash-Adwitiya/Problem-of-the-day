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