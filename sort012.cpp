#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
  int l = 0, m = 0, r = nums.size() - 1;

  while(m <= r){
      if(nums[m] == 0) {
          swap(nums[m], nums[l]);
          l++;
          m++;
      }else if(nums[m] == 1){
          m++;

      }else {
          swap(nums[r], nums[m]);
          r--;
          // * We don't move mid pointer because it can lead to error if there's a 0 on the right end
      }
  }
}