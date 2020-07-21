/*
	just do binary search...
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll n,m;
vector<ll> a;

void solve(){
	a.clear();
	cin>>n>>m;
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		ll tmp=0LL;
		for(ll j=m-1;~j;--j) if(s[j]=='1') tmp+=1LL<<(m-1LL-j);
		a.push_back(tmp);
	}
	sort(a.begin(),a.end());
	ll l=0LL,r=(1LL<<m)-1LL;
	ll k=(1LL<<m)-n;
	while(l<=r){
		ll mid=(l+r)>>1LL;
		ll pos=lower_bound(a.begin(),a.end(),mid)-a.begin();
		if(mid-pos>(k-1)/2) r=mid-1;
		else l=mid+1;
	}
	for(ll i=m-1;~i;--i) cout<<((r>>i&1)?1:0);
	cout<<'\n';
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