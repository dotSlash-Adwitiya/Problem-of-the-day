#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < arr.size(); i++) pq.push(arr[i]);
  int ans = 0;
  while(k--) {
      ans = pq.top();
      pq.pop();
  }
  return ans;
}