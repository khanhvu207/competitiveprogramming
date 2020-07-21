/*
	triangle inequality: x+y>z
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e6+5;
ll a,b,c,d,cnt[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>a>>b>>c>>d;
	for(ll x=a;x<=b;++x) ++cnt[x+b],--cnt[x+c+1];
	for(ll i=1;i<=1000000;++i) cnt[i]+=cnt[i-1];
	for(ll i=1;i<=1000000;++i) cnt[i]+=cnt[i-1];
	ll res=0;
	for(ll z=c;z<=d;++z){
		if(z+1>b+c) continue;
		ll l=max(z+1,a+b);
		res+=cnt[b+c]-cnt[l-1];
	}
	cout<<res;
}