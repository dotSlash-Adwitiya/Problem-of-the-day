#include<bits/stdc++.h>
using namespace std;

long long minCost(vector<long long>& arr) {
  // * Create min heap
  priority_queue<long long,vector<long long>,greater<long long>>pq;
  
  for(int i=0;i<arr.size();i++)
      pq.push(arr[i]);
  
  long long res = 0;
  while(pq.size() > 1){
      long long num1 = pq.top();
      pq.pop();
      
      res += num1 + pq.top();
      pq.push(num1 + pq.top());
      pq.pop();
  }
  return res;
}