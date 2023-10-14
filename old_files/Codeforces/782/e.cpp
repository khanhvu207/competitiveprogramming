// Nice application of Euler Tour 
// Euler tour: List all vertices while doing DFS -> number of vertices show up = 2*n-1

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m,k;
bool vst[N];
vector<int> g[N],eulerTour;

void dfs(int u){
	vst[u]=true;
	eulerTour.push_back(u);
	for(int v:g[u]) if(!vst[v]){
		dfs(v);
		eulerTour.push_back(u);
	}
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	int r=(2*n-1)%k;
	for(int i=0;i<k;++i){
		vector<int> res;
		for(int j=0;j<(2*n-1)/k+(r>0);++j) 
			if(!eulerTour.empty()) {
				res.push_back(eulerTour.back());
				eulerTour.pop_back();
			}
		--r;
		cout<<(int)res.size()<<' ';
		for(int x:res) cout<<x<<' ';
		cout<<'\n';
	}
}