#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll a[55];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	ll res=0;
	while(true){
		bool has=false;
		for(int i=0;i<n;++i) 
			if(a[i]>=n){
				has=true;
				ll dec=a[i]/n;
				a[i]%=n;
				for(int j=0;j<n;++j)
					if(i!=j) a[j]+=dec;
				res+=dec;
			}
		if(!has) break;
	}
	cout<<res<<'\n';
}


