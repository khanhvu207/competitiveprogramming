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
		ll n,l,r;
		cin>>n>>l>>r;
		if(l==n*(n-1)+1){
			cout<<1<<'\n';
			continue;
		}
		for(ll i=1,sum=0;i<n;++i){
			sum+=(n-i)*2LL;
			if(sum<l) continue;
			sum-=(n-i)*2LL;
			for(ll j=l,k=i;j<=r;++j){
				if(j>sum+(n-k)*2LL) sum+=(n-k)*2LL,++k;
				ll x=((j-sum)&1)?k:((j-sum)/2LL+k);
				if(j==n*(n-1)+1) x=1;
				cout<<x<<' ';
			}
			cout<<'\n';
			break;
		}
	}
}