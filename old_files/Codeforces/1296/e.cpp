#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int res[N], f[30], col;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	string s;
	cin>>n>>s;
	for(int i=0; i<n; ++i) {
		int t=0;
		for(int j=s[i]-'a'+1; j<=26; ++j) t=max(t, f[j]);
		col=max(col, res[i]=t+1);
		f[s[i]-'a']=max(f[s[i]-'a'], res[i]);
	}
	cout<<col<<'\n';
	for(int i=0; i<n; ++i) cout<<res[i]<<' ';
}