#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i =0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    //creation of distance array with infinte value initially
    vector<int> dist(vertices);
    for(int i =0;i<vertices;i++)
        dist[i] = INT_MAX;
    
    //creation of set on basis (distance, node)
    set<pair<int,int>> s;
    
    //initialse distance and set with source node
    dist[source] = 0;
    s.insert({0,source});
    
    
    while(!s.empty()){
        //fetchh top record
        auto top = *(s.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
       //remove top record
        s.erase(s.begin());
         for(auto neighbour:adj[topNode]){
            int child=neighbour.first;
            int wt=neighbour.second;
            if(dist[child]>nodeDistance+wt){
                dist[child]= nodeDistance + wt;
                s.insert({dist[child],child});
            }
        }
    }
    return dist;
}
