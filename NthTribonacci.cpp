#include<bits/stdc++.h>
using namespace std;


// * OPTIMISED Solution in One Go.
// * T.C : O(n), S.C : O(1)
int tribonacci(int n) {

    // * Base cases
    if(n == 0)
        return 0;
    if(n == 1 || n == 2)
        return 1;

    int t0 = 0, t1 = 1, t2 = 1;
    
    // * n-2 logic is the give eqn is : Tn+3 = Tn + Tn+1 + Tn+2;
    for(int i = 1; i <= n-2; i++){
        int temp = t2;
        t2 = t0 + t1 + t2;    
        t0 = t1;
        t1 = temp;
    }
    return t2;
}