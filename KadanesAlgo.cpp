#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
  int currSum = 0, maxSum = INT_MIN;
  for(int &ele : arr){
      currSum += ele;
      maxSum = max(maxSum, currSum);
      if(currSum < 0) currSum = 0;
  }
  return maxSum;
}