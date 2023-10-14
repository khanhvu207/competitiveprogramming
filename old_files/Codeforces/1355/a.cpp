#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll calc(ll x){
	ll t=x,mn=10,mx=-1;
	while(t){
		mn=min(mn,t%10);
		mx=max(mx,t%10);
		t/=10;
	}
	return x+mn*mx;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	ll res;
	while(k--){
		res=n;
		ll m=calc(n);
		if(n==m) break;
		n=m;
	}
	cout<<res<<'\n';
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}