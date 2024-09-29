#include<bits/stdc++.h>
using namespace std;

int totalCount(int k, vector<int>& arr) {
  int res = 0;
  for ( auto i : arr ) res += i/k + (i%k != 0);
  return res;
}