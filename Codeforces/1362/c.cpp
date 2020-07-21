#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll calc(ll n){
	if(!n) return 0;
	return calc(n/2LL)+n;
}

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
		ll n;
		cin>>n;
		cout<<calc(n)<<'\n';
	}
}