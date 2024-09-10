#include<bits/stdc++.h>
using namespace std;

vector < int > giftsLeft(int n, int k, int q, vector < int > demands) {
  int capacity = n;
  vector<int> list;
  for (const int &demand : demands) {
    if (demand > n){
        list.push_back(-1);
    } else {
        if(n < k) n = capacity;
        n -= demand;
        if(n < k) n = capacity;
        list.push_back(n);
    }
  }
  return list;
}