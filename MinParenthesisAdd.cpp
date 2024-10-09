#include<bits/stdc++.h>
using namespace std;

// * Problem link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/?envType=daily-question&envId=2024-10-09


int minAddToMakeValid(string S) {
  int left = 0, right = 0;
  for (char c : S)
      if (c == '(')
          right++;
      else if (right > 0)
          right--;
      else
          left++;
  return left + right;
}