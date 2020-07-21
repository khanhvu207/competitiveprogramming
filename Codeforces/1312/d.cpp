/*
	Let choose n-2 unique numbers
	then, choose numbers of the set to be on the left hill
	then, from the left hill, choose a number to be duplicated

	>.<
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=998244353;
const int N=2e5+5;
int n,m;
ll f[N],invf[N];

ll C(int n,int k){
	return f[n]%MOD*invf[k]%MOD*invf[n-k]%MOD;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	f[0]=1LL;
	for(ll i=1;i<=2e5;++i) f[i]=(f[i-1]*i)%MOD;
	invf[200000]=532999597LL;
	for(ll i=2e5-1;i>=0;--i) invf[i]=(invf[i+1]*(i+1LL))%MOD;
	cin>>n>>m;
	ll res=0LL;
	for(ll i=1;i<=n-2;++i){
		ll total=C(m,n-1)%MOD;
		(total*=C(n-2,i)%MOD)%=MOD;
		(total*=i%MOD)%=MOD;
		(res+=total%MOD)%=MOD;
	}
	cout<<res;
}