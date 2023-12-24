#include<bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int amt, int price[]){
  
  vector<pair<int, int>> vec;
  int maxStocks = 0;
  for(int i = 0; i < n; i++) 
      vec.push_back({price[i], i+1});
      
  // GREEDY Approach : Sorting on the basis of lowest value and highest index.    
  sort(vec.begin(), vec.end());
  
  // Debugging purpose
  // for(auto it = vec.begin(); it != vec.end(); it++) 
  //     cout << " Key : " << it->first << " Value: " << it->second << endl;
  
  // Self Explanatory Code :-
  for(auto it = vec.begin(); it != vec.end(); it++) {
      int stocksCanBeBought = it->second;
      int costForCurrDay = it->first;
      while(stocksCanBeBought != 0 && amt - costForCurrDay >= 0){
          amt -= costForCurrDay;
          stocksCanBeBought -= 1;
          maxStocks++;
      }
  }
  
  return maxStocks;
}
