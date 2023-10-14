#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll x;
	cin>>x;
	ll walk=0;
	for(ll i=1;i<=1000000;++i){
		walk+=i;
		if(walk>=x){
			cout<<i<<'\n';
			return 0;
		}
	}
}

