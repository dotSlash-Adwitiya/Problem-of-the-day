#include<bits/stdc++.h>
using namespace std;


//* THOUGHT Process to come up with recursive solution - 
// * Ese toh kitne bi elements ho skte h jo bade ho, chote ho !
//* Sabko kese include or exclude ek ek krke dekha ja skta h !! ??

//* Jab sare elements ko include exclude krne ka case aae or bhot sare elements ban reh ho, tab 
//* You can utilise recursion
int recursion(int arr[], int n, int index)
{
    // Base case
    if (index >= n) {
        return 0;
    }

    // Taking the current house
    int taking = arr[index] + recursion(arr, n, index + 2);

    // Not taking the current house
    int notTaking = recursion(arr, n, index + 1);

    return max(taking, notTaking);
}

//* First ever DP Optimisation by MYSELF !!! (After seeing the recursive solution !)
//* MEMOIZATION - 
int recursion(int arr[], int n, int index, vector<int> &dp)
{
  // Base case
  if (index >= n) {
      return 0;
  }

  if(dp[index] != 0)
      return dp[index];
  // Taking the current house
  int taking = arr[index] + recursion(arr, n, index + 2, dp);
  // Not taking the current house
  int notTaking = recursion(arr, n, index + 1, dp);
  dp[index] = max(taking, notTaking);
  return dp[index];
}

int FindMaxSum(int arr[], int n)
{
  vector<int> dp(n+1, 0);
  return recursion(arr, n, 0, dp);
}

int FindMaxSum(int arr[], int n)
{
    return recursion(arr, n, 0);
}

int main()
{

  return 0;
}