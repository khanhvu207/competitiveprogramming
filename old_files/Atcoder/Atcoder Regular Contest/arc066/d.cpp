#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// dp digit
// SUM=a+b, XOR=a^b
// SUM=((a&b)<<1)+XOR
//    =AND*2+XOR
//    =OR+AND (AND+XOR=OR)

const ll mod=1e9+7;
ll n,dp[65][2][2];

ll dfs(int i,int carry,bool ok){
	if(i==60) return carry==0&&ok;
	ll& res=dp[i][carry][ok];
	if(~res) return res;
	res=0;
	ll curbit=n>>i&1ll;
	for(int a=0;a<2;++a)
		for(int b=0;b<=a;++b){
			int bit=(a+b+carry)&1;
			bool isOk=ok;
			if(bit>curbit) isOk=false;
			if(bit<curbit) isOk=true;
			(res+=dfs(i+1,(a+b+carry)/2,isOk))%=mod;
		}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	memset(dp,-1,sizeof dp);
	cout<<dfs(0,0,true)<<'\n';
}

