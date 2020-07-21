/*
	Consider parity of cells.
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=998244353;

ll fpow(ll a,ll p){
	ll res=1LL;
	while(p){
		if(p&1LL) (res*=a)%=MOD;
		a=(a*a)%MOD;
		p>>=1LL;
	}
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n,m,L,R;
	cin>>n>>m>>L>>R;
	ll k=n*m,num_color=R-L+1;
	ll res=fpow(num_color,k);
	if(k&1) cout<<res;
	else{
		ll odd_color=num_color/2+(num_color&1),even_color=num_color-odd_color;
		ll cnt=fpow(num_color,k)-fpow((even_color-odd_color+MOD)%MOD,k)+MOD;
		cnt%=MOD;
		(cnt*=fpow(2,MOD-2))%=MOD;
		res=(res-cnt+MOD)%MOD;
		cout<<res;
	}
}