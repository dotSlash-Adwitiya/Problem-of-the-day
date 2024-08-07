#include<bits/stdc++.h>
using namespace std;

int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
  vector<int> merged;
  
  for(int i = 0; i < arr1.size(); i++) merged.push_back(arr1[i]);
  for(int i = 0; i < arr2.size(); i++) merged.push_back(arr2[i]);
  
  sort(merged.begin(), merged.end());
  
  return merged[k-1];
}

int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {

  vector<int> merged(arr1);
  merged.insert(merged.end(), arr2.begin(), arr2.end());
  
  sort(merged.begin(), merged.end());
  
  return merged[k-1];
}