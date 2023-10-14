#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> cnt(26,55);
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		vector<int> tmp(26,0);
		for(char j:s) tmp[j-'a']++;
		for(int j=0;j<26;++j)
			cnt[j]=min(cnt[j],tmp[j]);
	}
	for(char c='a';c<='z';++c)
		for(int i=0;i<cnt[c-'a'];++i)
			cout<<c;
	cout<<'\n';
}

