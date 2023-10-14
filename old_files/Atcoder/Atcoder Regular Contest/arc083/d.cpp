#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<vector<ll>> a(n,vector<ll>(n));
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	ll res=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			bool ok=true;
			for(int k=0;k<n;++k)
				if(i!=j&&i!=k&&j!=k){
					if(a[i][k]+a[k][j]<a[i][j])
						return cout<<"-1\n",0;
					if(a[i][k]+a[k][j]==a[i][j])
						ok=false;
				}
			if(ok) res+=a[i][j];
		}
	cout<<res/2<<'\n';
}


