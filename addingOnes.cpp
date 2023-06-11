#include<bits/stdc++.h>
using namespace std;

//* BRUTE FORCE Approach Tc: O(n^2)
void update(int a[], int n, int updates[], int k)
{
    for(int i = 0; i < k; i++) {
        int ele = updates[i];
        for(int j = 0; j < n; j++) {
            if(j+1 >= ele)
                a[j] += 1;
        }
    }
}

void update(int a[], int n, int updates[], int k)
{
    for(int i= 0; i < k; i++) a[updates[i]-1]++;
    
    for(int i = 1; i < n; i++) a[i] += a[i-1];
}


int main()
{
  int arr[] = {1,2,3,4,5};

  vector<int> v = {10,20,30,40,50};


  return 0;
}