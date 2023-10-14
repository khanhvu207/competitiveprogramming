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
		int n,k;
		set<int> s;
		cin>>n>>k;
		vector<int> a(n);
		for(int& x:a){
			cin>>x;
			s.insert(x);
		}
		if((int)s.size()>k){
			cout<<-1<<'\n';
			continue;
		}
		vector<int> res;
		for(int x:s) res.push_back(x);
		while((int)res.size()<k) res.push_back(1);
		cout<<k*n<<'\n';
		for(int i=0;i<k*n;++i) cout<<res[i%k]<<' ';
		cout<<'\n';
	}
}