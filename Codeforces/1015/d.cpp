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
	ll n,k,s;
	cin>>n>>k>>s;
	if(s>(n-1LL)*k||k>s){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	int t=k;
	for(int i=0,id=1;i<t;++i){
		int d=min(n-1,s-k+1);
		id=(id+d>n)?id-d:id+d;
		cout<<id<<' ';
		s-=d,--k;
	}
}