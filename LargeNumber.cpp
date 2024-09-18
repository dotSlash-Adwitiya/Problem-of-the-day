#include<bits/stdc++.h>
using namespace std;

// * Problem Link: https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18

// * Check which addition of which integer to the string is GREATER
static bool compare(int a,int b) {
  return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
string largestNumber(vector<int>& nums) {
  sort(nums.begin(), nums.end(), compare);

  string num = "";
  for(int i = 0; i < nums.size(); i++)
      num += to_string(nums[i]);
  
  if(num[0] == '0') 
      return "0";
  return num; 
}