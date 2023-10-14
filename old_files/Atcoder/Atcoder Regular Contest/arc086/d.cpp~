#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	int lo=1e6+1,p_lo,hi=-1e6-1,p_hi;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		a[i]=x;
		if(x<lo){
			lo=x;
			p_lo=i;
		}
		if(x>hi){
			hi=x;
			p_hi=i;
		}
	}
	if(lo<0) lo=-lo;
	if(hi<0) hi=-hi;
	vector<pair<int,int>> res;
	if(lo<hi){
		for(int i=0;i<n;++i)
			if(i!=p_hi)
				res.emplace_back(p_hi+1,i+1);
		for(int i=2;i<=n;++i)
			res.emplace_back(i-1,i);
	}
	else{
		for(int i=0;i<n;++i)
			if(i!=p_lo)
				res.emplace_back(p_lo+1,i+1);
		for(int i=n-1;i>=1;--i)
			res.emplace_back(i+1,i);
	}
	cout<<int(res.size())<<'\n';
	for(auto it:res)
		cout<<it.first<<' '<<it.second<<'\n';
}


