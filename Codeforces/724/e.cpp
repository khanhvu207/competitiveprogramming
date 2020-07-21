/*
	Iterate from right to left, and maintain a heap?
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=10005;
int n;
ll c,p[N],s[N],res[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>c;
	for(int i=0;i<n;++i) cin>>p[i];
	for(int i=0;i<n;++i) cin>>s[i];
	set<pair<ll,int>> S;
	for(int i=n-1;~i;--i){
		vector<pair<int,int>> tmp;
		for(auto j:S){
			int k=min(c,min(p[i],j.fi));
			p[i]-=k;
			p[j.se]+=k;
			if(j.fi-k>0) tmp.push_back({j.fi-k,j.se}); 
		}
		S.clear();
		for(auto j:tmp) S.insert(j);
		if(p[i]>=s[i]) continue;
		S.insert({s[i]-p[i],i});
	}
	ll res=0LL;
	for(int i=0;i<n;++i) res+=min(p[i],s[i]);
	cout<<res<<'\n';
}