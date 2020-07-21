#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int K=26;
string s;
set<int> pos[K];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	for(int i=0;i<(int)s.size();++i) pos[s[i]-'a'].insert(i);
	int t;
	cin>>t;
	while(t--){
		int type;
		cin>>type;
		if(type==1){
			int x;
			char c;
			cin>>x>>c;
			--x;
			pos[s[x]-'a'].erase(x);
			s[x]=c;
			pos[c-'a'].insert(x);
		}
		else{
			int l,r,cnt=0;
			cin>>l>>r;
			--l,--r;
			for(int c=0;c<K;++c){
				auto it=pos[c].lower_bound(l);
				if(it==pos[c].end()||*it>r) continue;
				++cnt; 
			}
			cout<<cnt<<'\n';
		}
	}
}