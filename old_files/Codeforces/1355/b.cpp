#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,cnt[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cnt[i]=0;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		++cnt[x];
	}
	ll res=0,r=0;
	for(int i=1;i<=n;++i){
		res+=(r+cnt[i])/i;
		r=(r+cnt[i])%i;
	}
	cout<<res<<'\n';
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}