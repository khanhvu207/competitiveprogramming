#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
int n,p,k;
ll a[N],s[N][10],f[N][130];
vector<ll> aud;
vector<int> id;

ll dp(int cur,int mask){
	if(cur==n){
		if(mask!=(1<<p)-1) return -1e16;
		return 0;
	}
	ll& res=f[cur][mask];
	if(res!=-1) return res;
	for(int i=0;i<p;++i) if(!(mask>>i&1)) res=max(res,dp(cur+1,mask|(1<<i))+s[id[cur]][i]);
	if(cur-__builtin_popcount(mask)>=k) res=max(res,dp(cur+1,mask));
	else res=max(res,dp(cur+1,mask)+a[id[cur]]);
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>p>>k;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i) for(int j=0;j<p;++j) cin>>s[i][j];
	for(int i=0;i<n;++i) id.push_back(i);
	sort(id.begin(),id.end(),[](int l,int r){return a[l]>a[r];});
	memset(f,-1,sizeof f);
	ll res=dp(0,0);
	cout<<res;
}