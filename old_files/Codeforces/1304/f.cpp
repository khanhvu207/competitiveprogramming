/*
	dp[i][j] = the maximal answer if we put the camera at cell (i, j)
	for dp transition, we maintain a window + lazy IT to update the next row.
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=55;
const int M=2e4+5;
int n,m,k,a[N][M],b[N][M],dp[N][M],st[4*M],lazy[4*M];

int count(int xl,int yl,int xr,int yr){
	xl=max(xl,1);yl=max(yl,1);xr=min(xr,n);yr=min(yr,m);
	return b[xr][yr]-b[xl-1][yr]-b[xr][yl-1]+b[xl-1][yl-1];
}

void update(int id,int tl,int tr,int L,int R,int val){
	if(R<tl||L>tr) return;
	if(L<=tl&&tr<=R){
		lazy[id]+=val;
		return;
	}
	int tm=(tl+tr)>>1;
	update(id<<1,tl,tm,L,R,val);
	update(id<<1|1,tm+1,tr,L,R,val);
	st[id]=max(st[id<<1]+lazy[id<<1],st[id<<1|1]+lazy[id<<1|1]);
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>a[i][j];
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
	for(int i=1;i<=m-k+1;++i) dp[1][i]=count(1,i,2,i+k-1);
	for(int i=2;i<=n;++i){
		for(int j=1;j<=4*m;++j) st[j]=lazy[j]=0; 
		for(int j=1;j<=m;++j) update(1,1,m,j,j,dp[i-1][j]);
		for(int j=1;j<=k;++j) update(1,1,m,max(1,j-k+1),j,-a[i][j]);
		dp[i][1]=st[1]+lazy[1]+count(i,1,i+1,k);
		for(int j=2;j<=m-k+1;++j){
			update(1,1,m,max(1,j-k),j-1,a[i][j-1]);
			update(1,1,m,j,j+k-1,-a[i][j+k-1]);
			dp[i][j]=st[1]+lazy[1]+count(i,j,i+1,j+k-1);
		}
	}
	cout<<*max_element(dp[n]+1,dp[n]+m+1);
}