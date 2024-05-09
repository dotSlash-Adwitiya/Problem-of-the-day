#include<bits/stdc++.h>
using namespace std;

// * T.C : O(nLogn), S.C : O(1)
long long maximumHappinessSum(vector<int>& happiness, int k) {
  sort(happiness.begin(), happiness.end());
  
  int currHappiness = 0;
  long long maxHappiness = 0;
  int i = happiness.size() - 1; // For traversing
  int j = 0; // For keeping track of k

  while(i >= 0 && j < k) {
      // * Checking for >= 0 because its mentioned, happiness won't decreased beyond 0.
      // * CurrHappiness's value will inc in every element and will be subtracted from the actual value 
      maxHappiness += ((happiness[i] - currHappiness) >= 0 ? (happiness[i] - currHappiness) : 0 );
      currHappiness++;
      i--;
      j++;
  }
  return maxHappiness;
}