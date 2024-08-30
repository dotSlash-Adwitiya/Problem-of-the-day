#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int LARGE_VALUE = 2e9;
typedef pair<long, long> P;

ll DijkstraAlgo(vector<vector<int>>& edges, int n, int src, int dest) {
  //make the graph excluing -1 et edges
  unordered_map<ll, vector<pair<ll, ll>>> adj; //u -> (v, wt)

  // * CREATE A GRAPH ADJACENCY
  for(vector<int>& edge : edges) {
      if(edge[2] != -1) {
          int u  = edge[0];
          int v  = edge[1];
          int wt = edge[2];

          adj[u].push_back({v, wt});
          adj[v].push_back({u, wt});
      }
  }

  // * Priority QUEUE
  priority_queue<P, vector<P>, greater<P>> pq;
  
  // * result[i] = shortest path distance of src to ith node
  vector<ll> result(n, INT_MAX); 
  vector<bool> visited(n, false);

  // * Initial CONFIG
  result[src] = 0; 
  pq.push({0, src});

  while(!pq.empty()) {
      auto [currDist, currNode] = pq.top();
      pq.pop();

      if(visited[currNode] == true) continue;
      
      // * MARK VISITED
      visited[currNode] = true;

      for(auto&[nbr, wt] : adj[currNode]) {
          if(currDist + wt < result[nbr]) {
              result[nbr] = currDist + wt; //  *Update the shorter distance
              pq.push({result[nbr], nbr}); // * Push into PQ
          }
      }
  }
  return result[dest];
}

vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
  ll currShortestDist = DijkstraAlgo(edges, n, source, destination);

  // * We can never make the target, because the shortest path is less than target
  if(currShortestDist < target) 
      return {};
  
  bool matchedTarget = (currShortestDist == target);

  for(vector<int>& edge : edges) {
      if(edge[2] == -1) {

          edge[2] = (matchedTarget == true) ? LARGE_VALUE : 1; //assign lowest number i.e. 1
          if(!matchedTarget) {
              ll newShortestDist = DijkstraAlgo(edges, n, source, destination);

              if(newShortestDist <= target) {
                  matchedTarget = true;
                  edge[2] += (target - newShortestDist);
              }
          }
      }
  }

  if(matchedTarget == false) 
      return {};
  return edges;
}