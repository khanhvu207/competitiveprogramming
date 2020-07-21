#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=2e5+5;
int n,m;
vector<int> adj[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool ok=false;
	for(int i=1;i<=n;++i){
		sort(adj[i].begin(),adj[i].end());
		if(int(adj[i].size())<2) continue;
		if(adj[i][0]==1&&adj[i].back()==n) ok=true;
	}
	cout<<(ok?"POSSIBLE\n":"IMPOSSIBLE\n");
}

