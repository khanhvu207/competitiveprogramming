#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const ll mod=1e9+7;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<char> s(n+5),t(n+5);
	vector<vector<ll>> dp(n+5,vector<ll>(n+5));
	for(int i=1;i<=n;++i){
		cin>>s[i];
		t[i]=s[i];
	}
	for(int i=0;i<m;++i){
		int l,r;
		cin>>l>>r;
		sort(s.begin()+l,s.begin()+r+1);
		sort(t.begin()+l,t.begin()+r+1,greater<char>());
	}
	dp[0][0]=1;
	int lo=0,hi=0;
	for(int i=1;i<=n;++i){
		lo+=s[i]=='1';
		hi+=t[i]=='1';
		for(int j=lo;j<=hi;++j)
			(dp[i][j]=dp[i-1][j]+(j>0?dp[i-1][j-1]:0))%=mod;
	}
	cout<<dp[n][lo]<<'\n';
}

