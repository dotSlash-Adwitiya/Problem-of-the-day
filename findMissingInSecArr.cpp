#include<bits/stdc++.h>
using namespace std;

vector<int> findMissing(int a[], int b[], int n, int m) 
{ 
    unordered_set<int> ds;
    vector<int> ans;
    
    // * Insert 2nd array's ALL element into set
    for(int i = 0; i < m; i++)
        ds.insert(b[i]);
    // * If any of the 1st array's element's not found then include it in the ans vector     
    for(int i = 0; i < n; i++){
        if(ds.find(a[i]) == ds.end())
            ans.push_back(a[i]);    
    }
    return ans;
} 