#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	ll k;
	cin>>n>>k;
	vector<pair<ll,ll>> p(n);
	for(int i=0;i<n;++i)
		cin>>p[i].first>>p[i].second;
	sort(p.begin(),p.end());
	ll sum=0;
	for(int i=0;i<n;++i){
		sum+=p[i].second;
		if(sum>=k){
			cout<<p[i].first<<'\n';
			return 0;
		}
	}
}


