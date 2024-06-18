#include<bits/stdc++.h>
using namespace std;



// * T.C : O(nlogn)
// * S.C : O(n)
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
  priority_queue<pair<int,int>> pq;
  sort(worker.begin(), worker.end());
  int maxProfit = 0;

  // * Sort according to MAX PROFIT and NOT According to difficulty!
  for(int i = 0; i < difficulty.size(); i++)
      pq.push({profit[i], difficulty[i]});
  
  // * For debugging purpose
  // while(!pq.empty()) {
  //     cout << "Difficulty: " << pq.top().first << ", Profit: " << pq.top().second << endl;
  //     pq.pop();
  // }

  for(int i = worker.size() - 1; i >= 0; i--) {
      int currDiff = worker[i];

      //* If the difficulty is greater than this element's profit cannot be included in our answer so pop() 
      while(!pq.empty() && pq.top().second > currDiff) 
        pq.pop();
      
      if(pq.empty()) break;
      
      maxProfit += pq.top().first;
  }
  return maxProfit;
}