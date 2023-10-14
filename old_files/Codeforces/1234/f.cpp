// we record unique characters by bitmasks
// alright, i looked at the solution and it was lul.

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int K=20;
const int MX=(1<<20)+5;
string s;
vector<int> Set;
bool vst[MX];
int dp[MX];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;++i){
		int r=min(n,i+K);
		int mask=0;
		for(int j=i;j<r;++j){
			int add=1<<(s[j]-'a');
			if(mask&add) break;
			mask^=add;
			if(!vst[mask]){
				Set.push_back(mask);
				vst[mask]=true;
			}
		}
	}
	int res=0,total=(1<<K)-1;
	for(int mask:Set) dp[mask]=__builtin_popcount(mask);
	for(int i=0;i<=total;++i)
		for(int j=0;j<K;++j)
			if(i>>j&1) dp[i]=max(dp[i],dp[i^(1<<j)]);
	for(int mask:Set) 
		res=max(res,dp[mask]+dp[mask^total]);
	cout<<res;
}