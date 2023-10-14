#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll x,y;
	cin>>x>>y;
	int res=0;
	while(x<=y){
		res++;
		x<<=1LL;
	}
	cout<<res<<'\n';
}

