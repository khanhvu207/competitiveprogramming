/*
	Greedily take the lowest indices which greater then the previous one.
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
string a,b;
vector<int> v,p[30];
 
int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>a>>b;
	int n=a.size(),m=b.size();
	int res=0,l=-1,r=m;
	for(int i=0;i<n;++i) p[a[i]-'a'].push_back(i);
	for(int i=0;i<m;++i){
		int c=b[i]-'a';
		int x=i?v.back():-1;
		auto y=upper_bound(p[c].begin(),p[c].end(),x);
		if(y==p[c].end()) break;
		v.push_back(*y);
		res=i+1,l=i;
	}
	if(res==m){
		cout<<b;
		return 0;
	}
	for(int i=m-1,prev=n;~i;--i){
		int c=b[i]-'a';
		if(p[c].empty()) break;
		int y=lower_bound(p[c].begin(),p[c].end(),prev)-p[c].begin();
		if(y==(int)p[c].size()) --y;
		while(~y&&p[c][y]>=prev) --y;
		if(y==-1) break;
		int x=lower_bound(v.begin(),v.end(),p[c][y])-v.begin();
		if(x==(int)v.size()) --x;
		while(~x&&v[x]>=p[c][y]) --x;
		if(x==-1){
			if(res<m-i) res=m-i,l=-1,r=i;
		}
		else if(res<m-i+x+1){
			res=m-i+x+1;
			l=x,r=i;
		}
		prev=p[c][y];
	}
	if(res==0){
		cout<<'-';
		return 0;
	}
	for(int i=0;i<=l;++i) cout<<b[i];
	for(int i=r;i<m;++i) cout<<b[i];
}
