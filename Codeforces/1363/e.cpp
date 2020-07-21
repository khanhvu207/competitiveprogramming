// dfs from the root down to leaf nodes
// greedily pick cheaper descedants

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll inf=1e9;
const int N=2e5+5;
int n,b[N],w[N];
bool black[N],white[N];
vector<int> adj[N];
ll a[N];

ll dfs(int u,int p=-1,ll cost=inf){
	if(black[u]) ++b[u];
	if(white[u]) ++w[u];
	ll total=0;
	for(int v:adj[u]) 
		if(v!=p){
			total+=dfs(v,u,min(cost,a[u]));
			b[u]+=b[v];
			w[u]+=w[v];
		}
	if(cost>a[u]){
		ll cntSwap=min(b[u],w[u])*2;
		total-=cntSwap*cost;
		total+=cntSwap*a[u];
	}
	return total;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	int cb=0,cw=0;
	for(int i=1;i<=n;++i){
		int b,c;
		cin>>a[i]>>b>>c;
		if(b==c) continue;
		if(!b) black[i]=true,++cb;
		if(!c) white[i]=true,++cw;
	}
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(cb!=cw){
		cout<<-1;
		return 0;
	}
	ll res=2LL*cb*inf+dfs(1);
	cout<<res;
}