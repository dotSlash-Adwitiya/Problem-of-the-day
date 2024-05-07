#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode * next;

  ListNode(int val) { this->val = val; }
};

ListNode* reverseList(ListNode * &head) {
    ListNode * p = head, * q = head->next, * r = NULL; 

    while(p) {
        p->next = r;
        r = p;
        p = q;
        if(q)
            q = q->next;
    }
    return r;
}

void multiply(ListNode* head, ListNode * &newCurr, ListNode *& newHead, long long &carry) {
    ListNode* curr = head;
    long long tempAns = curr->val * 2 + carry;
    long long digit = tempAns % 10;
    carry = tempAns / 10;

    ListNode *newNode = new ListNode(digit);

    // * Used for debugging
    // cout << "New Node's Data : " << newNode->val << endl;

    if(newHead == NULL) {
        newHead = newNode;
        newCurr = newHead;
    }
    else{
        newCurr->next = newNode;
        newCurr = newCurr->next;
    }

    // * If this is the LAST Node
    if(head->next == NULL) {
        while(carry) {
            ListNode * newNode = new ListNode(carry % 10);
            carry /= 10;
            newCurr->next = newNode;
            newCurr = newCurr->next;
        }
    }

    // * Used for debugging :-
    // if(newHead && newCurr) {
    //     cout << "New Head "<< newHead->val << endl;
    //     cout << "New Curr "<< newCurr->val << endl;
    // }

}

ListNode* doubleIt(ListNode* head) {
    if(!head)
        return head;

    // * If there are at least two nodes
    if(head->next)
        head = reverseList(head);

    ListNode *temp = head, * newHead = NULL, *newCurr = NULL;        
    long long carry = 0;

    // * Traverse till the end of list, and for each node call multiply fn():-
    while(temp) {
        multiply(temp, newHead, newCurr, carry);
        temp = temp->next;
    }

    newHead = reverseList(newCurr);

    return newHead;
}