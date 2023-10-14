// Two pointer and maintain a set to count the distinct numbers.

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e6+5;
int cnt[N];

void solve(){
	int n,k,d;
	cin>>n>>k>>d;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	set<int> s;
	for(int i=0;i<d;++i) s.insert(a[i]),cnt[a[i]]++;
	int res=(int)s.size();
	for(int i=1;i+d-1<n;++i){
		--cnt[a[i-1]];
		++cnt[a[i+d-1]];
		if(cnt[a[i-1]]==0) s.erase(a[i-1]);
		if(cnt[a[i+d-1]]==1) s.insert(a[i+d-1]);
		res=min(res,(int)s.size());
	}
	for(int& x:a) cnt[x]=0;
	cout<<res<<'\n';
}

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