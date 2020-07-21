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
	int n=s.size();
	vector<int> res;
	int l=0,r=n-1;
	while(l<r){
		while(s[r]!=')'&&r-1>=0) --r;
		while(s[l]!='('&&l+1<n) ++l;
		if(l<r) res.push_back(l),res.push_back(r);
		++l,--r;
	}
	if(res.empty()){
		cout<<0;
		return 0;
	}
	cout<<1<<'\n';
	sort(res.begin(),res.end());
	cout<<(int)res.size()<<'\n';
	for(int i:res) cout<<i+1<<' ';
}