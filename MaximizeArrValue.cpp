#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int Maximize(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
        sum = (sum + (long)arr[i]*i) % mod;
    return sum;
}