/*
	k < path(a, b): have to use the extra edge
	k = path(a, b): YES
	k > path(a, b):
		if parity of k and path(a, b) is the same -> YES
		else, consider using the extra edge. 
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
int n,depth[N],p[35][N];
vector<int> adj[N];

void dfs(int u){
	for(int v:adj[u]) if(v!=p[0][u]){
		depth[v]=depth[u]+1;
		p[0][v]=u;
		dfs(v);
	}
}

int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=log2(depth[u])+1;i>=0;--i) 
		if(p[i][u]!=-1&&depth[p[i][u]]>=depth[v]) u=p[i][u];
	if(u==v) return u;
	for(int i=log2(depth[u])+1;i>=0;--i)
		if(p[i][u]!=p[i][v]) u=p[i][u],v=p[i][v];
	return p[0][u];
}

int dist(int u,int v){
	return depth[u]+depth[v]-2*depth[lca(u,v)];
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
	}
	memset(p,-1,sizeof p);
	dfs(1);
	for(int i=1;(1<<i)<=n;++i)
		for(int u=1;u<=n;++u)
			if(p[i-1][u]!=-1) p[i][u]=p[i-1][p[i-1][u]];
	int t;
	cin>>t;
	while(t--){
		int x,y,a,b,k;
		cin>>x>>y>>a>>b>>k;
		int p=dist(a,b);
		int f=dist(a,x)+1+dist(y,b);
		int h=dist(a,y)+1+dist(x,b);
		bool ok=false;
		ok|=(p<=k&&!((p^k)&1));
		ok|=(f<=k&&!((f^k)&1));
		ok|=(h<=k&&!((h^k)&1));
		cout<<(ok?"YES\n":"NO\n");
	}
}