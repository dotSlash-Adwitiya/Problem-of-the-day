#include<bits/stdc++.h>
using namespace std;

/*
  * INTUITION: Since we have ATMOST 3 Moves, 
  * The min diff can only be obtained from TOP-3 Largest and Smallest Element's Diff. 
*/

int minDifference(vector<int>& nums) {
  if(nums.size() <= 3)
      return 0;
  int ans = INT_MAX;
  int right = nums.size() - 1;
  sort(nums.begin(), nums.end());
  
  for(int left = 3; left >= 0; left--, right--)
      ans = min(ans, nums[right] - nums[left]);
  
  return ans;
}