#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

array<array<ll,3>,4> Map={{
	{0,0,0},
	{1,2,3},
	{2,3,1},
	{3,1,2}
}};

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
		ll n;
		cin>>n;
		if(n<=3){
			cout<<n<<'\n';
			continue;
		}
		ll t=1LL,x,res=0LL;
		while(t*4LL<=n) t*=4LL;
		x=(n-t)/3LL;
		vector<ll> base4;
		while(x){
			base4.push_back(x%4LL);
			x>>=2LL;
		}
		res+=Map[1][(n-1)%3]*t;
		for(ll i=0;i<(int)base4.size();++i) res+=Map[base4[i]][(n-1)%3]<<(2LL*i);
		cout<<res<<'\n';
	}
}