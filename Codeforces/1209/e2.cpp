#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=15;
const int M=2005;
int n,m,a[N][M],mx[M],dp[N][1<<12],total[N][1<<12];

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
		cin>>n>>m;
		for(int i=0;i<m;++i) mx[i]=0;
		for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>a[i][j];
		for(int i=0;i<m;++i) for(int j=0;j<n;++j) mx[i]=max(mx[i],a[j][i]);
		vector<int> id(m);
		iota(id.begin(),id.end(),0);
		sort(id.begin(),id.end(),[&](int l,int r){
			return mx[l]>mx[r];
		});
		for(int i=0;i<min(n,m);++i) 
			for(int j=0;j<(1<<n);++j){
				dp[i][j]=0;
				total[i][j]=0;
				for(int r=0;r<n;++r){
					int sum=0;
					for(int k=0;k<n;++k) if(j>>k&1) sum+=a[(k+r)%n][id[i]];
					total[i][j]=max(total[i][j],sum);
				}
			}
		for(int i=0;i<min(n,m);++i){
			if(i==0){
				for(int maskx=0;maskx<(1<<n);++maskx) dp[i][maskx]=total[i][maskx];
			}
			else{
				for(int maskx=0;maskx<(1<<n);++maskx){
					for(int masky=maskx;;masky=maskx&(masky-1)){
						dp[i][maskx]=max(dp[i][maskx],dp[i-1][masky]+total[i][maskx^masky]);
						if(masky==0) break;
					}
				}
			}
		}
		cout<<dp[min(n,m)-1][(1<<n)-1]<<'\n';
	}
}