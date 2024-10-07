#include<bits/stdc++.h>
using namespace std;

int pairsum(vector<int> &arr) {
  int first = -1, sec = -1;
  int n = arr.size();
  
  for(int i = 0; i < n; i++){
      if(arr[i] > first){
          sec = first;
          first = arr[i];
      }    
      else if(arr[i] > sec)
          sec = arr[i];
  }
  return sec + first;
}