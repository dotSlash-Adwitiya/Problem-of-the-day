#include<bits/stdc++.h>
using namespace std;

int maxPathSum(vector<int>& arr1, vector<int>& arr2) {
  int i = 0, j = 0, sum1 = 0, sum2 = 0, total = 0;

  while (i < arr1.size() && j < arr2.size()) {
      if (arr1[i] < arr2[j]) sum1 += arr1[i++];
      else if (arr2[j] < arr1[i]) sum2 += arr2[j++];
      else {
          total += max(sum1, sum2) + arr1[i];
          sum1 = 0; sum2 = 0; i++; j++;
      }
  }
  while (i < arr1.size()) sum1 += arr1[i++];
  
  while (j < arr2.size()) sum2 += arr2[j++];

  return total + max(sum1, sum2);
}