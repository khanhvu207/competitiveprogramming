#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

const int T=8005;
const int MX=2*T+5;
bool dp[2][2][22222];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	int n=s.size(),x,y;
	cin>>x>>y;
	int i=0;
	while(i<n&&s[i]!='T') i++;
	x-=i;
	int j=i,token=0;
	dp[0][0][T]=dp[1][0][T]=true;
	for(;i<n;i=++j){
		token^=1;
		while(j+1<n&&s[j+1]!='T') j++;
		int len=j-i;
		for(int k=0;k<MX;++k)
			dp[token][1][k]=false;
		for(int k=0;k<MX;++k)
			if(dp[token][0][k])
				dp[token][1][k-len]=dp[token][1][k+len]=true;
		for(int k=0;k<MX;++k)
			dp[token][0][k]=dp[token][1][k];
	}
	bool res=dp[0][0][T+x]&&dp[1][0][T+y];
	cout<<(res?"Yes\n":"No\n");
}
