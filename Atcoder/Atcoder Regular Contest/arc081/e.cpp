#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF=1e8;
const int N=2e5+5;
int n,dp[N],nxt[26];
pair<int,int> trace[N];
string s;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<N;++i) 
		dp[i]=INF;
	dp[n+1]=0;
	dp[n]=1;
	for(int i=0;i<26;++i)
		nxt[i]=n+1;
	for(int i=n-1;~i;--i){
		nxt[s[i]-'a']=i+1;
		for(int j=0;j<26;++j)
			if(dp[nxt[j]]+1<dp[i]){
				dp[i]=dp[nxt[j]]+1;
				trace[i]=make_pair(j,nxt[j]);
			}
	}
	for(int i=0;i<n+1;){
		char c=trace[i].first+'a';
		cout<<c;
		i=trace[i].second;
	}
	cout<<'\n';
}


