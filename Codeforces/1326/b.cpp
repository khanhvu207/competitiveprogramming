#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n;
ll a[200005];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	cout<<a[0]<<' ';
	ll mx=a[0];
	for(int i=1;i<n;++i){
		cout<<mx+a[i]<<' ';
		mx=max(mx,mx+a[i]);
	}
}