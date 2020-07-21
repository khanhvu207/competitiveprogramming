/*
	On an optimal path, there exists at least an unchanged node.
	So we just brute-force for that middle-man node, and do dp back and forward.
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll inf=numeric_limits<ll>::max();
int t,n,m;
ll a[105][105],dp[105][105];

ll solve(int x,int y){
	dp[x][y]=0;
	for(int i=x;i>=1;--i) 
		for(int j=y;j>=1;--j){
			if(i==x&&j==y) continue;
			ll f=a[x][y]-abs(x-i)-abs(y-j);
			dp[i][j]=inf;
			if(f>a[i][j]) continue;
			if(i+1<=x&&dp[i+1][j]!=inf) dp[i][j]=min(dp[i][j],dp[i+1][j]+a[i][j]-f);
			if(j+1<=y&&dp[i][j+1]!=inf) dp[i][j]=min(dp[i][j],dp[i][j+1]+a[i][j]-f);
		}
	if(dp[1][1]==inf) return inf;
	for(int i=x;i<=n;++i) 
		for(int j=y;j<=m;++j){
			if(i==x&&j==y) continue;
			ll f=a[x][y]+abs(x-i)+abs(y-j);
			dp[i][j]=inf;
			if(f>a[i][j]||(x==i&&y==j)) continue;
			if(i-1>=x&&dp[i-1][j]!=inf) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]-f); 
			if(j-1>=y&&dp[i][j-1]!=inf) dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]-f);
		}
	if(dp[n][m]==inf) return inf;
	return dp[1][1]+dp[n][m];
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll res=numeric_limits<ll>::max();
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>a[i][j];
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) res=min(res,solve(i,j));
		cout<<res<<'\n';
	}
}