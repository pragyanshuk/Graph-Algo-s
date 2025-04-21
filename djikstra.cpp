/******************************************************************************
Djikstra's Algo - Shortest path from src to all vertices in undirected weighted graph.
TC - O(ELo)
SC - O(N)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void computeDistArray(vector<pair<int,int>>adj[],vector<int>&dist,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&minpq){
    while(!minpq.empty()){
        pair<int,int> p = minpq.top();
        minpq.pop();
        int weight = p.first;
        int node = p.second;
        for(int j=0;j<adj[node].size();j++){
            if(dist[adj[node][j].first] > weight + adj[node][j].second){
                dist[adj[node][j].first] = weight + adj[node][j].second;
                minpq.push(make_pair(dist[adj[node][j].first],adj[node][j].first));
            }
        }
    }
    return;
}

int main()
{
    int n = 6;
    int src = 0;
    vector<pair<int,int>>adj[n];
    vector<pair<int,int>>v0{{1,4},{2,4}};
    vector<pair<int,int>>v1{{0,4},{2,2}};
    vector<pair<int,int>>v2{{0,4},{1,2},{3,3},{4,1},{5,6}};
    vector<pair<int,int>>v3{{2,3},{5,2}};
    vector<pair<int,int>>v4{{2,1},{5,3}};
    vector<pair<int,int>>v5{{2,6},{3,2},{4,3}};
    
    adj[0] = v0, adj[1] = v1, adj[2] = v2, adj[3] = v3, adj[4] = v4, adj[5] = v5;
    
    vector<int>dist(n,1e9);
    dist[src] = 0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minpq; // {dist,node}
    minpq.push(make_pair(0,0)); // {0,src}
    
    computeDistArray(adj,dist,minpq);
    
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}