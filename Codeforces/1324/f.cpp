#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,val[N],f[N],res[N];
vector<int> g[N];

void dfs1(int u,int p){
	f[u]=val[u];
	for(int v:g[u]) 
		if(v!=p){
			dfs1(v,u);
			if(f[v]>0) f[u]+=f[v];
		}
}

void dfs2(int u,int p,int lazy){
	res[u]=f[u];
	int total=val[u];
	if(lazy>0) res[u]+=lazy,total+=lazy;
	for(int v:g[u]) if(v!=p&&f[v]>0) total+=f[v];
	for(int v:g[u]) 
		if(v!=p){
			int down=total;
			if(f[v]>0) down-=f[v];
			dfs2(v,u,down);
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
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		val[i]=!x?-1:1;
	}
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,-1);
	dfs2(1,-1,0);
	for(int i=1;i<=n;++i) cout<<res[i]<<' ';
}