// sqrt(2*m) edges reversion in total!

#include <bits/stdc++.h>
#define ll int64_t

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(0);
	int n,m,q;
	std::cin>>n>>m;
	std::vector<ll> out(n+1,0);
	std::vector<std::vector<int>> rev;
	rev.resize(n+1);
	for(int i=m;i--;){
		int u,v;
		std::cin>>u>>v;
		if(u>v) std::swap(u,v);
		rev[u].push_back(v);
		++out[v];
	}
	ll res=0;
	for(int u=1;u<=n;++u) res+=out[u]*(ll)rev[u].size();
	std::cout<<res<<'\n';
	std::cin>>q;
	for(int _=q;_--;){
		int u;
		std::cin>>u;
		for(int v:rev[u]){
			res-=out[v]*(ll)rev[v].size();
			rev[v].push_back(u);
			out[v]--;
			res+=out[v]*(ll)rev[v].size();
		}
		res-=out[u]*(ll)rev[u].size();
		out[u]+=rev[u].size();
		rev[u].clear();
		std::cout<<res<<'\n';
	}
}