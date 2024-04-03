#include<bits/stdc++.h>
using namespace std;


int lengthOfLastWord(string str) {
    int i = str.size()-1;
    int ansLength = 0;

    while(i >= 0 && str[i] == ' ')
        i--;
    
    while(i >= 0 && str[i] != ' ') {
        ansLength++;
        i--;
    }

    return ansLength;
}