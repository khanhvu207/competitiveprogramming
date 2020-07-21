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
		ll a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		ll k=b/a;
		if(k&(k-1LL)||(b%a)!=0){
			cout<<-1<<'\n';
			continue;
		}
		int res=0,t=log2(k);
		res=t/3;
		t%=3;
		res+=t/2;
		t%=2;
		res+=t/1;
		cout<<res<<'\n';
	}
}