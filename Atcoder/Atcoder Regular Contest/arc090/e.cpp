#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+5;
const ll MD=1e9+7;
const ll INF=1e16;
int n,m,s,t;
ll d[N],d2[N],f[N],g[N];
bool vst[N];
vector<int> bw[N];
vector<pair<int,ll>> adj[N];
vector<pair<pair<int,int>,ll>> edges;

ll traverse(int u){
	if(f[u]!=-1) return f[u];
	f[u]=0;
	for(int v:bw[u])
		(f[u]+=traverse(v))%=MD;
	return f[u];
}

ll traverse2(int u){
	if(g[u]!=-1) return g[u];
	g[u]=0;
	for(int v:bw[u])
		(g[u]+=traverse2(v))%=MD;
	return g[u];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;++i){
		int u,v;
		ll c;
		cin>>u>>v>>c;
		edges.emplace_back(make_pair(u,v),c);
		adj[u].emplace_back(v,c);
		adj[v].emplace_back(u,c);
	}
	for(int i=1;i<=n;++i) d[i]=INF;
	d[s]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> Q;
	Q.push(make_pair(d[s],s));
	while(!Q.empty()){
		int u=Q.top().second;
		ll dist=Q.top().first;
		Q.pop();
		if(dist>d[u]) continue;
		vst[u]=true;
		for(auto nxt:adj[u]){
			if(!vst[nxt.first]&&dist+nxt.second<d[nxt.first]){
				d[nxt.first]=dist+nxt.second;
				Q.push(make_pair(d[nxt.first],nxt.first));
				bw[nxt.first].clear();
				bw[nxt.first].push_back(u);
			}
			else if(dist+nxt.second==d[nxt.first]){
				bw[nxt.first].push_back(u);
			}
		}
	}
	memset(f,-1,sizeof f);
	f[s]=1;
	traverse(t);
	memset(vst,false,sizeof vst);
	for(int i=1;i<=n;++i) d2[i]=INF;
	d2[t]=0;
	Q.push(make_pair(d2[t],t));
	while(!Q.empty()){
		int u=Q.top().second;
		ll dist=Q.top().first;
		Q.pop();
		if(dist>d2[u]) continue;
		vst[u]=true;
		for(auto nxt:adj[u]){
			if(!vst[nxt.first]&&dist+nxt.second<d2[nxt.first]){
				d2[nxt.first]=dist+nxt.second;
				Q.push(make_pair(d2[nxt.first],nxt.first));
				bw[nxt.first].clear();
				bw[nxt.first].push_back(u);
			}
			else if(dist+nxt.second==d2[nxt.first]){
				bw[nxt.first].push_back(u);
			}
		}
	}
	memset(g,-1,sizeof g);
	g[t]=1;
	traverse2(s);
	ll total=f[t]*f[t]%MD;
	ll path=d[t];
	for(int i=1;i<=n;++i)
		if(d[i]==d2[i]&&d[i]+d2[i]==path){ // Taka and Aoki meet at node i
			ll ways=f[i]*f[i]%MD;
			ways=ways*g[i]%MD*g[i]%MD;
			total=(total-ways+MD)%MD;
		}
	for(auto e:edges){
		int u=e.first.first;
		int v=e.first.second;
		ll len=e.second;
		if(d[u]>d[v]) swap(u,v);
		if(d[u]*2<path&&d2[v]*2<path&&d[u]+d2[v]+len==path){ // Taka and Aoki meet on edge that links u and v
			ll ways=f[u]*f[u]%MD;
			ways=ways*g[v]%MD*g[v]%MD;
			total=(total-ways+MD)%MD;
		}
	}
	cout<<total<<'\n';
}


