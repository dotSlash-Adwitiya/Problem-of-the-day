#include <bits/stdc++.h> 
using namespace std;


void f(int openCnt, int closeCnt, string temp, vector<string> &v){
    if(closeCnt < 0 || openCnt < 0)
        return;

    if(closeCnt == 0 and openCnt == 0){
        v.push_back(temp);
        return;
    }

    if(openCnt > 0)
        f(openCnt - 1, closeCnt, temp + '(', v);
    
    if(closeCnt > openCnt)
        f(openCnt, closeCnt - 1, temp + ')', v);   
}

vector<string> balancedParantheses(int n)
{
    vector<string> v;
    f(n, n, "", v);
    return v;
}

