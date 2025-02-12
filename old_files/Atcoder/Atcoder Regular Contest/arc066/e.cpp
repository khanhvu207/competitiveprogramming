#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// i think we could use at most 2 nested brackets, more than 2 is unneccessary
// dp[i][j] = max answer [i..n-1] if we've opened j brackets before

const int N=1e5+5;
ll n,dp[N][3];
vector<ll> a;

ll go(int i,int br){
	if(i==n) return 0;
	ll& res=dp[i][br];
	if(~res) return res;
	res=0;
	ll val=(br&1)?-a[i]:a[i];
	res=max(res,go(i+1,br)+val);
	if(a[i]<0&&br<2) res=max(res,go(i+1,br+1)+val);
	if(br>0) res=max(res,go(i+1,br-1)+val);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	bool neg=false;
	for(int i=0;i<n+n-1;++i){
		if(i&1){
			char sign;
			cin>>sign;
			neg=sign=='-';
		}
		else{
			ll x;
			cin>>x;
			a.push_back(neg?-x:x);
			neg=false;
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<go(0,0);
}

