#include<bits/stdc++.h>
using namespace std;



//* By creating the sum variable approach TC :O(n), SC : O(1)
int equilibriumPoint(long long a[], int n) {

  long long sum = 0, currSum = 0;
  
  for(long long i = 0; i < n; i++) 
      sum += a[i];
      
  for(long long i = 0; i < n; i++) {
      currSum += a[i];
      
      if((currSum-a[i]) == (sum-a[i]))
          return i+1;
      sum -= a[i];
  }
  return -1;
}

//* Most Optimised! - W/O Sum variable Approach !! - gPrefix SUM
int equilibriumPoint(long long a[], int n) {
    if(n==1)return 1;
    
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    
    for(int i=1;i<n-1;i++){
        if(a[i-1]==(a[n-1]-a[i]))return i+1;
    }
    
    return -1;
}

int main()
{

  return 0;
}