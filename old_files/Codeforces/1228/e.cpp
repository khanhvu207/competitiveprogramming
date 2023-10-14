#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD = 1E9 + 7;
const int MX = 555;
ll n, k, f[MX];

ll fpow(ll a, ll p) {
    ll res = 1LL;
    while (p) {
        if (p & 1LL) res = res * a % MOD;
        a = a * a % MOD;
        p >>= 1LL;
    }
    return res;
}

ll nCk(ll N, ll K) {
    ll res = f[N];
    res = res * fpow(f[N - K], MOD - 2LL) % MOD;
    res = res * fpow(f[K], MOD - 2LL) % MOD;
    return res % MOD;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	f[0] = 1LL;
    for (int i = 1; i < MX; ++i) f[i] = f[i - 1] * i * 1LL % MOD;
	
	ll n,k;
	cin>>n>>k;
	ll res=0;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j){
			ll tmp=nCk(n,i)*nCk(n,j)%MOD;
			(tmp*=fpow(k-1,n*(i+j)-i*j))%=MOD;
			(tmp*=fpow(k,n*n-n*(i+j)+i*j))%=MOD;
			if((i+j)&1) res-=tmp;
			else res+=tmp;
			if(res<0) res+=MOD;
			res%=MOD;
		}
	cout<<res;
}