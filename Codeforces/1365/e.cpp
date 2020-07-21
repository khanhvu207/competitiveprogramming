// can we only use 3 elements?

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=555;
int n;
ll a[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	ll res=0;
	for(int i=0;i<n;++i) cin>>a[i];
	if(n<=3){
		res=a[0]|a[1]|a[2];
		cout<<res;
		return 0;
	}
	for(int i=0;i<n-2;++i)	
		for(int j=i+1;j<n-1;++j)
			for(int k=j+1;k<n;++k)
				res=max(res,a[i]|a[j]|a[k]);
	// for(ll i=0;(1LL<<i)<=res;++i) cerr<<(res>>i&1);cerr<<'\n';
	cout<<res<<'\n';
}