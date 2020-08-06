#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF=1e5;
const int N=100;
int n,x,y,a[N],b[N],c[N];
int dp[44][444][444];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>x>>y;
	for(int k=0;k<44;++k)
		for(int i=0;i<444;++i)
			for(int j=0;j<444;++j) 
				dp[k][i][j]=(i==0&&j==0)?0:INF;
	for(int i=1;i<=n;++i)
		cin>>a[i]>>b[i]>>c[i];
	for(int k=1;k<=n;++k)
		for(int i=0;i<444;++i)
			for(int j=0;j<444;++j){
				dp[k][i][j]=min(dp[k][i][j],dp[k-1][i][j]);
				if(i-a[k]>=0&&j-b[k]>=0)
					dp[k][i][j]=min(dp[k][i][j],dp[k-1][i-a[k]][j-b[k]]+c[k]);
			}
	int res=INF;
	for(int k=1;k<=n;++k)
		for(int i=1;max(x*i,y*i)<444;++i)
			res=min(res,dp[k][x*i][y*i]);
	if(res>=INF) res=-1;
	cout<<res<<'\n';
}


