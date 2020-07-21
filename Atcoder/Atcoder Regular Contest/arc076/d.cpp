#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
int n,par[N],r[N];
vector<tuple<int,int,int>> p;
vector<tuple<ll,int,int>> e;

int getroot(int u){
	return u==par[u]?u:par[u]=getroot(par[u]);
}

bool joint(int u,int v){
	u=getroot(u);
	v=getroot(v);
	if(u==v) return false;
	if(r[u]>r[v]) r[u]+=r[v],par[v]=u;
	else r[v]+=r[u],par[u]=v;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		p.emplace_back(x,y,i);
	}
	sort(p.begin(),p.end());
	for(int i=1;i<n;++i){
		int dist=get<0>(p[i])-get<0>(p[i-1]);
		int u=get<2>(p[i]);
		int v=get<2>(p[i-1]);
		e.emplace_back(dist,u,v);
	}
	sort(p.begin(),p.end(),[](const tuple<int,int,int> &L,const tuple<int,int,int> &R){
				return get<1>(L)<get<1>(R);
			});
	for(int i=1;i<n;++i){
		int dist=get<1>(p[i])-get<1>(p[i-1]);
		int u=get<2>(p[i]);
		int v=get<2>(p[i-1]);
		e.emplace_back(dist,u,v);
	}
	for(int i=0;i<n;++i) 
		par[i]=i,r[i]=1;
	sort(e.begin(),e.end());
	ll res=0;
	for(auto it:e){
		ll d,u,v;
		tie(d,u,v)=it;
		//cerr<<d<<' '<<u<<' '<<v<<'\n';
		if(joint(u,v)) 
			res+=d;
	}
	cout<<res<<'\n';
}


