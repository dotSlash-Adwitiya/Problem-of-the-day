#include<bits/stdc++.h>
using namespace std;

long long max_Books(int arr[], int n, int k) {
  
  long long maxBookSequence = -1;
  
  for(int i = 0; i < n; i++) {
      long long currBookSequence = 0;
      
      while(i < n && arr[i] <= k) {
          currBookSequence += arr[i]; // * Add books in current Sequence
          i++;
      }

      // * Store the maximum Sequence     
      maxBookSequence = max(maxBookSequence, currBookSequence);
  }
  return maxBookSequence;
}