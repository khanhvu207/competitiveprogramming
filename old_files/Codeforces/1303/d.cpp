#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		int c[61]={0};
		ll sum=0;
		for(int i=0;i<m;++i){
			int x;
			cin>>x;
			++c[(int)log2(x)];
			sum+=x;
		}
		if(sum<n){
			cout<<"-1\n";
			continue;
		}
		int res=0;
		for(int i=0;i<60;++i){
			if(n>>i&1LL){
				if(!c[i]){
					int j=i+1;
					while(!c[j]) ++j;
					--c[j];
					for(int k=j-1;k>=i;--k){
						++c[k];
						++res;
					}
				}
				--c[i];
			}
			c[i+1]+=c[i]>>1LL;
		}
		cout<<res<<'\n';
	}
}