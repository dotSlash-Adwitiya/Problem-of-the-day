#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr) {
  int i = 0, jumps = 0;
  int n = arr.size();
  
  // * If the first element is 0, we cannot move forward
  if(arr[0] == 0 && n > 1) return -1;
  
  while(i < n) { 
      int x = arr[i];  // * Maximum steps we can jump from current index
      int maxEle = -1, maxIdx = i;
      
      // * If we can directly jump to or beyond the last element
      if(i + x >= n - 1) return jumps + 1;
      
      jumps++;  // * Increment the jump count
      
      // * Find the index with MAX ele to jump to within the current jump range
      for(int j = i + 1; j <= i + x; j++) {
          if(arr[j] > maxEle){
              maxEle = arr[j];
              maxIdx = j;
          }
      }
      
      // * If no progress can be made, return -1
      if(maxIdx == i) return -1;
      
      i = maxIdx;  // * Jump to the best index
  }
  
  return jumps;
}