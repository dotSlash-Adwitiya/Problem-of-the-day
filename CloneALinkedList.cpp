#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node *copyList(Node *head) {
  unordered_set<Node*> st;
  
  Node* ptr = head, * tail = nullptr;
  Node* cloneList = nullptr;
  while(ptr != nullptr){
      if(cloneList == nullptr){
          tail = new Node(ptr->data);
          cloneList = tail;
      }
      
      if(ptr->next){
          if(st.count(ptr->next)){
              Node* currNext = *(st.find(ptr->next));
              // * Connect tail to its NEXT
              tail->next = currNext;
          } else {
              // * If the NEXT is the upcoming node (NOT YET Created)
              Node* nextNode = new Node(ptr->next->data);
              // * Connect tail to its NEXT
              tail->next = nextNode;
          }
      }
      
      if(ptr->random){
          // * If the RANDOM is the previous node
          if(st.count(ptr->random)){
              Node* currRandom = *(st.find(ptr->random));
              // * Connect tail to its RANDOM
              tail->random = currRandom;
              st.insert(currRandom);
              
          } else {
              // * If the RANDOM is the upcoming node (NOT YET Created)
              Node* currRandom = new Node(ptr->random->data);
              // * Connect tail to its RANDOM
              tail->random = currRandom;
              //* Insert RANDOM into set
              st.insert(currRandom);
          }
      }
      st.insert(ptr);
      // * Move both ptr's
      tail = tail->next;
      ptr = ptr->next;
  }
  return cloneList;
}