#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& nums) {
  int n = nums.size();
  long long int left[n], right[n], prod = 1;
  
  for(int i = 0; i < n; i++){
      prod *= nums[i];
      left[i] = prod;
  }
  
  // * RESET the prod variable
  prod = 1;
  for(int i = n-1; i >= 0; i--){
      prod *= nums[i];
      right[i] = prod;
  }
  
  vector<long long int> ans(n,1);
  for(int i = 0; i < n; i++) {
      
      if(i != 0 and i != n-1) ans[i] = left[i-1] * right[i+1];
          
      else if(i == 0 and n >= 2) ans[i] = right[i+1];
          
      else if(i == n-1 and n >= 2)  ans[i] = left[i-1];
  }
  