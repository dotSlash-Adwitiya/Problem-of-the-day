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

// * GfG PoTD - 09-Sept-2024 (Efficient and minimal code)
void sort012(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n-1, mid = 0;
    
    while(mid <= right){
        if(arr[mid] == 0) swap(arr[left++], arr[mid++]);
        else if(arr[mid] == 1) mid++;
        else swap(arr[mid], arr[right--]);
    }
}