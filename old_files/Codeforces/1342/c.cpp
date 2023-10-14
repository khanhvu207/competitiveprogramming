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
		ll a,b,q;
		cin>>a>>b>>q;
		ll prefix[a*b]={0};
		for(int i=1;i<a*b;++i){
			prefix[i]=prefix[i-1];
			if(i%a%b!=i%b%a) ++prefix[i];
		}
		while(q--){
			ll l,r;
			cin>>l>>r;
			--l;
			ll res=(r/(a*b))*prefix[a*b-1]+prefix[r%(a*b)];
			res-=(l/(a*b))*prefix[a*b-1]+prefix[l%(a*b)];
			cout<<res<<' ';
		}
		cout<<'\n';
	}
}