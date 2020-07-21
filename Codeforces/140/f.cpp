/*
	Sorting points ccw (Graham) + caseworks
	UPD: no, actually there's a much clever way.
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,k;
pair<int,int> p[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	if(k>=n){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<n;++i) cin>>p[i].fi>>p[i].se;
	sort(p,p+n);
	set<pair<int,int>> res;
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k-i;++j){
			int l=i,r=n-1-j;
			int cnt=i+j;
			int mx=p[l].fi+p[r].fi,my=p[l].se+p[r].se;
			while(l<=r){
				while(l<r&&make_pair(mx,my)<make_pair(p[l].fi+p[r].fi,p[l].se+p[r].se)) --r,++cnt;
				if(make_pair(mx,my)!=make_pair(p[l].fi+p[r].fi,p[l].se+p[r].se)) ++cnt;
				else --r;
				++l;
			}
			if(cnt<=k) res.insert(pair<int,int>(mx,my));
		}
	cout<<(int)res.size()<<'\n';
	for(auto i:res) cout<<fixed<<setprecision(5)<<i.fi*.5<<' '<<i.se*.5<<'\n';
}