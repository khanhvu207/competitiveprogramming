// take arbitrary k nodes from G
// if there is a cycle, print it
// else, G' induced from G is a forest, and we could do bi-coloring
// what an elegent problem!

#include <bits/stdc++.h>
#define ll int64_t

const int N=1e5+5;
int n,m,k,par[N];
bool vst[N];
std::vector<int> adj[N],s[2];

void dfs(int u,int p,int col){
	vst[u]=true;
	s[col].push_back(u);
	for(int v:adj[u])
		if(v!=p){
			if(vst[v]){
				std::vector<int> cyc;
				while(u!=v){
					cyc.push_back(u);
					u=par[u];
				}
				cyc.push_back(v);
				std::cout<<2<<'\n'<<(int)cyc.size()<<'\n';
				for(int node:cyc)
					std::cout<<node<<' ';
				exit(0);
			}
			par[v]=u;
			dfs(v,u,col^1);
		}
}

int main() {
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n>>m>>k;
	n=k;
	for(int i=0;i<m;++i){
		int u,v;
		std::cin>>u>>v;
		if(u>k||v>k) continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=k;++i)
		if(!vst[i]) dfs(i,-1,0);
	std::cout<<1<<'\n';
	if(s[0].size()>s[1].size()) std::swap(s[0],s[1]);
	for(int i=0;i<(k+1)/2;++i)
		std::cout<<s[1][i]<<' ';
}