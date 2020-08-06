#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<int,int> P;
const int N=305;
const ll mod=1e9+7;
int n,m;
ll dp[N][N][N];
vector<P> r[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int L,R,x;
		cin>>L>>R>>x;
		r[R].emplace_back(L,x);
	}
	dp[0][0][0]=1;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			for(int k=0;k<=n;++k){
				int t=max({i,j,k});
				for(P p:r[t]){
					int l=p.first;
					int x=p.second;
					if((l<=i)+(l<=j)+(l<=k)!=x) 
						dp[i][j][k]=0;
				}
				if(t==n||!dp[i][j][k]) continue;
				(dp[t+1][j][k]+=dp[i][j][k])%=mod;
				(dp[i][t+1][k]+=dp[i][j][k])%=mod;
				(dp[i][j][t+1]+=dp[i][j][k])%=mod;
			}
	ll res=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			(res+=dp[n][i][j])%=mod;
			(res+=dp[i][n][j])%=mod;
			(res+=dp[i][j][n])%=mod;
		}
	cout<<res<<'\n';
}


