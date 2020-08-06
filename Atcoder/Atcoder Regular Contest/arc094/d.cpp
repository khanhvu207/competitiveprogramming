#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		ll res;
		if(a==b) res=2*a-2;
		else{
			ll mid=sqrt(a*b);
			if(mid*mid==a*b) mid--;
			if(mid*(mid+1)>=a*b) res=2*mid-2;
			else res=2*mid-1;
		}
		cout<<res<<'\n';
	}
}


