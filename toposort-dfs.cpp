/******************************************************************************

TopoSort-DFS
TC - O(N+2*E)
SC - O(N)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int i,vector<int>adj[],vector<bool>&vis,stack<int>&st){
    vis[i] = true;
    for(int j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]]){
            findTopoSort(adj[i][j],adj,vis,st);
        }
    }
    st.push(i);
    return;
}

int main()
{
    int n = 6;
    
    vector<int>adj[n];
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);
    
    vector<bool>vis(n,false);
    stack<int>st;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            findTopoSort(i,adj,vis,st);
        }
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}