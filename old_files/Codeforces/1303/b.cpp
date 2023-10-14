#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		ll n,g,b;
		cin>>n>>g>>b;
		ll r=(n+1)/2;
		ll res=(r/g)*(g+b);
		if(r%g) res+=r%g;
		else res-=b;
		res=max(res,n);
		cout<<res<<'\n';		
	}
}