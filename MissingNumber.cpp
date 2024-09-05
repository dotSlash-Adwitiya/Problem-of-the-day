#include<bits/stdc++.h>
using namespace std;

// * One line code
int missingNumber(int n, vector<int>& arr) {
  return (n*(n+1) / 2) - accumulate(arr.begin(), arr.end(), 0);
}