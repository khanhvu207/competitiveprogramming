#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> t(n+1),x(n+1),y(n+1);
	for(int i=1;i<=n;++i){
		cin>>t[i]>>x[i]>>y[i];
		int dist=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
		int T=t[i]-t[i-1];
		if(dist>T||(dist<=T&&((dist^T)&1))) 
			return cout<<"No\n",0;
	}
	cout<<"Yes\n";
}

