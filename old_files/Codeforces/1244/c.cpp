// x=(p-yd)/w
// brute-force for y=[0..w-1]

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
	ll n,p,d,w;
	cin>>n>>p>>w>>d;
	for(ll y=0;y<w;++y){
		ll k=p%w-y*d%w;
		if(k!=0||p-y*d<0) continue;
		ll x=(p-y*d)/w;
		ll z=n-y-x;
		if(z<0) continue;
		cout<<x<<' '<<y<<' '<<z;
		return 0;
	}
	cout<<-1;
}