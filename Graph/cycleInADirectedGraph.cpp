#include<bits/stdc++.h>
bool checkcycle(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj){
    visited[node] = true;
    dfsvisited[node] = true;
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycle = checkcycle(neighbour,visited,dfsvisited,adj);
            if(cycle)
                return true;
        }
        else if(dfsvisited[neighbour]){
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cyclefound = checkcycle(i,visited,dfsvisited,adj);
            if(cyclefound)
                return true;
        }
    }
    return false;
}