// just try 3 possible initial colour of the root.

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
vector<int> adj[N];
int n,color[N];
ll cost[3][N],total;

void dfs(int u){
	set<int> used;
	total+=cost[color[u]][u];
	used.insert(color[u]);
	for(int v:adj[u]) if(color[v]!=-1) used.insert(color[v]);
	for(int v:adj[u]) 
		if(color[v]==-1){
			for(int j=0;j<3;++j)
				if(used.find(j)==used.end()){
					color[v]=j;
					dfs(v);
					break;
				}
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
	for(int i=0;i<3;++i) for(int j=1;j<=n;++j) cin>>cost[i][j];
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;++i) 
		if((int)adj[i].size()>=3){
			cout<<-1;
			return 0;
		}
	int u=1,v=adj[1][0],col1=-1,col2=-1;
	ll best=numeric_limits<ll>::max();
	for(int i=0;i<2;++i)
		for(int j=i+1;j<3;++j){
			color[u]=i,color[v]=j;
			for(int k=0;k<2;++k,swap(color[u],color[v])){
				total=0;
				for(int t=1;t<=n;++t) if(t!=u&&t!=v) color[t]=-1;
				dfs(u),dfs(v);
				if(total<best){
					best=total;
					col1=color[u],col2=color[v];
				}
			}
		}
	color[u]=col1,color[v]=col2;
	for(int i=1;i<=n;++i) if(i!=u&&i!=v) color[i]=-1;
	dfs(u),dfs(v);
	cout<<best<<'\n';
	for(int i=1;i<=n;++i) cout<<color[i]+1<<' ';
}