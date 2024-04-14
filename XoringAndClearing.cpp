#include<bits/stdc++.h>
using namespace std;

void printArr(int n, int arr[]) {
  // Your code for printing array here
  for(int i = 0; i < n; i++)
      cout << arr[i] << " ";
  cout << endl;
}

void setToZero(int n, int arr[]) {
  // Use memset to set arr to zero
  memset(arr, 0, n * sizeof(int)); // * IMP : Multiply by the size of arr with data type!
}

void xor1ToN(int n, int arr[]) {
  for(int i = 0; i < n; i++)
      arr[i] ^= i;
}