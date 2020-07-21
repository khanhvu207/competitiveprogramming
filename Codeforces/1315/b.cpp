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
		ll a,b,p;
		string s;
		cin>>a>>b>>p;
		cin>>s;
		int n=s.size();
		int res=n-1;
		vector<ll> cost(n,0);
		cost[n-2]=s[n-2]=='A'?a:b;
		for(int i=n-3;i>=0;--i) cost[i]=cost[i+1]+(s[i]==s[i+1]?0:(s[i]=='A'?a:b));
		for(int i=0;i<n;++i) if(cost[i]<=p){
			res=i+1;
			break;
		}
		cout<<res<<'\n';
	}
}