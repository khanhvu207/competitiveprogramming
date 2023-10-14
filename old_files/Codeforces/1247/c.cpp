#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll n,p;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>p;
	for(int i=1;i<=34;++i){
		ll y=n-i*p;
		ll cnt=__builtin_popcountll(y);
		if(y>=i&&i>=cnt){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}