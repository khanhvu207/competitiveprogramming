#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	for(int _=t;_--;){
		ll a,b,n;cin>>a>>b>>n;
		ll res=0;
		while(a<=n&&b<=n){
			if(a<b) a+=b;
			else b+=a;
			res++;
		}
		cout<<res<<'\n';
	}
}