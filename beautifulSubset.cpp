#include<bits/stdc++.h>
using namespace std;

// * Function to check the provided condition
bool isBeautiful(vector<int> &subset, int currEle, int k) {
  for(int &ele : subset)
      if(abs(ele - currEle) == k)
          return false;
  return true;
}

void helper(vector<int> &arr, vector<int> &subset, int idx, int k, int &cnt) {
  if(idx == arr.size()){
      if(subset.size() > 0)
          cnt++;
      return;
  }

  // * Include it ONLY if it satisfies the given condition, which is :
  // * A subset is BEAUTIFUL if(no 2 elements in it has absolute difference == k)
  if(isBeautiful(subset, arr[idx], k)) {
      subset.push_back(arr[idx]);;
      helper(arr, subset, idx + 1, k, cnt);
      subset.pop_back();
  }
  helper(arr, subset, idx + 1, k, cnt);
}

int beautifulSubsets(vector<int>& nums, int k) {
  int cnt = 0;
  vector<int> subset;
  helper(nums, subset, 0, k, cnt);
  return cnt;
}