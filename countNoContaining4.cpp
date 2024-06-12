#include<bits/stdc++.h>
using namespace std;

int divide(int n){
  int cnt = 0;
  while(n){
      int mod = n % 10;
      if(mod == 4){
          cnt++;
          break; // * VERY IMP, because if n == 44, then it will be counted twice which is wrong according to the question.
      }
      n /= 10;
  }
  return cnt;
}

int countNumberswith4(int n) {
  int cnt = 0;
  
  for(int i = 0; i <= n; i++){
      cnt += divide(i);        
  }
  
  return cnt;
}