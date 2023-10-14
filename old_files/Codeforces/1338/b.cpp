#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=1e5+5;
int n,deg[MX],depth[MX];
vector<int> adj[MX];

void dfs(int u,int p){
	for(int v:adj[u]) if(v!=p){
		depth[v]=depth[u]+1;
		dfs(v,u);
	}
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		++deg[u],++deg[v];
	}
	int k=1,fMin=1,fMax=n-1;
	for(int i=1;i<=n;++i) if(deg[i]==1) k=i;
	dfs(k,-1);
	bool odd=false,even=false,three=false;
	for(int i=1;i<=n;++i) if(i!=k&&deg[i]==1){
		odd|=depth[i]&1;
		even|=!(depth[i]&1);
		if(depth[i]&1) three|=depth[i]>=3;
	}
	if((odd&&even)||(!even&&three)) fMin=3;
	for(int i=1;i<=n;++i){
		int leaves=0;
		for(int j:adj[i]) if(j!=i&&deg[j]==1) ++leaves;
		if(leaves>1) fMax-=leaves-1;	
	}
	cout<<fMin<<' '<<fMax;
}