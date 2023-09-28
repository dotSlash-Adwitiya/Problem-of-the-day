#include<bits/stdc++.h>
using namespace std;

void convertToWave(int n, vector<int>& arr){
  int sz = n;;
  // * If size is odd, then traverse till the element where next element exists.
  if(n&1)
      sz = n-1;
  for(int i = 0; i < sz; i += 2)
      swap(arr[i+1], arr[i]);
}

int main()
{

  return 0;
}