#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<vector<int>> pf(20,vector<int>(n));
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(i){
			for(int j=0;j<20;++j) 
				pf[j][i]=pf[j][i-1];
		}
		for(int j=0;j<20;++j)
			if(x>>j&1) pf[j][i]++;
	}
	ll res=0;
	for(int i=0;i<n;++i){
		int l=0,r=i;
		while(l<=r){
			int m=(l+r)>>1;
			bool ok=true;
			for(int j=0;j<20;++j)
				if(pf[j][i]-(m?pf[j][m-1]:0)>1) ok=false;
			if(!ok) l=m+1;
			else r=m-1;
		}
		res+=i-l+1;
	}
	cout<<res<<'\n';
}


