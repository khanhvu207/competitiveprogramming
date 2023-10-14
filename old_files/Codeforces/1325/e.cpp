#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int maxa=1e6+5;
int n,d[maxa],par[maxa];
vector<int> adj[maxa];

int bfs(int u){
	queue<int> Q;
	par[u]=-1;
	d[u]=0;
	Q.push(u);
	vector<int> save;
	int res=1e9;
	while(!Q.empty()){
		int u=Q.front();
		save.push_back(u);
		Q.pop();
		bool flag=1;
		for(int v:adj[u])
			if(d[v]==-1){
				d[v]=d[u]+1;
				par[v]=u;
				Q.push(v);
			}
			else{
				if(v==par[u]&&flag) flag=0;
				else res=min(res,d[u]+d[v]+1);
			}
	}
	for(int i:save) d[i]=-1;
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vector<int> p;
		for(int j=2;j*j<=x;++j)
			if(x%j==0){
				int cnt=0;
				while(x%j==0) ++cnt,x/=j;
				if(cnt&1) p.push_back(j);
			}
		if(x>1) p.push_back(x);
		if(p.empty()){
			cout<<1;
			return 0;
		}
		if((int)p.size()==1) adj[1].push_back(p[0]),adj[p[0]].push_back(1);
		else adj[p[0]].push_back(p[1]),adj[p[1]].push_back(p[0]);
	}
	int res=1e9;
	memset(d,-1,sizeof d);
	for(int i=1;i<=1000;++i) res=min(res,bfs(i));
	if(res==1e9) res=-1;
	cout<<res;
}