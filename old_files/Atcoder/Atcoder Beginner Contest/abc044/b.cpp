#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	int cnt[26];
	memset(cnt,0,sizeof cnt);
	cin>>s;
	for(char c:s)
		cnt[c-'a']++;
	bool ok=true;
	for(int i=0;i<26;++i)
		ok&=cnt[i]%2==0&&cnt[i]>0;
	cout<<(ok?"YES\n":"NO\n");
}

