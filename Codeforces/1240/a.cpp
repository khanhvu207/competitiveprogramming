// binary search + greedy
// UPD1: overflow?

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n;
ll p[N],x,a,y,b,k;

bool check(int cnt){
	ll total=0;
	ll lcm=a*b/__gcd(a,b);
	ll both=cnt/lcm;
	ll justx=cnt/a-both,justy=cnt/b-both;
	// cerr<<cnt<<' '<<both<<' '<<justx<<' '<<justy<<'\n';
	ll i=0;
	while(i<both) total+=p[i++]*(x+y)/100LL;
	while(i<both+justy) total+=p[i++]*y/100LL;
	while(i<both+justy+justx) total+=p[i++]*x/100LL;
	// cerr<<cnt<<' '<<total<<'\n';
	return total>=k;
}

void solve(){
	cin>>n;
	for(int i=0;i<n;++i) cin>>p[i];
	cin>>x>>a>>y>>b>>k;
	if(x>y){
		swap(x,y);
		swap(a,b);
	}
	sort(p,p+n,greater<ll>());
	int l=1,r=n;
	while(l<=r){
		int m=(l+r)>>1;
		if(check(m)) r=m-1;
		else l=m+1;
	}
	if(l>n) l=-1;
	cout<<l<<'\n';
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