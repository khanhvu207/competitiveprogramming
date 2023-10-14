// ...
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll M=1e9+7;
const ll inf=numeric_limits<ll>::max()/2LL;

ll fpow(ll a,ll p){
	ll res=1LL;
	while(p){
		if(p&1LL) res=res*a%M;
		res=min(res,inf);
		a=a*a%M;
		a=min(a,inf);
		p>>=1LL;
	}
	return res;
}

const int N=1e6+5;
ll n,p,a[N];

void solve(){
	cin>>n>>p;
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n,greater<ll>());
	ll res=fpow(p,a[0]);
	ll delta=1;
	for(int i=1;i<n;++i){
		if(delta<inf&&a[i]!=a[i-1]) delta*=fpow(p,a[i-1]-a[i]);
		if(delta==0){
			(res+=fpow(p,a[i]))%=M;
			delta++;
		}
		else{
			res=(res-fpow(p,a[i])+M)%M;
			delta--;
		}
	}
	cout<<res<<'\n';
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}