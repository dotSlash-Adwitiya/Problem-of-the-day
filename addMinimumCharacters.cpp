#include<bits/stdc++.h>
using namespace std;

//* BRUTE FORCE Approach by finding the length of the longest palindrome in the string from the prefix of the given string,
//* And subtracting it from the overall length of the given string.

//* Palindromic Function below :
bool isPalindrome(string str) {
    int i = 0;
    int j = str.size()-1;

    while(i < j){
        if(str[i] != str[j])
            return false;
        i++;
        j--;    
    }
    return true;
}

int addMinChar(string str){    

    int n = str.size();
    // int cntConsecutive = 0;

    string temp = "";
    int ans = 0;
    for(int i = 0; i < n; i++) {
        temp += str[i];
        if(isPalindrome(temp) && ans < temp.size())
            ans = temp.size();
    }

    return n-ans;
}

int main()
{
  string str = "AASFASA";
  cout << "Minimum character required to be added to the front of the string to make it a palindrome are : " << addMinChar(str) << endl; 
  
  return 0;
