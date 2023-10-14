#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=5e5+5;
int n,m,p[N],low[N];
bool vst[N];
vector<int> adj[N],col[N];

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
	for(int i=1;i<=n;++i){
		cin>>p[i];
		col[p[i]].push_back(i);
	}
	set<int> s;
	for(int i=1;i<=n;++i){
		s.clear();
		bool ok=true;
		for(int v:adj[i]){
			if(p[v]<p[i]) s.insert(p[v]);
			if(p[v]==p[i]) ok=false;
		}
		if(p[i]-1!=(int)s.size()||!ok){
			cout<<-1;
			return 0;
		}
	}
	for(int i=1;i<=n;++i) for(int u:col[i]) cout<<u<<' ';
}