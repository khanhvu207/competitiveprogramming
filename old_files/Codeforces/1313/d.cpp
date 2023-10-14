#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=1e5+5;
int n,m,k,col[2*MX],colorMask[2*MX],dp[2*MX][266];
vector<pair<int,int>> ev;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=0;i<n;++i){
		int l,r;
		cin>>l>>r;
		ev.emplace_back(l,i+n);
		ev.emplace_back(r+1,i);
	}
	sort(ev.begin(),ev.end());
	for(int i=1;i<=2*n;++i){
		int id=ev[i-1].se;
		if(id>=n){
			id-=n;
			for(col[id]=0;col[id]<k;++col[id]) if((colorMask[i-1]>>col[id]&1)==0) break;
			colorMask[i]=colorMask[i-1]|(1<<col[id]);
		}
		else colorMask[i]=colorMask[i-1]^(1<<col[id]);
	}
	for(int i=1;i<=2*n;++i){
		int x=ev[i-1].fi,j=ev[i-1].se;
		int numChild=(i==2*n?0:ev[i].fi-x);
		int color=col[j%n];
		for(int mask=0;mask<(1<<k);++mask){
			int happy=(__builtin_popcount(mask&colorMask[i])%2?numChild:0);
			dp[i][mask]=happy+dp[i-1][mask];
			if(j<n) dp[i][mask]=max(dp[i][mask],happy+dp[i-1][mask^(1<<color)]);
		}
	}
	cout<<dp[2*n][0];
}