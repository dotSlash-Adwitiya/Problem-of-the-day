#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
  int maxEle = *max_element(nums.begin(), nums.end());
  int maxLen = 0;
  for(int i = 0; i < nums.size(); i++){
      int len = 0;
      while(i < nums.size() and nums[i] == maxEle){
          len++;
          i++;
      }
      maxLen = max(maxLen, len);
  }
  return maxLen;
}