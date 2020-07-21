#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const ll MX=1E16+1000;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll k;
	cin>>k;
	ll n=50;
	cout<<n<<'\n';
	vector<ll> res(n);
	for(int i=0;i<n;++i) res[i]=i+(k/n);
	for(int i=0;i<k%n;++i)
		for(int j=0;j<n;++j)
			if(j==i) res[j]+=n;
			else res[j]--;
	for(ll x:res) cout<<x<<' ';
	cout<<endl;
}


