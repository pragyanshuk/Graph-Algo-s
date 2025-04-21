/******************************************************************************

TopoSort-BFS
TC - O(N+2*E)
SC - O(N)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int n,vector<int>adj[],vector<int>&indegree,vector<int>&toposort){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        toposort.push_back(x);
        q.pop();
        for(int j=0;j<adj[x].size();j++){
            indegree[adj[x][j]]--;
            if(indegree[adj[x][j]] == 0){
                q.push(adj[x][j]);
            }
        }
    }
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
    
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }
    vector<int>toposort;
    findTopoSort(n,adj,indegree,toposort);
    
    for(int i=0;i<n;i++){
        cout<<toposort[i]<<" ";
    }
    cout<<endl;
}