#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int inf=1e9;
const int N=1e5+5;
int n,m,goal,f[25][25],dp[1<<21];
string s;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	goal=(1<<m)-1;
	for(int i=1;i<n;++i) f[s[i]-'a'][s[i-1]-'a']=++f[s[i-1]-'a'][s[i]-'a'];
	for(int state=1;state<(1<<m);++state){
		dp[state]=inf;
		int pos=__builtin_popcount(state);
		for(int i=0;i<m;++i) if(state>>i&1){
			int prev=dp[state^(1<<i)];
			for(int j=0;j<m;++j) if(j!=i) prev+=(state>>j&1)?f[i][j]*pos:-f[i][j]*pos;
			dp[state]=min(dp[state],prev);
		}
	}
	cout<<dp[goal];
}