#include<bits/stdc++.h>
using namespace std;

string compareFrac(string str) {
  int num1 = 0, i = 0;
  
  while(str[i] != '/'){
      num1 = num1 * 10 + str[i] - '0';
      i++;
  }
  i++; // * Move away from '/'
  
  int den1 = 0;
  while(str[i] != ','){
      den1 = den1 * 10 + str[i] - '0';
      i++;
  }
  
  
  double f1 = 0;
  if(den1 != 0) f1 = (double)num1/den1;
  
  // * Move away from the , and ' '
  i++;
  i++;
  
  // // * For Fraction - 2
  int num2 = 0, den2 = 0;
  while(str[i] != '/'){
      num2 = num2 * 10 + str[i] - '0';
      i++;
  }
  
  
  i++; // * Move away from the '/'
  
  while(str[i] != '\0'){
      den2 = den2 * 10 + str[i] - '0';
      i++;
  }
  
  double f2 = 0;
  if(den2 != 0) f2 = (double)num2/den2;

  
  
  string ans = "";
  if(f1 < f2){
      ans += to_string(num2);
      ans += "/";
      ans += to_string(den2);
  } else if(f1 > f2) {
      ans += to_string(num1);
      ans += "/";
      ans += to_string(den1);
  } else ans = "equal";
  
  return ans;
}