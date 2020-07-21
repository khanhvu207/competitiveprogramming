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
		string s;
		cin>>s;
		int p=-1,n=s.size(),res=0;
		for(int i=0;i<n;++i){
			if(s[i]=='0') continue;
			if(p!=-1) res+=i-p-1;
			p=i;
		}
		cout<<res<<'\n';
	}
}