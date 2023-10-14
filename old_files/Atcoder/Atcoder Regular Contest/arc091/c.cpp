#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,m;
	cin>>n>>m;
	if(n>m) swap(n,m);
	if(n==1){
		cout<<(m>1?m-2:1)<<'\n';
		return 0;
	}
	if(n==2) return cout<<"0\n",0;
	cout<<(n-2LL)*(m-2LL)<<'\n';
}

