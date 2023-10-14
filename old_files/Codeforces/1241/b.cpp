#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		vector<int> cnta(26,0),cntb(26,0);
		for(char c:a) cnta[c-'a']++;
		for(char c:b) cntb[c-'a']++;
		bool ok=false;
		for(int i=0;i<26;++i) if(cnta[i]&&cntb[i]) ok=true;
		cout<<(ok?"YES\n":"NO\n");
	}
}