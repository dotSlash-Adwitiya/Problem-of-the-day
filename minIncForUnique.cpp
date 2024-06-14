#include<bits/stdc++.h>
using namespace std;

// * Approach - 1 : TLE
int minIncrementForUnique(vector<int>& nums) {
    unordered_map<int, int> ump;
    
    int ans = 0;

    for(int &ele : nums){
        int cnt = 0;
        while(ump.find(ele) != ump.end()){
            ele++;
            cnt++;
        }
        ump[ele] = 1;
        ans += cnt;
    }
    return ans;
}

// * Approach - 2 : Optimised using SORTING
/*
 * res += largest - nums[i] + 1; // * NEW APPROACH LEARNT
 * In every step, we need to check whether the currEle matches with the largest ele
 * If it does, then we need to increment the largest elem
 * And increase one operation
 * But, just increasing one operation won't work if we have multiple same numbers, hence we use :
 * largest - nums[i] + 1 and !----- Update largest in every step --------!.
*/
int minIncrementForUnique(vector<int>& nums) {
  sort(nums.begin(),nums.end());
  int largest = INT_MIN;
  int res = 0;
  for(int i=0; i<nums.size(); i++){
      if(nums[i] > largest){
          largest = nums[i];
      }else{
          res += largest - nums[i] + 1; // * NEW APPROACH LEARNT
          largest++;
      }
  }
  return res;
}
