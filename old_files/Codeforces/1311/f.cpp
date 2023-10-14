// Compress velocities and update on BIT + caseworks

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n;
pair<ll,ll> p[N],BITpre[N],BITsuf[N];

void upd1(int x,ll a,ll b){
	for(;x<N;x+=x&(-x))
		BITpre[x].fi+=a,BITpre[x].se+=b;
}

pair<ll,ll> get1(int x){
	pair<ll,ll> ans={0,0};
	for(;x>=1;x-=x&(-x))
		ans.fi+=BITpre[x].fi,ans.se+=BITpre[x].se;
	return ans;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i) cin>>p[i].fi;
	for(int i=0;i<n;++i) cin>>p[i].se;
	sort(p,p+n);
	vector<ll> c;
	for(int i=0;i<n;++i) c.push_back(p[i].se);
	sort(c.begin(),c.end());
	ll res=0LL;
	for(int i=0;i<n;++i){
		int idx=lower_bound(c.begin(),c.end(),p[i].se)-c.begin()+1;
		pair<ll,ll> x=get1(idx);
		res+=x.se*p[i].fi-x.fi;
		upd1(idx,p[i].fi,1);
	}
	cout<<res<<'\n';
}