#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// the resulting sequence after putting N cards looks like a valley, where 1 is the bottom number
// and the sequence that we have to construct is made of two decreasing sequences
// let dp[i][j] = # ways to construct the two chains, where the first i positions is determined, and the minimum is j
// a0         a_n-1
// 	a1      ...
//   a2    a_k+1
//    a3  a_k
//     ...
//      1

const ll mod=1e9+7;
const int N=2005;
int n,k;
ll dp[N][N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	dp[0][0]=1;
	for(int i=0;i<k;++i){
		ll sum=0;
		for(int j=1;j<=n;++j){
			(sum+=dp[i][j-1])%=mod;
			(dp[i+1][j]+=sum)%=mod;
			if(j>i&&j!=n) (dp[i+1][j]+=dp[i][j])%=mod;
		}
	}
	ll res=dp[k][n];
	for(int i=0;i<n-k-1;++i)
		res=res*2LL%mod;
	cout<<res<<'\n';
}

