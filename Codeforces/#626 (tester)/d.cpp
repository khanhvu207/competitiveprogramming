#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1005;
int n,p[N],depth[N],deg[N];
vector<int> G[N];

void dfs(int u){
	for(int v:G[u])	
		if(v!=p[u]){
			p[v]=u;
			depth[v]=depth[u]+1;
			dfs(v);
		}
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		++deg[u];
		++deg[v];
	}
	p[1]=0;
	dfs(1);
	vector<bool> marked(n+1,false);
	int counter=n/2;
	bool ok=false;
	while(counter--){
		int u=-1,v=-1;
		for(int i=1;i<=n;++i) if(!marked[i]&&deg[i]==1){ u=i; break;}
		for(int i=1;i<=n;++i) if(!marked[i]&&i!=u&&deg[i]==1){ v=i; break;}
		cout<<"? "<<u<<' '<<v<<endl;
		int f; cin>>f;
		if(f==u||f==v){
			cout<<"! "<<f<<endl;
			ok=true;
			break;
		}
		for(int nxt:G[u]) --deg[nxt];
		for(int nxt:G[v]) --deg[nxt];
		marked[u]=marked[v]=true;
	}
	if(!ok){
		for(int i=1;i<=n;++i) 
			if(!marked[i]){
				cout<<"! "<<i<<endl;
				break;
			}
	}
	return 0;
}