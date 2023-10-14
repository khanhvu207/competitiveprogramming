// do O(n^2) swap and O(n) check
// UPD1: ok :/, O(n^3*log) wouldn't work (TLE)
// UPD2: i'm dumb 100

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=505;
int n,a[N],pref[N];
string s;

int count(int x,int y){
	int cnt=0;
	swap(a[x],a[y]);
	for(int i=1;i<=n;++i) pref[i]=pref[i-1]+a[i];
	int Min=*min_element(pref+1,pref+n+1);
	for(int i=1;i<=n;++i) cnt+=pref[i]==Min;
	swap(a[x],a[y]);
	return pref[n]==0?cnt:0;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>s;
	for(int i=0;i<n;++i) a[i+1]=(s[i]=='(')?1:-1;
	int res=0,x=1,y=1;
	for(int i=1;i<=n-1;++i) 
		for(int j=i+1;j<=n;++j){
			int tmp=count(i,j);
			if(tmp>res){
				res=tmp;
				x=i,y=j;
			}
		}
	cout<<res<<'\n'<<x<<' '<<y<<'\n';
	// cerr<<"Time elapsed: "<<clock()*1000/CLOCKS_PER_SEC<<'\n';
}