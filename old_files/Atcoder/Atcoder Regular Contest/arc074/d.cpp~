#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(3*n),pf(3*n,0);
	for(ll& x:a) cin>>x;
	map<ll,ll> Map;
	int cnt=0;
	for(int i=0;i<3*n;++i)
		if(i<n){
			auto it=Map.find(a[i]);
			if(i) pf[i]=pf[i-1];
			if(it==Map.end()) Map.emplace(a[i],1);
			else it->second++;
			pf[i]+=a[i];
			cnt++;
		}
		else{
			auto it=Map.begin();
			pf[i]=pf[i-1];
			if(a[i]<=it->first) continue;
			if(cnt+1>n){
				pf[i]-=it->first;
				if(--it->second==0) Map.erase(it);
			}
			cnt++;
			it=Map.find(a[i]);
			if(it==Map.end()) Map.emplace(a[i],1);
			else it->second++;
			pf[i]+=a[i];
		}
	Map.clear();
	cnt=0;
	ll res=numeric_limits<ll>::min(),sf=0;
	for(int i=3*n-1;i>=n;--i)
		if(cnt<n){
			auto it=Map.find(a[i]);
			if(it==Map.end()) Map.emplace(a[i],1);
			else it->second++;
			sf+=a[i];
			cnt++;
			if(cnt==n) 
				res=max(res,pf[i-1]-sf);
		}
		else{
			auto it=Map.end();
			it--;
			if(a[i]>it->first) continue;
			if(cnt+1>n){
				sf-=it->first;
				if(--it->second==0) Map.erase(it);
			}
			cnt++;
			it=Map.find(a[i]);
			if(it==Map.end()) Map.emplace(a[i],1);
			else it->second++;
			sf+=a[i];
			res=max(res,pf[i-1]-sf);
		}
	cout<<res<<'\n';
}


