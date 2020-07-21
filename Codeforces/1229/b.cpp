#include <bits/stdc++.h>
#define ll int64_t

const ll M=1E9+7;
const int N=1e5+5;
int n;
ll a[N];
std::map<ll,ll> Map[N];
std::vector<int> adj[N];

void dfs(int u,int p){
	Map[u].emplace(a[u],1);
	if(p!=-1){
		for(auto it:Map[p]){
			ll y=std::__gcd(it.first,a[u]);
			if(!Map[u].count(y)) Map[u].emplace(y,it.second);
			else Map[u][y]+=it.second;
		}
	}
	for(int v:adj[u])
		if(v!=p) dfs(v,u);
}

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(0);
	std::cin>>n;
	for(int i=1;i<=n;++i) std::cin>>a[i];
	for(int i=0;i<n-1;++i){
		int u,v;std::cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	ll res=0;
	for(int i=1;i<=n;++i){
		ll total=0;
		for(auto it:Map[i])
			(total+=it.first*it.second%M)%=M;
		(res+=total)%=M;
	}
	std::cout<<res<<'\n';
}	