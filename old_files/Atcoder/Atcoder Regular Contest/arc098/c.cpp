#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> pf(n),sf(n);
	for(int i=0;i<n;++i)
		pf[i]=(s[i]=='W')+(i?pf[i-1]:0);
	for(int i=n-1;~i;--i)
		sf[i]=(s[i]=='E')+(i!=n-1?sf[i+1]:0);
	int res=n;
	for(int i=0;i<n;++i){
		int cost=0;
		if(i) cost+=pf[i-1];
		if(i!=n-1) cost+=sf[i+1];
		res=min(res,cost);
	}
	cout<<res<<'\n';
}

