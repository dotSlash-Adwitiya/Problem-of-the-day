#include<bits/stdc++.h>
using namespace std;

// * T.C O(log(n))
long long reversedBits(long long x) {
  if(x == 0)
      return 0;
  
  string bin = "";
  
  // * Convert to binary Form : T.C : O(log(n))  
  while(x != 0) {
      int rem = x % 2;
      bin += to_string(rem);
      x /= 2; // * Division by 2
  } 
  
  // * Fill till length is 32
  while(bin.length() != 32)
      bin += '0';
  
  long long ans = 0;
  int expo = 0;
  
  // * Starting in reverse direction to avoid reversing the string, which would lead to O(n) T.C
  for(int i = 31; i >= 0; i--, expo++)
      ans += (bin[i] - '0') * pow(2,expo);
      
  return ans;
}