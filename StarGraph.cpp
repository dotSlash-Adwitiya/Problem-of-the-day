#include<bits/stdc++.h>
using namespace std;

// * T.C : O(N), S.C: O(N)
int findCenter(vector<vector<int>>& edges) {
  int V = edges.size();
  
  unordered_map<int,int> ump;

  for(int i = 0; i < edges.size(); i++){
      for(int j = 0; j < edges[0].size(); j++){
          ump[edges[i][j]]++;
      }
  }

  for(auto ele: ump)
      if(ele.second == V)
          return ele.first;

  return -1;
}

/*
  * After doing some observations, we see that :
  * Every node is connected to exactly 1 node
  * That means if there's a central node,
  * Than it will be present in at least two edges, so just check that!
*/

// * T.C: O(1), S.C: O(1)
int findCenter(vector<vector<int>>& edges) {
    if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        return edges[0][0];
    return edges[0][1];   
}