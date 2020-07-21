/*
	For numbers which could be Bob choices, find optimal [l, r]
	UPD1: dumb mistakes were made...
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
int n,a[N],pref[N],suff[N],rmq[30][N],res[N],pos[100];

void init(int *A){
	for(int i=1;i<=n;++i) rmq[0][i]=A[i];
	for(int i=1;(1<<i)<=n;++i) 
		for(int j=1;j+(1<<i)-1<=n;++j)
			rmq[i][j]=max(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
}

int get(int L,int R){
	int k=log2(R-L+1);
	return max(rmq[k][L],rmq[k][R-(1<<k)+1]);
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pref[i]=pref[i-1]+a[i];
	}
	for(int i=n;~i;--i) suff[i]=suff[i+1]+a[i];
	init(suff);
	for(int i=1;i<=n;++i){
		int x=a[i]+30,l=1;
		for(int j=x+1;j<=60;++j) l=max(l,pos[j]+1);
		pos[x]=i;
		res[i]=get(l,i)-suff[i];
	}
	// for(int i=1;i<=n;++i) cerr<<res[i]<<' ';cerr<<'\n';
	init(pref);
	for(int i=0;i<=60;++i) pos[i]=n+1;
	for(int i=n;~i;--i){
		int x=a[i]+30,r=n;
		for(int j=x+1;j<=60;++j) r=min(r,pos[j]-1);
		pos[x]=i;
		res[i]+=get(i,r)-pref[i];
	}
	// for(int i=1;i<=n;++i) cerr<<res[i]<<' ';cerr<<'\n';
	cout<<*max_element(res+1,res+n+1);
}