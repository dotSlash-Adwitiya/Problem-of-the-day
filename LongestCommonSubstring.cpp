#include<bits/stdc++.h>
using namespace std;

// * GIVES TLE: O(N²)
int longestCommonSubstr (string str1, string str2, int n, int m) {
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(str1[i] == str2[j]){
                int ptr1 = i, ptr2 = j;
                int currLen = 0;
                while(ptr1 < n && ptr2 < m && str1[ptr1] == str2[ptr2]){
                    currLen++;
                    ptr1++, ptr2++;
                } 
                maxLen = max(maxLen, currLen);
            }
        }
    }
    return maxLen;
}

// * Solved using LCS Logic :T.C: O(N*M)
int longestCommonSubstr(string s1, string s2) {
  int n = s1.size(), m = s2.size();

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  int ans = 0; 

  for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
          if(s1[i-1] == s2[j-1]){
              int val = 1 + dp[i-1][j-1]; 
              dp[i][j] = val; 
              ans = max(ans, val); 
          }
          else
              dp[i][j] = 0; 
      }
  }
  
  return ans; 
}