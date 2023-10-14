/*
	L[i][j] is the answer if we walk from the left to (i,j)
	D[i][j] is the answer if we walk from the top to (i,j)
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2005;
const ll MOD=1e9+7;
int n,m,rh[N][N],rv[N][N];
ll L[N][N],D[N][N];
char g[N][N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			cin>>g[i][j];
			rh[i][j]=rh[i][j-1]+(g[i][j]=='R');
			rv[i][j]=rv[i-1][j]+(g[i][j]=='R');
		}
	L[1][1]=D[1][1]=1LL;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(i==1&&j==1) continue;
			(L[i][j]+=L[i][j-1])%=MOD;
			if(i==1&&m-rh[i][m]+1<=j) L[i][j]=0;
			if(rv[n][j]-rv[i][j]<n-i){
				(D[i+1][j]+=L[i][j])%=MOD;
				(D[n-(rv[n][j]-rv[i][j])+1][j]+=-L[i][j]+MOD)%=MOD;
			}
			(D[i][j]+=D[i-1][j])%=MOD;
			if(j==1&&n-rv[n][j]+1<=i) D[i][j]=0;
			if(rh[i][m]-rh[i][j]<m-j){
				(L[i][j+1]+=D[i][j])%=MOD;
				(L[i][m-(rh[i][m]-rh[i][j])+1]+=-D[i][j]+MOD)%=MOD;
			}
		}
	// for(int i=1;i<=n;++i){
	// 	for(int j=1;j<=m;++j) cerr<<L[i][j]<<' ';
	// 	cerr<<'\n';
	// }
	ll res=(L[n][m]+D[n][m])%MOD;
	cout<<res;
}