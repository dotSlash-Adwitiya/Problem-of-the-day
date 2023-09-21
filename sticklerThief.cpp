#include<bits/stdc++.h>
using namespace std;

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

int FindMaxSum(int arr[], int n)
{
    return recursion(arr, n, 0);
}

int main()
{

  return 0;
}