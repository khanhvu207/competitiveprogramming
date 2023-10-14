#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<int,int> P;

const int N=2e5+5;
const ll INF=numeric_limits<ll>::max();
int n;
P bag[N];
multiset<int> r,b;

ll cost(){
	return 1LL*(*r.rbegin()-*r.begin())*(*b.rbegin()-*b.begin());
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		r.emplace(x);
		b.emplace(y);
		bag[i].first=x;
		bag[i].second=y;
	}
	sort(bag,bag+n);
	ll res=cost();
	for(int i=0;i<n;++i){
		//we will swap color of pair i, in the hope that it could minimize (Rmax-Rmin) by bringing Rmin closer to Rmax
		//the cost function will decrease, then increase back after the breakpoint
		int x=bag[i].first;
		int y=bag[i].second;
		r.erase(r.find(x));
		b.erase(b.find(y));
		r.insert(y);
		b.insert(x);
		res=min(res,cost());
	}
	cout<<res<<'\n';
}
