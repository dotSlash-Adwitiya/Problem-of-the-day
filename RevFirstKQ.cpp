#include <bits/stdc++.h> 
using namespace std;

void reverse(queue<int> &q,int k)
{
    stack<int> stk;
    int cnt = 0;

    while(cnt < k){
        int frontEle = q.front();
        stk.push(frontEle);
        q.pop();
        cnt++;
    }

    while(!stk.empty()){
        int topEle = stk.top();
        stk.pop();
        q.push(topEle);
    }

    int size = q.size() - k;
    while(size--){
        int frontEle = q.front();
        q.push(frontEle);
        q.pop();
    }
}