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
	int n,m;
	cin>>n>>m;
	vector<ll> a(n),cnt(m,0);
	for(ll& x:a){
		cin>>x;
		++cnt[x%m];
		if(cnt[x%m]>1){
			cout<<0;
			return 0;
		}
	}
	ll res=1LL;
	for(int i=0;i<n-1;++i) for(int j=i+1;j<n;++j) (res*=abs(a[j]-a[i])%m)%=m;
	cout<<res;
}
