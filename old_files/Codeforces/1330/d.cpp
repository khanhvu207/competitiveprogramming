#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll pow2[33];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		ll d,mod,res=1;
		cin>>d>>mod;
		for(ll x=1LL;x<=d;x*=2){
			ll t=min(d,x*2-1)-x+1;
			(res*=(t+1LL)%mod)%=mod;
		}
		--res;
		if(res<0) res+=mod;
		cout<<res<<'\n';
	}
}