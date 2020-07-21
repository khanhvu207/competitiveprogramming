// binary search the answer

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll inf=numeric_limits<ll>::max();
const int N=1e5+5;
ll n,k,a[N],pref[N];

ll count(ll lo,ll hi){
	int L=lower_bound(a+1,a+n+1,lo)-a;
	int R=lower_bound(a+1,a+n+1,hi)-a;
	while(a[L]>lo) --L;
	ll cost=0LL;
	cost+=1LL*L*lo-pref[L];
	cost+=pref[n]-pref[R-1]-1LL*(n-R+1)*hi;
	return cost;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	ll res=inf;
	for(int i=1;i<=n;++i) pref[i]=pref[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=a[i],r=a[n];
		while(l<=r){
			int m=(l+r)>>1;
			if(count(a[i],m)>k) l=m+1;
			else r=m-1;
		}
		if(l<=a[n]&&count(a[i],l)<=k) res=min(res,l-a[i]);
		l=a[1],r=a[i];
		while(l<=r){
			int m=(l+r)>>1;
			if(count(m,a[i])>k) r=m-1;
			else l=m+1;
		}
		if(r>=a[1]&&count(r,a[i])<=k) res=min(res,a[i]-r);
	}
	cout<<res;
}