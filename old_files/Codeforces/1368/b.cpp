#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string res="codeforces";
	ll k;cin>>k;
	vector<ll> e(10,1);
	ll total=1;
	while(total<k){
		for(ll& x:e){
			total/=x;
			x++;
			total*=x;
			if(total>=k) break;
		}
	}
	string ans="";
	for(int i=0;i<10;++i)
		for(int j=0;j<e[i];++j)
			ans+=res[i];
	cout<<ans<<'\n';
}