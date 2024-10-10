#include<bits/stdc++.h>
using namespace std;

// * Problem Link: https://leetcode.com/problems/maximum-width-ramp/submissions/1418421476/?envType=daily-question&envId=2024-10-10


// * O(N) Time & Space - Monotonic Stack
int maxWidthRamp(vector<int>& nums) {
  int n = nums.size();
  stack<int> s;

  // Step 1: Create a monotonic decreasing stack of indices
  for (int i = 0; i < n; ++i) {
      if (s.empty() || nums[s.top()] > nums[i]) {
          s.push(i);
      }
  }

  // Step 2: Iterate from right to left and check for the largest width
  int maxWidth = 0;
  for (int j = n - 1; j >= 0; --j) {
      while (!s.empty() && nums[s.top()] <= nums[j]) {
          maxWidth = max(maxWidth, j - s.top());
          s.pop();
      }
  }

  return maxWidth;
}
// * Sorting O(nlogn)
int maxWidthRamp(vector<int>& nums) {
  int n = nums.size();
  vector<pair<int, int>> indexedNums;

  // Step 1: Create a vector of pairs (value, index)
  for (int i = 0; i < n; ++i) {
      indexedNums.push_back({nums[i], i});
  }

  // Step 2: Sort by value (if values are the same, sort by index)
  sort(indexedNums.begin(), indexedNums.end());

  // Step 3: Track the minimum index so far and calculate the maximum ramp width
  int minIndex = n;
  int maxWidth = 0;

  for (auto& [value, index] : indexedNums) {
      maxWidth = max(maxWidth, index - minIndex);
      minIndex = min(minIndex, index);
  }

  return maxWidth;
}

// * O(N) Time O(1) Space - SLIDING WINDOW
int maxWidthRamp(vector<int>& nums) {
  int n = nums.size();
  vector<int> rMax(n);
  rMax[n - 1] = nums[n - 1];
  
  for (int idx = n - 2; idx >= 0; idx--) {
      rMax[idx] = max(rMax[idx + 1], nums[idx]);
  }
  
  int left = 0, right = 0;
  int maxWidth = 0;
  
  while (right < n) {
      while (left < right && nums[left] > rMax[right]) {
          left++;
      }
      maxWidth = max(maxWidth, right - left);
      right++;
  }
  
  return maxWidth;
}