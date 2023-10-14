/*
	it seemed easy, but still looking for elegant way.
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=30005;
int res,ra,rb,rc,best[N],dp[N];

void opt(int x,int d,int e,int f){
	if(res<=x) return;
	res=x;
	ra=d,rb=e,rc=f;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		for(int i=1;i<N;++i) dp[i]=99999;
		for(int i=1;i<N;++i)
			for(int j=1;j*j<=i;++j)
				if(i%j==0){
					int cost=abs(i-b)+abs(j-a);
					if(dp[i]>cost) dp[i]=cost,best[i]=j;
					cost=abs(i-b)+abs(i/j-a);
					if(j*j!=i&&dp[i]>cost) dp[i]=cost,best[i]=i/j;
				}
		res=99999;
		for(int i=1;i<N;++i)
			for(int j=1;j*j<=i;++j)
				if(i%j==0){
					int cost=abs(i-c)+dp[j]; 
					opt(cost,best[j],j,i);
					cost=abs(i-c)+dp[i/j];
					if(j*j!=i) opt(cost,best[i/j],i/j,i);
				}
		cout<<res<<'\n';
		cout<<ra<<' '<<rb<<' '<<rc<<'\n';
	}
}