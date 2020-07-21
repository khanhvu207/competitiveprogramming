#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	auto st=clock();
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	vector<ll> a(n);
	for(ll& x:a) cin>>x;
	shuffle(a.begin(),a.end(),rng);
	ll best=1e18;
	set<ll> s;
	for(int i=0;i<n;++i){
		if(clock()>st+2.0*CLOCKS_PER_SEC) break;
		for(ll j=max(1LL,a[i]-1LL);j<=a[i]+1;++j){
			vector<ll> pr;
			ll x=j;
			for(ll p=2;p*p<=x;++p){
				if(x%p) continue;
				while(x%p==0) x/=p;
				pr.push_back(p);
			}
			if(x>1) pr.push_back(x);
			for(ll y:pr){
				if(s.count(y)) continue;
				s.insert(y);
				ll cost=0;
				for(ll x:a){
					if(x<y) cost+=y-x;
					else{
						x%=y;
						cost+=min(x,y-x);
					}
					if(cost>best) break;
				}
				best=min(best,cost);
			}
		}
	}
	cout<<best;
}