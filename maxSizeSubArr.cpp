#include<bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int k, vector<int> &arr , int n){
  long sum = 0, maxSum = 0;
  int i = 0, j = 0;
  
  while(j < n) {
      sum += arr[j];
      
      if(j-i+1 < k){
          j++;
      }
      else if(j-i+1 == k){
          maxSum = max(sum, maxSum);
          j++;
          sum -= arr[i];
          i++;
      }
      else {
          sum -= arr[i];
          i++;
      }
      
  }
  return maxSum;
}