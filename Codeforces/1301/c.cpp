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
		ll n,m;
		cin>>n>>m;
		if(n-m<=m+1LL){
			cout<<n+n*(n-1LL)/2LL-(n-m)<<'\n';
			continue;
		}
		ll k=(n-m)/(m+1LL);
		ll res=(k*(k-1LL)/2LL+k)*(m+1LL);
		if((n-m)%(m+1LL)){
			ll r=(n-m)%(m+1LL);
			res-=(k*(k-1LL)/2LL+k)*r;
			++k;
			res+=(k*(k-1LL)/2LL+k)*r;
		}
		res=n+n*(n-1LL)/2LL-res;
		cout<<res<<'\n';
	}
}