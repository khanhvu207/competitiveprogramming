#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1005;
const ll mod=1e9+7;
int n,a,b,c,d;
ll fact[1005],C[1005][1005],dp[1005][1005];

ll fpow(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>a>>b>>c>>d;
	fact[0]=1;
	for(ll i=1;i<N;++i) fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<N;++i) C[i][0]=1;
	for(int i=1;i<N;++i)
		for(int j=1;j<=i;++j)
			(C[i][j]=C[i-1][j-1]+C[i-1][j])%=mod;
	dp[a-1][0]=1;
	for(int i=a;i<=b;++i)
		for(int j=0;j<=n;++j){
			dp[i][j]=dp[i-1][j];
			for(int k=c;k<=d;++k){
				if(k*i>j) break; // O(N^2*log(N)) due to harmonic series tight bound O(logN)
				ll val=dp[i-1][j-k*i]*C[n-j+k*i][k*i]%mod*fact[k*i]%mod;
				(val*=fpow(fpow(fact[i],k),mod-2))%=mod;
				(val*=fpow(fact[k],mod-2))%=mod;
				(dp[i][j]+=val)%=mod;
			}
		}
	cout<<dp[b][n]<<'\n';
}

