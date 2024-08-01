#include<bits/stdc++.h>
using namespace std;

int countSeniors(vector<string>& details) {
  int seniorCount = 0;
  for (const string& info : details) {
      char tens = info[11];
      char ones = info[12];
      if (tens > '6' || (tens == '6' && ones > '0')) seniorCount++;
  }
  return seniorCount;
}

// * Shorter Code :
int countSeniors(vector<string>& details) {
  int seniorCnt = 0;
  for(int i = 0; i < details.size(); i++) {
      char age1 = details[i][11];
      char age2 = details[i][12];
      if(age1 > '6' or (age1 == '6' and age2 > '0')) seniorCnt++;
  }
  return seniorCnt;
}