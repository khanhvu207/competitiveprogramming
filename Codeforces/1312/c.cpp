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
		ll k;
		cin>>n>>k;
		set<int> s;
		bool bad=false;
		for(int i=0;i<n;++i){
			ll x;
			cin>>x;
			int cnt=0;
			while(x){
				if(x%k>1||(x%k==1&&s.count(cnt))){
					bad=true;
					break;
				}
				if(x%k==1) s.insert(cnt);
				++cnt;
				x/=k;
			}
		}
		cout<<(bad?"NO\n":"YES\n");
	}
}