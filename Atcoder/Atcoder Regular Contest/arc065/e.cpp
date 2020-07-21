#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
const int inf=numeric_limits<int>::max();
ll n,a,b,chebyshev,deg;
bool reachable[N];
map<ll,vector<ll>> c1,c2;
map<ll,set<pair<ll,ll>>> mpx,mpy;
vector<pair<ll,ll>> p;

void dfs(int v){
	reachable[v]=true;
	ll x=p[v].first;
	ll y=p[v].second;
	while(true){
		auto it=mpx[x-chebyshev].lower_bound(make_pair(y-chebyshev,-1));
		if(it==mpx[x-chebyshev].end()||it->first>y+chebyshev) break;
		int u=it->second;
		mpx[x-chebyshev].erase(it);
		if(!reachable[u]) dfs(u);
	}
	while(true){
		auto it=mpx[x+chebyshev].lower_bound(make_pair(y-chebyshev,-1));
		if(it==mpx[x+chebyshev].end()||it->first>y+chebyshev) break;
		int u=it->second;
		mpx[x+chebyshev].erase(it);
		if(!reachable[u]) dfs(u);
	}
	while(true){
		auto it=mpy[y-chebyshev].lower_bound(make_pair(x-chebyshev,-1));
		if(it==mpy[y-chebyshev].end()||it->first>x+chebyshev) break;
		int u=it->second;
		mpy[y-chebyshev].erase(it);
		if(!reachable[u]) dfs(u);
	}
	while(true){
		auto it=mpy[y+chebyshev].lower_bound(make_pair(x-chebyshev,-1));
		if(it==mpy[y+chebyshev].end()||it->first>x+chebyshev) break;
		int u=it->second;
		mpy[y+chebyshev].erase(it);
		if(!reachable[u]) dfs(u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>a>>b;
	--a,--b;
	for(int i=0;i<n;++i){
		ll x,y;
		cin>>x>>y;
		c1[x+y].push_back(x-y);
		c2[x-y].push_back(x+y);
		mpx[x+y].insert(make_pair(x-y,i));
		mpy[x-y].insert(make_pair(x+y,i));
		p.emplace_back(x+y,x-y);
	}
	chebyshev=max(abs(p[a].first-p[b].first),abs(p[a].second-p[b].second));
	dfs(a);
	for(auto it:c1)
		sort(c1[it.first].begin(),c1[it.first].end());
	for(auto it:c2)
		sort(c2[it.first].begin(),c2[it.first].end());
	for(int i=0;i<n;++i){
		if(!reachable[i]) continue;
		ll x=p[i].first;
		ll y=p[i].second;
		deg+=upper_bound(c1[x-chebyshev].begin(),c1[x-chebyshev].end(),y+chebyshev)-lower_bound(c1[x-chebyshev].begin(),c1[x-chebyshev].end(),y-chebyshev);
		deg+=upper_bound(c1[x+chebyshev].begin(),c1[x+chebyshev].end(),y+chebyshev)-lower_bound(c1[x+chebyshev].begin(),c1[x+chebyshev].end(),y-chebyshev);
		deg+=lower_bound(c2[y-chebyshev].begin(),c2[y-chebyshev].end(),x+chebyshev)-upper_bound(c2[y-chebyshev].begin(),c2[y-chebyshev].end(),x-chebyshev);
		deg+=lower_bound(c2[y+chebyshev].begin(),c2[y+chebyshev].end(),x+chebyshev)-upper_bound(c2[y+chebyshev].begin(),c2[y+chebyshev].end(),x-chebyshev);
	}
	cout<<deg/2ll<<'\n';
}

