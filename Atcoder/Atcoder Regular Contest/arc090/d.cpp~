#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

typedef pair<int,int> P;

const int INF=numeric_limits<int>::max();
const int N=1e5+5;
int n,m,dist[N];
vector<P> adj[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int l,r,d;
		cin>>l>>r>>d;
		adj[l].emplace_back(r,d);
		adj[r].emplace_back(l,-d);
	}
	for(int i=1;i<=n;++i) dist[i]=INF;
	for(int i=1;i<=n;++i)
		if(dist[i]==INF){
			dist[i]=0;
			queue<int> Q;
			Q.push(i);
			while(!Q.empty()){
				int u=Q.front();
				Q.pop();
				for(P nxt:adj[u]){
					int v=nxt.first;
					int d=nxt.second;
					if(dist[v]==INF){
						dist[v]=dist[u]+d;
						Q.push(v);
					}
					else if(dist[v]!=dist[u]+d){
						return cout<<"No\n",0;
					}
				}
			}
		}
	cout<<"Yes\n";
}


