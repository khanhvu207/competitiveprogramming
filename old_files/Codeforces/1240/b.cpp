// ... okay I looked at the sol and it was incredible
// 

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int inf=1e9;
const int N=3e5+5;
int l[N],r[N],dp[N];

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& i:a) cin>>i;
	for(int i=1;i<=n;++i) l[i]=inf,r[i]=-inf,dp[i]=0;
	for(int i=0;i<n;++i){
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	int res=0;
	for(int i=(int)a.size()-1;~i;--i){
		dp[i]=(i==n-1||r[a[i]]>=l[a[i+1]])?1:dp[i+1]+1;
		res=max(res,dp[i]);
	}
	cout<<(int)a.size()-res<<'\n';
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