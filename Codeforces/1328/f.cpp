#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,k;
ll a[N],pref[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n);
	pref[0]=a[0];
	for(int i=1;i<n;++i) pref[i]=pref[i-1]+a[i];
	ll res=numeric_limits<ll>::max();
	for(int i=0;i<n;++i)
		if(i==0||a[i]!=a[i-1]){
			int r=upper_bound(a,a+n,a[i])-a;
			int sz=r-i;
			if(sz>=k){
				res=0;
				break;
			}
			ll cnt_l=i,cnt_r=n-r;
			ll cost_l=(a[i]-1LL)*cnt_l-(i>0?pref[i-1]:0);
			ll cost_r=pref[n-1]-pref[r-1]-(a[i]+1LL)*cnt_r;
			if(cnt_l>=k-sz) res=min(res,cost_l+k-sz);
			if(cnt_r>=k-sz) res=min(res,cost_r+k-sz);
			res=min(res,cost_l+cost_r+k-sz);
		}
	cout<<res;
}