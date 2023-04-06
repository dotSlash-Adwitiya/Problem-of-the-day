#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)

using namespace std;


int equalSum(int n, vector<int> &A) {
    vector<int> v1(n), v2(n);
    int sum1 = 0, sum2 = 0;
    
    if(n==1)
        return A[0];
    
    for(int i = 0; i < n; i++) {
        sum1 += A[i];
        v1[i] = sum1;
    }
    for(int i = n-1; i >= 0; i--) {
        sum2 += A[i];
        v2[i] = sum2;
        // sum2 += A[i];
    }
    for(auto i: v2)
      cout << i << " ";

    int ans = -1;
    
    for(int i = 0; i < n-1; i++)
    {
        if(i == 0){
            if(v2[i+1] == 0){
              ans = i+1;
              break;
            }
        }
        else if(v1[i-1] == v2[i+1]) {
            ans = i+1;
            break;
        }
    }
    return ans;
}

//* Approach 2 using O(1) Auxillary Space 
int equalSum(int N, vector<int> &A) {
        
    if(N==1)
        return N;

    int preSum = 0, sum = 0;
    for(auto &i : A) sum += i;

    int cnt = 0;
    for(auto &i : A) {
        if(sum - preSum - i == preSum)
            return cnt+1;
        preSum += i;    
        cnt++;
    }
    return -1;
}


int main()
{
  vector<int> v = {1,3,5,2,2};

  cout << equalSum2(5,v) << endl;

  return 0;
}
