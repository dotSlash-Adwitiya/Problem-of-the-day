#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr) {
  vector<int> p , n; // Vectors to hold positive and negative numbers
  for(auto it : arr) {
      if(it >= 0) p.push_back(it); // Add positive numbers to vector p
      else n.push_back(it); // Add negative numbers to vector n
  }
  
  int i = 0 , j = 0, k = 0;
  // Indexes for positive and negative vectors
  
  while (i < p.size() && j < n.size()) {
      arr[k++] = p[i++]; // Add positive number
      arr[k++] = n[j++]; // Add negative number
  }

  // Add remaining positive numbers, if any
  while (i < p.size()) 
      arr[k++] = p[i++];
  

  // Add remaining negative numbers, if any
  while (j < n.size()) 
      arr[k++] = n[j++];
}