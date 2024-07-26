#include<bits/stdc++.h>
using namespace std;

bool kPangram(string str, int k) {
  int freq[26] = {0};
  int cnt = 0, totalChar = 0;
  for(int i = 0; i<str.size(); i++){
      if(freq[str[i] - 'a'] == 0)
          cnt++;
      if(str[i] != ' '){
          totalChar++;   
          freq[str[i] - 'a']++;
      }
  }
  // * There has to be a total of 26 distinct chars
  // * cnt is the no of distinct char already present in a string
  // * 26 - cnt means the no of distinct char missing in the string.
  // * if we can introduct missing characters in AT MOST K operations return true
  if(totalChar >= 26 && 26-cnt <= k)
      return true;
  return false;
}