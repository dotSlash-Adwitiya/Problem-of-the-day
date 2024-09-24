#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string s, string p) {
  // * Step 1: Edge case check - if p is longer than s, return "-1"
  if (p.length() > s.length()) return "-1";
  
  int n = s.length(), m = p.length();    // n: length of s, m: length of p
  int start = -1, end = -1;              // To store the start and end of the smallest window
  int len = INT_MAX;                     // Store the length of the smallest window
  int uniqueCharsInP = 0, matchCount = 0;// uniqueCharsInP: distinct chars in p, matchCount: chars matched in the window
  int left = 0;                          // Left pointer of the window
  
  // * Step 2: Frequency maps for characters in s and p (only lowercase letters)
  vector<int> freqS(26, 0), freqP(26, 0);
  
  // * Step 3: Fill the frequency map for string p
  for (int i = 0; i < m; i++) {
      freqP[p[i] - 'a']++;
      if (freqP[p[i] - 'a'] == 1) uniqueCharsInP++;  // Count distinct characters in p
  }
  
  // * Step 4: Sliding window approach to find the smallest window
  for (int right = 0; right < n; right++) {
      // Expand the window by adding the current character s[right] to freqS
      freqS[s[right] - 'a']++;
      
      // * If the current character count in window matches the frequency in p, increment matchCount
      if (freqS[s[right] - 'a'] == freqP[s[right] - 'a']) matchCount++;
      
      // * When the window has all characters of p (matchCount == uniqueCharsInP)
      if (matchCount == uniqueCharsInP) {
          // * Try to minimize the window by moving the left pointer
          while (freqS[s[left] - 'a'] > freqP[s[left] - 'a']) {
              freqS[s[left] - 'a']--;    // Decrease the count of the character and move the left pointer
              left++;
          }
          
          // * Step 5: Update the result if the current window is smaller
          if (len > right - left + 1) {
              start = left;
              end = right;
              len = right - left + 1;
          }
      }
  }
  
  if (start == -1) return "-1";
  
  return s.substr(start, len);
}