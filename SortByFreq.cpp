#include<bits/stdc++.h>
using namespace std;

vector<int> sortByFreq(vector<int>& arr) {
  // * First create a map and count the frequency
  unordered_map<int, int> frequency;
  for(int &num : arr)
      frequency[num]++;
  
  // * Used a Custom Comparator for sorting
  // * This Comparator contains a lambda function with a compare List
  sort(arr.begin(), arr.end(), [&frequency](int a, int b){
      if(frequency[a] == frequency[b]){
          // * Sort by value if frequencies are the same
          return a < b;
      }
      // * Sort by frequency in descending order
      return frequency[a] > frequency[b];
  });
  return arr;
}