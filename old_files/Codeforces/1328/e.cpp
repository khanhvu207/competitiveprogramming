#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m,d[N],p[30][N];
vector<int> adj[N];

void dfs(int u){
	for(int v:adj[u])
		if(v!=p[0][u]){
			d[v]=d[u]+1;
			p[0][v]=u;
			dfs(v);
		}
}

int get(int u,int h){
	for(int i=log2(d[u])+1;i>=0;--i)
		if(p[i][u]!=-1&&d[p[i][u]]>=h) u=p[i][u];
	return u;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	p[0][1]=-1;
	d[1]=1;
	dfs(1);
	for(int i=1;(1<<i)<=n;++i)
		for(int j=1;j<=n;++j) 
			if(p[i-1][j]!=-1)
				p[i][j]=p[i-1][p[i-1][j]];
	while(m--){
		int k;
		cin>>k;
		vector<int> v(k);
		for(int& x:v){
			cin>>x;
			if(x!=1) x=p[0][x];
		}
		sort(v.begin(),v.end(),[](int l,int r){
			return d[l]>d[r];
		});
		bool ok=true;
		for(int i=1;i<k;++i) ok&=v[i]==get(v[0],d[v[i]]);
		cout<<(ok?"YES\n":"NO\n");
	}
}