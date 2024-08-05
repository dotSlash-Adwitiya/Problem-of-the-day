#include<bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string>& arr, int k) {
  unordered_map<string, int> counter;
  for (auto& ele : arr) ++counter[ele];
  for (auto& ele: arr) {
      if (counter[ele] == 1) {
          --k;
          if (k == 0) return ele;
      }
  }
  return "";
}