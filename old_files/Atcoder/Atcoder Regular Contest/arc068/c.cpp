#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n;
	cin>>n;
	ll res=2LL*(n/11LL);
	n%=11LL;
	if(n){
		if(n<=6) res++;
		else res+=2;
	}
	cout<<res<<'\n';
}

