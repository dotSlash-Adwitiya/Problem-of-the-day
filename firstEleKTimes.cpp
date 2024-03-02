#include<bits/stdc++.h>
using namespace std;

int firstElementKTime(int n, int k, int a[])
{
  unordered_map<int, int> ump;
  
  for(int i = 0; i < n; i++) {
      ump[a[i]]++;
      if(ump[a[i]] == k)
          return a[i];
  }

  return -1;
}