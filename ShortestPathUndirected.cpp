#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
  vector<int> dist(N, 1e9);
  
  vector<int> adj[N];
  
  for(auto it: edges){
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
  }
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
  pq.push({0, src});  // {distance, node}
  
  dist[src] = 0;
  
  while(!pq.empty()) {
      int currDis = pq.top().first;
      int currNode = pq.top().second;
      pq.pop();
      
      for(auto &ele: adj[currNode]){
          if(currDis + 1 < dist[ele]){
              dist[ele] = currDis + 1;
              pq.push({currDis + 1, ele});
          }
      }
  }
  
  for(int i = 0; i < N; i++){
      if(dist[i] == 1e9)
          dist[i] = -1;
  }
          
  return dist;
  
}