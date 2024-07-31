#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> arr) {
  string str1 = arr[0], res = arr[0];
  int n = arr.size();
  for(int i = 1; i < n; i++){
      string str2 = arr[i];
      int j = 0, k = 0;
      string temp = "";
      while(j < str2.size() and k < str1.size() and str1[k] == str2[j]){
          temp += str1[k];
          k++, j++;
      }
      res = min(temp, res);
  }
  if(res == "")
      return "-1";
  return res;
}