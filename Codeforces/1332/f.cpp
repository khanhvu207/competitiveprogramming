/*
	Dp on tree, black and white color considerations.
	UPD1: >.<
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=998244353;
const int N=3e5+5;
int n;
vector<int> adj[N];
ll res,f[N],b[N],w[N];

void dfs(int u,int p){
	b[u]=w[u]=1LL;
	f[u]=0LL;
	ll t=1LL,sum=0LL;
	for(int v:adj[u]) if(v!=p){
		dfs(v,u);
		(t*=(1LL+f[v])%MOD)%=MOD;
		(sum+=f[v])%=MOD;
		(b[u]*=(w[v]+1LL+f[v])%MOD)%=MOD;
		(w[u]*=(w[v]+b[v]+1LL+f[v])%MOD)%=MOD;
	}
	t=(t-1LL+MOD)%MOD;
	(f[u]+=b[u]+w[u]-2LL+MOD)%=MOD;
	(f[u]+=-t+MOD)%=MOD;
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
	dfs(1,-1);
	cout<<f[1];
}