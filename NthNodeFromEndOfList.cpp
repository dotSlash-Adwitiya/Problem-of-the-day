#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// * Brute Force, O(N) - Double PASS :-
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode *temp = head;

    while(temp){
        temp = temp->next;
        size++;
    }

    int k = size - n;

    ListNode* slow = head, *prev = NULL;
    
    int cnt = 0;
    while(slow && cnt < k){
        prev = slow;
        slow = slow->next;
        cnt++;
    }

    if(prev){
        prev->next = slow->next;
        delete slow;
    }else {
        prev = slow;
        slow = slow->next;
        head = slow;
        delete prev;
    }

    return head;
}


// * Optimised Approach O(N) time, - SINGLE PASS
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode * slowPtr = head, * fastPtr = head, *prev = NULL;

    int cnt = 1;
    
    // * Maintain K-Distance b/w two ptrs
    while(fastPtr && cnt < n){
        fastPtr = fastPtr->next;
        cnt++;
    } 

    // * Move till last node
    while(fastPtr && fastPtr->next){
        fastPtr = fastPtr->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    // * We're not on Head Node
    if(prev) {
        prev->next = slowPtr->next;
        delete slowPtr;
    } else { // * If we're on HEAD then ChangeLinks !
        prev = slowPtr;
        slowPtr = slowPtr->next;
        head = slowPtr;
        delete prev;
    }

    return head;
}