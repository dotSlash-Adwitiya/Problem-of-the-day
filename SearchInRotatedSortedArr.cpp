#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int l, int h, int key){
  
  while(l <= h) {
      int mid = l+(h-l)/2;
      
      if(arr[mid] == key)
          return mid;
          
      if(arr[l] <= arr[mid]){
          if(key >= arr[l] && key <= arr[mid])  
              h = mid - 1;
          else 
              l = mid + 1;
      } 
      
      else  {
          if(key >= arr[mid] && key <= arr[h])
              l = mid + 1;
          else 
              h = mid - 1;
      }
  }
  return -1;
}