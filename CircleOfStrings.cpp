#include<bits/stdc++.h>
using namespace std;

// * Problem Link: https://www.geeksforgeeks.org/problems/circle-of-strings4530/1
void dfs(int node, vector<int> adj[], vector<bool> &vis){
  if(!vis[node]) return;
  
  // * Mark nodes as unvisited
  /*
    * If after DFS, some nodes are left visited, meaning a CHAIN
    * is NOT FORMED !!
  */
  vis[node] = false;
  
  for(int &ele:adj[node])
      dfs(ele, adj, vis);
}
int isCircle(vector<string> &arr) {
  vector<int> adj[26];
  vector<int> indegree(26, 0), outdegree(26,0);
  vector<bool> vis(26, 0);
  
  for(int i = 0; i < arr.size(); i++){
      int u = arr[i][0]-'a';
      int v = arr[i].back()-'a';
      
      // * Create an edge b/w u and v
      adj[u].push_back(v);
      
      // * Count indegree and outdegree
      indegree[u]++;
      outdegree[v]++;
      
      // * Mark them as visited
      vis[u] = true;
      vis[v] = true;
  }
  
  if(indegree != outdegree) return 0;
  dfs(arr[0][0] - 'a', adj, vis);
  
  for(int i = 0; i < 26; i++)
      if(vis[i])
          return 0;
  return 1;
}
