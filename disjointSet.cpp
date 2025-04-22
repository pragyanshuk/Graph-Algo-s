/******************************************************************************
Disjoint Set
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int findPar(int i,vector<int>&par) {
	if(i == par[i]) {
		return i;
	}
	return(par[i] = findPar(par[i],par));
}

void unionByRank(int u,int v,vector<int>&rank,vector<int>&par) {
	int pu = findPar(u,par);
	int pv = findPar(v,par);
	if(pu == pv) return;
	else if(rank[pu]<rank[pv]) {
		par[pu] = pv;
	}
	else if(rank[pv]<rank[pu]) {
		par[pv] = pu;
	}
	else {
		par[pu] = pv;
		rank[pv]++;
	}
	return;
}

int main()
{
	int n = 7;
	vector<int>rank(n+1,0);
	vector<int>par(n+1);
	for(int i=0; i<=n; i++) {
		par[i] = i;
	}

	unionByRank(1,2,rank,par);
	unionByRank(2,3,rank,par);
	unionByRank(4,5,rank,par);
	unionByRank(6,7,rank,par);
	unionByRank(5,6,rank,par);
	if(findPar(3,par) == findPar(7,par)) {
		cout<<"Belong to same component"<<endl;
	}
	else {
		cout<<"Not same"<<endl;
	}
	unionByRank(3,7,rank,par);
	if(findPar(3,par) == findPar(7,par)) {
		cout<<"Belong to same component"<<endl;
	}
	else {
		cout<<"Not same"<<endl;
	}

}