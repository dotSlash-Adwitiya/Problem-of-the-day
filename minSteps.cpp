#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

int minSteps(string str) {
    
    int n = str.size(), a = 0, b = 0;
    char prev = str[0];
    
    rep(i,0,n-1) {
        if(i == 0) {
            if(str[i] == 'a')
                a++;
            else
                b++;
            prev = str[i];
        }
        else{
            if(str[i] != prev && str[i] == 'a')
                a++;
            if(str[i] != prev && str[i] == 'b')
                b++;
            prev = str[i];
        }
    }
    if(a == b)
        return a+1;
    return max(a,b);
}


int main()
{
  cout << minSteps("aabbbaababbabaaa") << endl;
  return 0;
}