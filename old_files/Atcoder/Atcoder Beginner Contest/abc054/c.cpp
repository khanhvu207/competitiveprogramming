#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
bool adj[10][10];

int go(int u,int mask){
	int cnt=0;
	for(int v=0;v<n;++v)
		if(!(mask>>v&1)&&adj[u][v]){
			int nmask=mask|(1<<v);
			if(nmask==(1<<n)-1) return 1;
			else cnt+=go(v,mask|(1<<v));
		}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	memset(adj,false,sizeof adj);
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		--u,--v;
		adj[u][v]=adj[v][u]=true;
	}
	cout<<go(0,1)<<'\n';
}


