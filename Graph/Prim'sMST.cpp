https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i =0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);
    
    key[1] = 0;
    parent[1] = -1;
    
    for(int i =0;i<n;i++){
        int mini = INT_MAX;
        int u;
        //find mini. wali node
        for(int v=1;v<=n;v++){
            if(!mst[v] && key[v]<mini){
                u=v;
                mini = key[v];
            }
        }
    // mark min node as true
        mst[u] = true;
        //check its adj node
        for( auto neighbour:adj[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            if(!mst[v] && w<key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    vector<pair<pair<int,int>,int>> ans;
    for(int i =2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
       
    }
    return ans;
}
