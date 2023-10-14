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
	string s;
	cin>>s;
	int n=s.size(),res=0;
	for (int i=-1;i<n;++i){
		string t=s;
		if (i>=0) t[i]='V';
		int cnt=0;
		for(int j=0;j<n-1;++j) cnt+=t[j]=='V'&&t[j+1]=='K';
		res=max(res,cnt);
	}
	for (int i=0;i<n;++i){
		string t=s;
		t[i]='K';
		int cnt=0;
		for(int j=0;j<n-1;++j) cnt+=t[j]=='V'&&t[j+1]=='K';
		res=max(res,cnt);
	}
	cout<<res;
}