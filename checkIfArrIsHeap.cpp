#include<bits/stdc++.h>
using namespace std;

// * TC : O(N), SC : O(1)
bool isMaxHeap(int arr[], int n)
{
  for(int i = 0; i < n/2; i++) 
      if(2*i+1 < n && arr[i] < arr[i*2+1] || 2*i+1 < n && arr[i] < arr[i*2+2])
          return false;
  return true;
}