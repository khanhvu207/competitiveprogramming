#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=998244353;
const int N=2e5+5;
int n;
ll pow10[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	pow10[0]=1LL;
	for(int i=1;i<N;++i) pow10[i]=pow10[i-1]*10LL%MOD;
	cin>>n;
	for(int i=1;i<n;++i){
		ll res=180LL*pow10[n-i-1]%MOD;
		(res+=(n-i-1LL)*81LL%MOD*10LL%MOD*pow10[n-i-2LL]%MOD)%=MOD;
		cout<<res<<' ';
	}
	cout<<10;
}