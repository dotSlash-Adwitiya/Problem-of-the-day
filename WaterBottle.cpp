#include<bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
  int ans = 0;
  for(int i = numBottles, emptyBottles = 0; i >= 0; i--){
      ans++;
      if(emptyBottles == numExchange){
          emptyBottles = 0;
          i++;
      }
      emptyBottles++;
  }
  return ans-1;
}