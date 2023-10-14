#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	map<ll,int> mp;
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		mp[x]++;
	}
	auto it=mp.end();
	ll f=-1,s=-1;
	ll res=0;
	do{
		it--;
		if(it->second>=2){
			if(it->second>=4){
				ll side=it->first;
				res=max(res,side*side);
			}
			if(f==-1) f=it->first;
			else if(s==-1) s=it->first;
		}
		if(~f&&~s)
			res=max(res,f*s);
	} while(it!=mp.begin());
	cout<<res<<'\n';
}

