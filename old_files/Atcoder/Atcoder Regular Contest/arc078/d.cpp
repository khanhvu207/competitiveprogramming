#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
int n,cnt[N],par[N],depth[N];
vector<int> adj[N];

void dfs(int u,int p){
	cnt[u]=1;
	for(int v:adj[u])
		if(v!=p){
			par[v]=u;
			depth[v]=depth[u]+1;
			dfs(v,u);
			cnt[u]+=cnt[v];
		}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	int v=n;
	for(int i=0;i<(depth[n]-1)/2;++i) v=par[v];
	if(2*cnt[v]<n) cout<<"Fennec\n";
	else cout<<"Snuke\n";
}


