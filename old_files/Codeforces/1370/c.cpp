#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		ll maxOdd=1;
		for(ll i=1;i*i<=n;++i)
			if(n%i==0){
				if(i>1&&(i&1)) maxOdd=max(maxOdd,i);
				if((n/i)>1&&((n/i)&1)) maxOdd=max(maxOdd,n/i);
			}
		if(n&1){
			if(n==1) cout<<"FastestFinger\n";
			else cout<<"Ashishgup\n";
		}
		else{
			if(n==2) cout<<"Ashishgup\n";
			else{
				if(maxOdd==1){
					cout<<"FastestFinger\n";
					continue;
				}
				n/=maxOdd;
				if(n>2) cout<<"Ashishgup\n";
				else{
					bool notPrime=false;
					for(ll i=2;i*i<=maxOdd;++i)
						if(maxOdd%i==0){
							notPrime=true;
							break;
						}
					cout<<(notPrime?"Ashishgup\n":"FastestFinger\n");
				}
			}
		}
	}
}