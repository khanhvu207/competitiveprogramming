// too much thinking for such a problem :/

#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

const int N=7777;
int n;
map<ll,ll> Map,cnt;
ll a[N],b[N],res;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	if(n<2){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i) cin>>b[i];
	for(int i=0;i<n;++i) Map[a[i]]++,cnt[a[i]]+=b[i];
	vector<ll> skill;
	for(auto it:Map)
		if(it.second>1) res+=cnt[it.first],skill.push_back(it.first);
	for(auto it:Map)
		if(it.second==1){
			bool ok=false;
			for(ll x:skill)
				if((it.first&x)==it.first){
					ok=true;
					break;
				}
			if(ok) res+=cnt[it.first];
		}
	cout<<res<<'\n';
}