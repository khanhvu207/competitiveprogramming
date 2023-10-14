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
		int n;
		cin>>n;
		set<int> b;
		for(int i=1;i<=2*n;++i) b.insert(i);
		vector<int> a(n);
		for(int& x:a) cin>>x,b.erase(x);
		bool bad=false;
		vector<int> res;
		for(int x:a){
			auto it=lower_bound(b.begin(),b.end(),x+1);
			if(it==b.end()){
				bad=true;
				break;
			}
			res.push_back(x);
			res.push_back(*it);
			b.erase(x);
			b.erase(*it);
		}
		if(bad) cout<<-1;
		else for(int x:res) cout<<x<<' ';
		cout<<'\n';
	}
}