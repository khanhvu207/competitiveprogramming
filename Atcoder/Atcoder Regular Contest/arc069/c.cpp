#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,m;
	cin>>n>>m;
	ll res=0;
	if(n*2<=m){
		res+=n;
		m-=2*n;
		res+=m/4LL;
	}
	else res=m/2LL;
	cout<<res<<'\n';
}

