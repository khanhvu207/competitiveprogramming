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
	string s,t;
	cin>>s>>t;
	int n=s.size();
	string z="";
	for(int i=0;i<n;++i){
		if(t[i]<=s[i]){
			z+=t[i];
			continue;
		}
		if(t[i]>s[i]){
			cout<<-1;
			return 0;
		}
	}
	cout<<z;
}