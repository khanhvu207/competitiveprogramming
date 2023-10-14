// lul :))
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,smallestPrime[500005];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i) smallestPrime[i]=1;
	for(int i=2;i*i<=n;++i) 
		if(smallestPrime[i]==1) 
			for(int j=2*i;j<=n;j+=i) 
				if(smallestPrime[j]==1) smallestPrime[j]=i;
				else smallestPrime[j]=min(smallestPrime[j],i);
	for(int i=2;i<=n;++i) if(smallestPrime[i]!=1) smallestPrime[i]=i/smallestPrime[i];
	sort(smallestPrime+1,smallestPrime+n+1);
	for(int i=2;i<=n;++i) cout<<smallestPrime[i]<<' '; 
}