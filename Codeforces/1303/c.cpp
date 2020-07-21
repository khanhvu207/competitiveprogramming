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
		int n=s.size();
		set<int> g[26];
		bool ok=true;
		for(int i=0;i<n;++i){
			if(i-1>=0&&s[i-1]!=s[i]) g[s[i]-'a'].insert(s[i-1]-'a');
			if(i+1<n&&s[i+1]!=s[i]) g[s[i]-'a'].insert(s[i+1]-'a');
			ok&=(int)g[s[i]-'a'].size()<=2;
		}
		if(!ok){
			cout<<"NO\n";
			continue;
		}
		int st=0;
		for(int i=0;i<26;++i) if((int)g[i].size()==1) {st=i; break;}
		bool allZero=true;
		for(int i=0;i<26;++i) allZero&=(int)g[i].size()==0;
		string res="";
		bool vst[26]={false};
		if(allZero) goto nxt;
		if((int)g[st].size()!=1){
			cout<<"NO\n";
			continue;
		}
		while(true){
			res+=char(st+'a');
			vst[st]=true;
			for(int nxt:g[st]) if(!vst[nxt]) {st=nxt; break;}
			if(vst[st]) break;
		}
		nxt:
		for(int i=0;i<26;++i) if(!vst[i]) res+=char(i+'a');
		cout<<"YES\n"<<res<<'\n';
	}
}