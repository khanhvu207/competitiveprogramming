// i hate this problem...

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

void solve(){
	int n,pleft,pright,one=0;
	string s;
	cin>>n>>s;
	pleft=0,pright=n-1;
	for(char c:s) one+=c=='1';
	while(pleft<n&&s[pleft]=='0') ++pleft;
	while(~pright&&s[pright]=='0') --pright;
	if(pleft==n){
		cout<<n<<'\n';
		return;
	}
	int res=n;
	int between=pright-pleft+1;
	res=max(res,pleft+n-1-pright+between+one);
	int t=max(pleft,n-1-pright);
	res=max(res,2*(t+between));
	cout<<res<<'\n';
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}