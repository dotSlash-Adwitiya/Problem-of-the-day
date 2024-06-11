#include<bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
  int maxi = 0;
  vector<int> ans;

  unordered_map<int,int> hash;
  
  // * For accessing later in ascending order
  map<int, int> ump1;

  unordered_map<int, int> ump2;

  // * For all existing ele
  for(auto ele: arr1) 
      hash[ele]++;

  // * For all non-existing ele
  for(auto ele: arr1) 
      ump1[ele]++;

  // * Debugging purpose
  // for(auto it : ump1)
  //     cout << it.first << " " << it.second << endl;
  
  for(auto ele: arr2) 
      ump2[ele]++;   


  // * Traverse on all array 2 elements to store in relatively sorted order
  for(auto ele : arr2){
      while(hash[ele] != 0){
          ans.push_back(ele);
          hash[ele]--;
      }
  }

  for(auto ele : ump1){
      int temp = ele.second;
      // * Put the non-existing elements in sorted ordere
      if(ump2.find(ele.first) == ump2.end()) {
          while(temp != 0){
              temp--;
              ans.push_back(ele.first);
          }
      }
  }

  return ans;
}