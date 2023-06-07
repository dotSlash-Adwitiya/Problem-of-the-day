#include<bits/stdc++.h>
using namespace std;

//* BRUTE FORCE Approach - TC : O(n^2), SC O(1)
vector<int> leastPrimeFactor(int n) {
    vector<int> ans = {0,1};

    if(n == 2){
      ans.push_back(2);
      return ans;
    }

    for(int i = 2; i <= n; i++) {
      for(int j = 2; j <=n; j++)
        if(i%j == 0) {
          ans.push_back(j);
          break;
        }
    }
    return ans;
}

//* More Optimal Approach Using (Sieve Of Erastosthenes) TC : O(nlogn), SC : O(n)
vector<int> leastPrimeFactor(int n) {
         //* By default values are marked as false
  vector<int> sieve(n+1);

  //*Mark all of them as PRIME
  for(int i = 1; i<=n; i++)
    sieve[i] = i;

  //* Now applying the sieve of erastosthenes :
  for(int i = 2; i*i <=n; i++) 
    if(sieve[i] == i)   
      for(int j = i*i; j <= n; j+=i) 
        if(sieve[j] == j)
          sieve[j] = i;
      
    return sieve;
}



int main()
{ 
  cout << 4 % 2 << endl;
  
  return 0;
}
