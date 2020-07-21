/*
	This seems trivial if a string consists only A and B.
*/

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
	int n;
	string s;
	cin>>n>>s;
	ll res=n*(n-1LL)/2;
	for(int j=0;j<2;++j){
		for(int i=0,cnt=0;i<n;++i)
			if(i==0||s[i]==s[i-1]) ++cnt;
			else{
				res-=cnt-j;
				cnt=1;
			}
		reverse(s.begin(),s.end());
	}
	cout<<res;
}