#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m,k,res,d[N],f[N];
bool marked[N];
vector<int> g[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=0;i<k;++i){
		int x;
		cin>>x;
		marked[x]=true;
	}
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> topo;
	queue<int> Q;
	memset(d,-1,sizeof d);
	Q.push(1);
	d[1]=0;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		if(marked[u]) topo.push_back(u);
		for(int v:g[u]) if(d[v]==-1) d[v]=d[u]+1,Q.push(v);
	}
	memset(f,-1,sizeof f);
	Q.push(n);
	f[n]=0;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int v:g[u]) if(f[v]==-1) f[v]=f[u]+1,Q.push(v);
	}
	int res=0,dmax=0;
	for(int i=0;i+1<(int)topo.size();++i){
		// dmax=max(dmax,d[topo[i]]);
		res=max(res,d[topo[i]]+f[topo[i+1]]+1);
	}
	cout<<min(res,d[n]);
}