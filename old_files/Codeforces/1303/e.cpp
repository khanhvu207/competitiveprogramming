#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int inf=1e9;
const int N=405;
int n,m,z,dp[N][N],nxt[N][30];
string s,t;
 
int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int q;
	cin>>q;
	while(q--){
		cin>>s>>t;
		n=s.size(),m=t.size();
		for(int i=0;i<=n;++i)
			for(int j=0;j<26;++j)
				nxt[i][j]=inf;
		for(int i=n-1;i>=0;--i){
			for(int j=0;j<26;++j) nxt[i][j]=nxt[i+1][j];
			nxt[i][s[i]-'a']=i;
		}
		bool ok=false;
		for(int i=0;i<m;++i){
			string a=t.substr(0,i);
			string b=t.substr(i,m);
			for(int j=0;j<=(int)a.size();++j)
				for(int k=0;k<=(int)b.size();++k) dp[j][k]=inf;
			dp[0][0]=0;
			for(int j=0;j<=(int)a.size();++j)
				for(int k=0;k<=(int)b.size();++k){
					if(dp[j][k]>=inf) continue;
					int len=dp[j][k];
					if(j<(int)a.size()&&nxt[len][a[j]-'a']<inf) dp[j+1][k]=min(dp[j+1][k],nxt[len][a[j]-'a']+1);
					if(k<(int)b.size()&&nxt[len][b[k]-'a']<inf) dp[j][k+1]=min(dp[j][k+1],nxt[len][b[k]-'a']+1);
				}
			ok|=(dp[(int)a.size()][(int)b.size()]<inf);
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}