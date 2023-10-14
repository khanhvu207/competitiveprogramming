// just do dp?
// upd: some silly mistakes >.<

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,h,l,r,a[2005],f[2005][2005];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>h>>l>>r;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i) for(int j=0;j<=h;++j) f[i][j]=-1e9;
	f[0][a[0]]=(l<=a[0]&&a[0]<=r);
	f[0][a[0]-1]=(l<=a[0]-1)&&(a[0]-1<=r);
	int res=max(f[0][a[0]],f[0][a[0]-1]);
	for(int i=1;i<n;++i) 
		for(int j=0;j<h;++j){
			int t=(j+a[i])%h;
			f[i][t]=max(f[i][t],f[i-1][j]+(l<=t&&t<=r));
			res=max(res,f[i][t]);
			t=(j+a[i]-1)%h;
			f[i][t]=max(f[i][t],f[i-1][j]+(l<=t&&t<=r));
			res=max(res,f[i][t]);
		}
	cout<<res;
}