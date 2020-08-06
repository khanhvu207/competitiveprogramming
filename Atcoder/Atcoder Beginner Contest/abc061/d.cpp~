#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> P;

const int N=1005;
const ll INF=1e18;
int n,m;
vector<P> adj;
vector<int> nxt[N],rev[N];
ll c[N][N],d[N],dp[N];
vector<int> topo;
bool neg[N];

void neg_cycle(){
	for(int i=1;i<=n;++i)
		d[i]=INF;
	d[1]=0;
	for(int i=0;i<n-1;++i){
		for(auto it:adj){
			int u=it.first;
			int v=it.second;
//			if(d[u]==INF) continue;
			if(d[u]+c[u][v]<d[v]) 
				d[v]=d[u]+c[u][v];
		}
	}
	for(int i=0;i<n-1;++i){
		for(auto it:adj){
			int u=it.first;
			int v=it.second;
//			if(d[u]==INF) continue;
			if(d[u]+c[u][v]<d[v]){
				d[v]=d[u]+c[u][v];
				neg[v]=true;
			}
			neg[v]|=neg[u];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		c[u][v]=-w;
		adj.emplace_back(u,v);
	}
	neg_cycle();
	if(neg[n]) cout<<"inf\n";
	else cout<<-d[n]<<'\n';
}


