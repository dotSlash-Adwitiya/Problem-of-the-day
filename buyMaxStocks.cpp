#include<bits/stdc++.h>
using namespace std;

/*
//* Major learning from this question :
//* If you need to sort based on the combination of array's value (arr[i]) and index
//* Then you can make a separate arr of PAIRS ! and sort(), that sorting will be done based on pair.first
*/

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
  for(const auto& stock : vec) {
      int stocksCanBeBought = stock.second;
      int costForCurrDay = stock.first;
      while(stocksCanBeBought != 0 && amt - costForCurrDay >= 0){
          amt -= costForCurrDay;
          stocksCanBeBought -= 1;
          maxStocks++;
      }
  }
  
  return maxStocks;
}
