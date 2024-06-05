#include<bits/stdc++.h>
using namespace std;

/*
 * Find all the letters that are common in the given words array of type : vector<string>
 * Input: words = ["bella","label","roller"]
 * Output: ["e","l","l"] 
 * Hint 1 : Check something after processing each one of the string.
 * Hint 2: Store the MINIMAL frequencies of every character after processing each one of the string
*/

//*  Function to count frequency of each letter in each on of the string inside vector
vector<int> count(string &str){
  vector<int> freq(26, 0);
  for(char ch : str){
      freq[ch - 'a']++;
  }
  return freq;
}

// * CONSTANT TIME
vector<int> intersection(vector<int> s1, vector<int> s2){
  vector<int> temp(26,0);
  for(int i = 0; i < 26; i++) {
      temp[i] = min(s1[i], s2[i]); // * Store the minimal frequency
  }
  return temp;
}

// *T.C : O(n*m) , whete n = words.length() and m = length of the longest word
vector<string> commonChars(vector<string>& words) {
  vector<int> last = count(words[0]);

  for(int i = 1; i < words.size(); i++){
      vector<int> currVec = count(words[i]); // * Count each character's freq in current string at words[i]]
      last = intersection(last, currVec);
  }

  vector<string> ans;

  for(int i = 0; i < 26; i++){
      while(last[i] > 0){
          string temp = "";
          temp += i + 'a';
          ans.push_back(temp);
          last[i]--;
      }
  }
  return ans;
}