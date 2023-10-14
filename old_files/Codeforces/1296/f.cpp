#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=5005;
int n, q, par[N], h[N], Map[N][N], res[N];
vector<int> g[N];
vector<tuple<int, int, int>> Q;

void dfs(int u, int p=-1){
	for(auto v:g[u]) if(v!=p){
		h[v]=h[u]+1;
		par[v]=u;
		dfs(v, u);
	}
}

void go(int a, int b, int v){
	if(h[a]<h[b]) swap(a, b);
	while(h[a]>h[b]){
		res[Map[a][par[a]]]=v;
		a=par[a];
	}
	while(a!=b){
		res[Map[a][par[a]]]=v;
		res[Map[b][par[b]]]=v;
		a=par[a], b=par[b];
	}
}

bool check(int a, int b, int v){
	if(h[a]<h[b]) swap(a, b);
	int low=1e6+1;
	while(h[a]>h[b]){
		low=min(low, res[Map[a][par[a]]]);
		a=par[a];
	}
	while(a!=b){
		low=min(low, res[Map[a][par[a]]]);
		low=min(low, res[Map[b][par[b]]]);
		a=par[a], b=par[b];
	}
	return low==v;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0; i<n-1; ++i){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		Map[u][v]=Map[v][u]=i;
	}
	cin>>q;
	while(q--){
		int a, b, v;
		cin>>a>>b>>v;
		Q.push_back(make_tuple(v, a, b));
	}
	sort(Q.begin(), Q.end());
	h[1]=1;
	par[1]=-1;
	dfs(1);
	for(auto i:Q){
		int a, b, v;
		tie(v, a, b)=i;
		go(a, b, v);
	}
	for(auto i:Q){
		int a, b, v;
		tie(v, a, b)=i;
		if(!check(a, b, v)){
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=0; i<n-1; ++i){
		if(!res[i]) res[i]=1;
		cout<<res[i]<<' ';
	}
}