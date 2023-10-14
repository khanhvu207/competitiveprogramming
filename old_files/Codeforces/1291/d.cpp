#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n, q, a[30][N];
string s;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s>>q;
	n=s.size();
	for(int i=0; i<n; ++i) for(int j=0; j<26; ++j) a[j][i]=(i?a[j][i-1]:0)+(s[i]-'a'==j);
	while(q--){
		int l, r;
		cin>>l>>r;
		--l, --r;
		bool ok=false;
		ok|=(s[l]!=s[r]);
		ok|=(l==r);
		int cnt=0;
		for(int i=0; i<26; ++i) cnt+=(a[i][r]-(l?a[i][l-1]:0)>0);
		ok|=cnt>=3;
		cout<<(ok?"Yes\n":"No\n");
	}
}