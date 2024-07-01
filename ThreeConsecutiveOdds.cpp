#include<bits/stdc++.h>
using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
  int n = arr.size();
  for(int i = 0; i < n-2; i++) {
      int num1 = arr[i], num2 = arr[i+1], num3 = arr[i+2];
      if(num1 & 1 && num2 & 1 && num3 & 1)
          return true;
  }
  return false;
}