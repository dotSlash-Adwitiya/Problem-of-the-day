#include<bits/stdc++.h>
using namespace std;

int nthStair(int n){
  // * Base cases
  if (n == 0) return 0;
  if (n == 1) return 1;

  // * Recursive step
  if ((n & 1) == 0) return nthStair(n - 1) + 1;
  else return nthStair(n - 1);
}

// * Simple code after pattern observations
int nthStair(int n){
  return (n/2) + 1;
}