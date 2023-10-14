#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

void solve(){
	string s;
	cin>>s;
	int one=0,zero=0,res=1e9,n=s.size();
	for(int i=0;i<n;++i) if(s[i]=='0') ++zero; else ++one;
	int curZero=0;
	for(int i=0;i<n;++i){
		if(s[i]=='0') ++curZero;
		res=min(res,i+1-curZero+zero-curZero);
		res=min(res,curZero+(one-(i+1-curZero)));
	}
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