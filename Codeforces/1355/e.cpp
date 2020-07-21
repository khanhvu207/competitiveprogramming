/*
	... overflow again >.<
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
ll n,a,r,m,h[N],prefix[N];

ll solve(ll p){
	int pos=lower_bound(h+1,h+n+1,p)-h;
	if(h[pos]>p) --pos;
	ll add=pos*p-prefix[pos];
	if(h[pos]!=p) ++pos;
	ll rmv=prefix[n]-prefix[pos-1]-p*(n-pos+1LL);
	ll x=min(add,rmv),res=0LL;
	if(a+r<m) res+=x*(a+r);
	else res+=x*m;
	add-=x;
	rmv-=x;
	if(add>0) res+=add*a;
	if(rmv>0) res+=rmv*r;
	// cerr<<p<<' '<<res<<'\n';
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>a>>r>>m;
	for(int i=1;i<=n;++i) cin>>h[i];
	sort(h+1,h+n+1);
	for(int i=1;i<=n;++i) prefix[i]=prefix[i-1]+h[i];
	ll l=1,r=1e9;
	while(l+2<=r){
		ll m1=l+(r-l)/3;
		ll m2=r-(r-l)/3;
		if(solve(m1)<solve(m2)) r=m2-1;
		else l=m1+1;
	}
	ll res=numeric_limits<ll>::max();
	for(ll i=l;i<=r;++i) res=min(res,solve(i));
	cout<<res;
	// cout<<solve(92432544);
}

//92432544