#include<bits/stdc++.h>
using namespace std;

// Find Prefix
bool isPrefix(string element, string prefix) {
  if(prefix.length() > element.length())
    return false;

  for(int i = 0; i < prefix.length(); i++)
    {
      if(element[i] != prefix[i])
        return false;
    }
    return true;
}

// Find Suffix
bool isSuffix(string element, string suffix) {
    if(suffix.length() > element.length())
    return false;
    
  for(int i = suffix.length()-1; i >= 0; i--)
    {
      if(suffix[i] != element[element.length() - suffix.length() + i])
        return false;
    }
    return true;
}

int prefixSuffixString(vector<string> &s1,vector<string> s2){
    int k = 0; 
    // int n1 = s1.size(); // Size of s1 vector of string
    int n2 = s2.size(); // Size of s2 vector of string
    
    int ans = 0;

    //   int cnt=0;
        for(int i=0; i<n2; i++) {  // Traverse on 2nd substring
            string prefix = s2[i];
            for (string element : s1) {
                if(isPrefix(element, prefix) || isSuffix(element, prefix)) {
                    ans++;
                    break;
                }
            }
        }
    return ans;
}

int main()
{

  return 0;
}