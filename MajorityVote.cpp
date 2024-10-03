#include<bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int>& nums) {
  int candidate1 = 0, candidate2 = 1, cnt1 = 0, cnt2 = 0;
  int n = nums.size();
  for(auto &ele : nums){
      if(ele == candidate1)
          cnt1++;
      else if(ele == candidate2)
          cnt2++;
      else if(cnt1 == 0)
          candidate1 = ele, cnt1 = 1;
      else if(cnt2 == 0)
          candidate2 = ele, cnt2 = 1;
      else
          cnt1--, cnt2--;
  }
  cnt1 = cnt2 = 0;
  for(auto &ele: nums){
      if(ele == candidate1) cnt1++;
      else if(ele == candidate2) cnt2++;
  }
  vector<int> ans;
  if(cnt1 > n / 3) ans.push_back(candidate1); 
  if(cnt2 > n / 3) ans.push_back(candidate2); 

  return ans;
}