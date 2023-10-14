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
		int n;
		cin>>n;
		vector<ll> a(n),b(n);
		for(int i=0;i<n;++i) cin>>a[i]>>b[i];
		ll total=0LL,res=1e18;
		for(int i=0;i<n;++i) total+=max(0LL,a[i]-b[(i-1+n)%n]);
		for(int i=0;i<n;++i) res=min(res,total-max(0LL,a[i]-b[(i-1+n)%n])+a[i]);
		cout<<res<<'\n';
	}
}