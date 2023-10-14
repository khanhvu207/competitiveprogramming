// (2^m-1)^n

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll M=1e9+7;

ll fpow(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1) res=res*a%M;
		a=a*a%M;
		p>>=1;
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
	ll n,m;
	cin>>n>>m;
	ll res=(fpow(2,m)-1LL+M)%M;
	res=fpow(res,n);
	cout<<res;
}