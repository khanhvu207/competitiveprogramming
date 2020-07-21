// do bfs and then do bipartitie check!
// UPD1: urghh, i should have check for more cases >w<

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
int n,m,res[N];
vector<int> adj[N];
int g[4];

bool bipartite(int u){
	bool ok=true;
	for(int v:adj[u]){
		if(res[v]==1) continue;
		if(res[v]!=0) ok&=res[v]!=res[u];
		else{
			res[v]=(res[u]==2)?3:2;
			ok&=bipartite(v);
		}
	}
	return ok;
}

bool check(int col){
	for(int u=1;u<=n;++u) if(res[u]==col){
		int c[4]={0};
		for(int v:adj[u]) 
			if(res[v]!=res[u]) ++c[res[v]];
			else return false;
		for(int i=1;i<=3;++i)
			if(i!=col&&c[i]!=g[i]) return false;
	}
	return true;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(res,-1,sizeof(res));
	queue<int> q;
	res[1]=1;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u])
			if(res[v]==-1){
				res[v]=res[u]^1;
				q.push(v);
			}
	}
	for(int i=1;i<=n;++i)
		if(res[i]==0){
			res[i]=2;
			if(!bipartite(i)){
				cout<<-1;
				return 0;
			}
		}
	for(int i=1;i<=n;++i) 
		if(res[i]>0) g[res[i]]++;
	if(!g[1]||!g[2]||!g[3]||(g[1]+g[2]+g[3])<n){
		cout<<-1;
		return 0;
	}
	if(!check(1)||!check(2)||!check(3)){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;++i) cout<<res[i]<<' ';
}