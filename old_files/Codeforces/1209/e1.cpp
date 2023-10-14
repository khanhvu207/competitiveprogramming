#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

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
		int n,m;
		cin>>n>>m;
		int a[n][m];
		for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>a[i][j];
		int dp[m][1<<4]={0};
		for(int i=0;i<m;++i){
			if(i==0){
				for(int maskx=0;maskx<(1<<n);++maskx){
					for(int j=0;j<n;++j){
						int total=0;
						for(int k=0;k<n;++k) if(maskx>>k&1) total+=a[(k+j)%n][i];
						dp[i][maskx]=max(dp[i][maskx],total);
					}
				}
			}
			else{
				for(int masky=0;masky<(1<<n);++masky)
					for(int maskx=0;maskx<(1<<n);++maskx){
						bool good=true;
						for(int j=0;j<n;++j) if((masky>>j&1)==1&&(maskx>>j&1)==0) good=false;
						if(!good) continue; 
						for(int j=0;j<n;++j){
							int total=0;
							int tmask=masky^maskx;
							for(int k=0;k<n;++k) if(tmask>>k&1) total+=a[(k+j)%n][i];
							dp[i][maskx]=max(dp[i][maskx],dp[i-1][masky]+total);
						}
					}
			}
		}
		cout<<dp[m-1][(1<<n)-1]<<'\n';
	}
}