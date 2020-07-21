#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=555;
ll n,k;
ll a[MX],b[MX];
bool dp[MX][MX];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i]>>b[i];
	dp[0][0]=true;
	for(int i=1;i<=n;++i){
		for(int j=0;j<k;++j){
			dp[i][j]=dp[i-1][(j-a[i]%k+k)%k];
			for(int l=0;l<=min(k-1LL,a[i]);++l) if((a[i]-l)%k+b[i]>=k) dp[i][j]|=dp[i-1][(j-l+k)%k];
		}
	}
	ll sum=accumulate(a+1,a+n+1,0LL)+accumulate(b+1,b+n+1,0LL);
	ll res=0LL;
	for(int i=0;i<k;++i) if(dp[n][i]) res=max(res,(sum-i)/k);
	cout<<res; 
}