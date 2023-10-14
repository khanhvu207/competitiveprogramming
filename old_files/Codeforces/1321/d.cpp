#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m;
vector<int> g[N],trace[N];

void bfs(int s){
	vector<int> d(n+1,-1);
	d[s]=0;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int v:g[u])
			if(d[v]==-1) d[v]=d[u]+1,Q.push(v),trace[v].push_back(u);
			else if(d[v]==d[u]+1) trace[v].push_back(u);
	}
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
		g[v].push_back(u);
	}
	int k;
	cin>>k;
	vector<int> path(k);
	for(int& x:path) cin>>x;
	bfs(path.back());
	int res1=0,res2=0;
	for(int i=0;i<(int)path.size()-1;++i){
		bool good=false;
		for(int u:trace[path[i]]) if(u==path[i+1]) good=true;
		if(!good) res1+=1;
		if(((int)trace[path[i]].size()==1&&!good)||(int)trace[path[i]].size()>=2) res2+=1;
	}
	cout<<res1<<' '<<res2;
}