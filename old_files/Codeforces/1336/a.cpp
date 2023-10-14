#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=2e5+5;
int n,k,f[MX],s[MX],depth[MX];
vector<int> adj[MX];

void dfs(int u,int p=-1){
	s[u]=1;
	for(int v:adj[u]) if(v!=p){
		depth[v]=depth[u]+1;
		dfs(v,u);
		s[u]+=s[v];
	}
	f[u]=s[u]-depth[u];
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	depth[1]=1;
	dfs(1);
	sort(f+1,f+n+1,greater<int>());
	cout<<accumulate(f+1,f+n-k+1,0LL);
}