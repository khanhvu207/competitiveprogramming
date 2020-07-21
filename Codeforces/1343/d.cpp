#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,k,a[N],cnt[2*N],b[2*N];

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
		cin>>n>>k;
		for(int i=0;i<=2*k;++i) cnt[i]=b[i]=0;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i*2<=n;++i){
			int l=min(1+a[i],1+a[n-i+1]);
			int r=max(k+a[i],k+a[n-i+1]);
			++b[l],--b[r+1];
			++cnt[a[i]+a[n-i+1]];
		}
		for(int i=1;i<=2*k;++i) b[i]+=b[i-1];
		int res=1e9;
		for(int i=2;i<=2*k;++i){ 
			int cost=b[i]-cnt[i]+2*(n/2-b[i]);
			res=min(res,cost);
		}
		cout<<res<<'\n';
	}
}