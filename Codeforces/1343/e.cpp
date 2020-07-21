#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m,a[3],dist[3][N];
ll p[N],prefix[N];
vector<int> adj[N];

void read(){
	cin>>n>>m>>a[0]>>a[1]>>a[2];
	for(int i=1;i<=n;++i){
		adj[i].clear();
		dist[0][i]=dist[1][i]=dist[2][i]=-1;
	}
	for(int i=1;i<=m;++i) cin>>p[i];
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(p+1,p+m+1);
	for(int i=1;i<=m;++i) prefix[i]=prefix[i-1]+p[i];
}

void solve(){
	for(int i=0;i<3;++i){
		queue<int> Q;
		Q.push(a[i]);
		dist[i][a[i]]=0;
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			for(int v:adj[u]) if(dist[i][v]==-1){
				dist[i][v]=dist[i][u]+1;
				Q.push(v);
			}
		}
	}
	ll res=1e18;
	for(int i=1;i<=n;++i){
		int totalLength=dist[0][i]+dist[1][i]+dist[2][i];
		if(totalLength>m) continue;
		// wtf, did i used std::accumlation instead of prefix sum !*@#&(
		ll cost=prefix[dist[1][i]]+prefix[totalLength];
		res=min(res,cost);
	}
	cout<<res<<'\n';
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		read();
		solve();
	}
}