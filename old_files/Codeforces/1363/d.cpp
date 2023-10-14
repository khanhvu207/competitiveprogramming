// divide and conquer
// split those subsets into 2 parts, and check where the maximum number lays within.
// UPD1: several dumb mistakes >w<
// UPD2: i thought the max always equal to n??

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int N=1005;
int n,k;
vector<int> s[N];
int res[N];

int query(int l,int r){
	set<int> q;
	for(int i=l;i<=r;++i) for(int x:s[i]) q.insert(x);
	cout<<"? "<<(int)q.size()<<' ';
	for(int x:q) cout<<x<<' ';
	cout<<endl;
	int mx;
	cin>>mx;
	return mx;
}

int exc(int id){
	set<int> q;
	for(int i=1;i<=n;++i) q.insert(i);
	for(int x:s[id]) q.erase(x);
	cout<<"? "<<(int)q.size()<<' ';
	for(int x:q) cout<<x<<' ';
	cout<<endl;
	int mx;
	cin>>mx;
	return mx;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=k;++i){
		int c;
		cin>>c;
		s[i].clear();
		for(int j=1;j<=c;++j){
			int x;
			cin>>x;
			s[i].push_back(x);
		}
	}
	s[k+1].clear();
	for(int i=1;i<=n;++i) s[k+1].push_back(i);
	int mx=query(k+1,k+1);
	fill(res+1,res+k+1,mx);
	int l=1,r=k;
	while(l<r){
		int m=(l+r)>>1;
		int y=query(l,m);
		if(y!=mx) l=m+1;
		else r=m;
	}
	res[l]=exc(l);
	cout<<"! ";
	for(int i=1;i<=k;++i) cout<<res[i]<<' ';
	cout<<endl;
	string rep;
	cin>>rep;
	if(rep=="Incorrect")
		exit(1);
}
//1 5 3 7 2 6 4
int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}