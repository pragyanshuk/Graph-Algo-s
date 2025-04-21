/******************************************************************************
Toposort - Shortest path from src to all vertices in DAG.
TC - O(N+E)
SC - O(N)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int i,int n,vector<pair<int,int>>adj[],vector<bool>&vis,stack<int>&st){
    vis[i] = true;
    for(int j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j].first]){
            findTopoSort(adj[i][j].first,n,adj,vis,st);
        }
    }
    st.push(i);
    return;
}

int main()
{
    int n = 7;
    int src = 6;
    vector<pair<int,int>>adj[n];
    adj[0].push_back(make_pair(1,2));
    adj[1].push_back(make_pair(3,1));
    adj[2].push_back(make_pair(3,3));
    adj[4].push_back(make_pair(0,3));
    adj[4].push_back(make_pair(2,1));
    adj[5].push_back(make_pair(4,1));
    adj[6].push_back(make_pair(4,2));
    adj[6].push_back(make_pair(5,3));
    
    vector<bool>vis(n,false);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            findTopoSort(i,n,adj,vis,st);
        }
    }
    
    vector<int>dist(n,1e9);
    dist[src] = 0;
    while(!st.empty()){
        int x = st.top();
        st.pop();
        for(int j=0;j<adj[x].size();j++){
            int node = adj[x][j].first;
            int weight = adj[x][j].second;
            if(dist[node]>dist[x]+weight){
                dist[node] = dist[x]+weight;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}