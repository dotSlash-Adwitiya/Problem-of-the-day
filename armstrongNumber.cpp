#include<bits/stdc++.h>
using namespace std;

int check(int n){
  return n*n*n;
}
string armstrongNumber(int n){
  int num = n;
  
  int d3 = n % 10;
  n /= 10;
  int d2 = n % 10;
  n /= 10;
  int d1 = n % 10;
  n /= 10;
  
  if(check(d1) + check(d2) + check(d3) == num)
      return "Yes";
  return "No";
}