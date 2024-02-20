#include<bits/stdc++.h>
using namespace std;

// * TC : O(N) + O(N*S(length))
int helper(int i, unordered_set<string> &st, string &s) {
  if(i == s.size()) // * This is the edge case, where the last char in string ends at a word, that is found in dictionary !
      return 1;
      
  // * Declare a temp String    
  string temp;
  
  // *Iterate through every possibility in the string
  for(int j = i; j < s.size(); j++) {
      // * Add current Char to the tempString
      temp += s[j];
      
      // * Check if the word already exists in the dictionary
      if(st.find(temp) != st.end()){
          
          // * Make a call for remaining chars as, their is a possibility that :-
          // [geeks, geeksfor, geeksforgeek, geeksforgeeks], s = geeksforgeeks
          if(helper(j+1, st, s)) 
              return 1;
      }
  }
  
  // * If not found, then return 0
  return 0;
}

// * Here's the function for debugging !
int helperDebug(int i, unordered_set<string> &st, string &s) {
  if(i == s.size()) // * This is the edge case, where the last char in string ends at a word, that is found in dictionary !
      return 1;
      
  // * Declare a temp String    
  string temp;
  
  // *Iterate through every possibility in the string
  for(int j = i; j < s.size(); j++) {
      // * Add current Char to the tempString
      temp += s[j];
      cout << temp << endl;
      // * Check if the word already exists in the dictionary
      if(st.find(temp) != st.end()){
          
          // * Make a call for remaining chars as, their is a possibility that :-
          // [geeks, geeksfor, geeksforgeek, geeksforgeeks], s = geeksforgeeks
          if(helper(j+1, st, s)) {
              cout << "Found" << temp << endl;
              return 1;
          }
      }
  }
  
  // * If not found, then return 0
  return 0;
}

int wordBreak(int n, string s, vector<string> &dictionary) {
  unordered_set<string> st;
  
  // * Insert all elements in set, so that we can access them in O(log n) time
  for(auto it : dictionary) 
    st.insert(it);
  
  return helper(0, st, s);
}

// * Using DP TC : O(N)
int helperDP(int i, unordered_set<string> &st, string &s, vector<int> &dp) {
  if(i == s.size()) 
      return 1;
      
  // * Declare a temp String    
  string temp;
      
  if(dp[i] != -1) 
      return dp[i];
  
  
  // *Iterate through every possibility in the string
  for(int j = i; j < s.size(); j++) {
      // * Add current Char to the tempString
      temp += s[j];
      // * Check if the word already exists in the dictionary
      if(st.find(temp) != st.end()){
          
          // * Make a call for remaining chars as, their is a possibility that :-
          // [geeks, geeksfor, geeksforgeek, geeksforgeeks], s = geeksforgeeks
          if(helperDP(j+1, st, s, dp))
              return dp[i] = 1;
      }
  }
  
  // * If not found, then return 0
  return dp[i] = 0;
}

int wordBreakDP(int n, string s, vector<string> &dictionary) {
  unordered_set<string> st;
  vector<int> dp(s.size() + 1, -1);
  
  for(auto it : dictionary) st.insert(it);
  
  return helperDP(0, st, s, dp);
}

int main()
{
  vector<string> v = {"i", "like", "sam", "sung"};
  cout << wordBreak(v.size(), "ilikesamsung",v) << endl;

  return 0;
}