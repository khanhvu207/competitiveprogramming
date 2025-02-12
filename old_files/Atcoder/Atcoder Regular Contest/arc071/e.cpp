#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
string s[2];
int n[2],pf[2][2][N];

void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	--a,--b,--c,--d;
	int num[2]={0};
	num[0]=pf[0][0][b]+pf[0][1][b]*2;
	if(a>0) num[0]-=pf[0][0][a-1]+pf[0][1][a-1]*2;
	num[1]=pf[1][0][d]+pf[1][1][d]*2;
	if(c>0) num[1]-=pf[1][0][c-1]+pf[1][1][c-1]*2;
//	cerr<<num[0]<<' '<<num[1]<<'\n';
	if(abs(num[0]-num[1])%3==0) cout<<"YES\n";
	else cout<<"NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s[0]>>s[1];
	n[0]=s[0].size();
	n[1]=s[1].size();
	for(int i=0;i<2;++i)
		for(char c='A';c<='B';++c)
			for(int j=0;j<n[i];++j)
				pf[i][c-'A'][j]=(j?pf[i][c-'A'][j-1]:0)+(s[i][j]==c);
	int T;
	cin>>T;
	while(T--) solve();
}


