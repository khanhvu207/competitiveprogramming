/*
	Observations:
		We could find the answer for each weapon i-th.
		Remove those unprofitable armours (b_i<b_j and cost_i>=cost_j, i<j)
		Ternary search to find optimal armour for each weapon i-th?

		UPD: No, actual the function is not a parabola

*/
 
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int N=2e5+5;
int n,m,p;
ll st[N*4],lazy[N*4];
pair<ll,ll> atk[N],def[N];
 
void update(int id,int tl,int tr,int L,int R,ll val){
	if(tl>R||tr<L) return;
	if(L<=tl&&tr<=R){
		lazy[id]+=val;
		return;
	}
	int tm=(tl+tr)>>1;
	update(id<<1,tl,tm,L,R,val);
	update(id<<1|1,tm+1,tr,L,R,val);
	st[id]=max(st[id<<1]+lazy[id<<1],st[id<<1|1]+lazy[id<<1|1]);
}
 
int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>p;
	for(int i=0;i<n;++i) cin>>atk[i].fi>>atk[i].se;
	for(int i=0;i<m;++i) cin>>def[i].fi>>def[i].se;
	sort(atk,atk+n);
	sort(def,def+m);
	for(int i=0;i<m;++i) update(1,0,m-1,i,i,-def[i].se);
	vector<tuple<int,int,int>> mons;
	for(int i=0;i<p;++i){
		ll x,y,z;
		cin>>x>>y>>z;
		mons.emplace_back(x,y,z);
	}
	sort(mons.begin(),mons.end());
	int j=-1;
	ll res=-1e18;
	for(int i=0;i<n;++i){
		while(j+1<p&&get<0>(mons[j+1])<atk[i].fi){
			++j;
			int vt=lower_bound(def,def+m,pair<ll,ll>(get<1>(mons[j])+1,0))-def;
			if(vt<m) update(1,0,m-1,vt,m-1,get<2>(mons[j]));
		}
		res=max(res,-atk[i].se+st[1]+lazy[1]);
	}
	cout<<res;
}