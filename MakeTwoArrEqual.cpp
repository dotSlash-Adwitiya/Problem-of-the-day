#include<bits/stdc++.h>
using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) {
  int hash[1001] = {0};
  for(auto &ele: target) hash[ele]++;
  
  for(auto &ele: arr) hash[ele]--;

  for(int i = 0; i < 1001; i++)
      if(hash[i] != 0)
          return false;
  return true;
}