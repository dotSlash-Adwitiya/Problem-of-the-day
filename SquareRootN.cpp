#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int n) {
    long long int low = 1, high = n, mid = 0, ans = -1;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        }
        
        else high = mid - 1;
    }
    return ans;
}