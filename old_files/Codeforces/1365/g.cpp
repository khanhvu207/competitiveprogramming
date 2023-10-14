// do random_suffle and evoke queries on the first half.
// the probability of a number only resides in one half is 0.5^13 ~= 0.0001
// is it enough precision?

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(),(x).end()
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	vector<ll> res(n,0);
	vector<int> q[13],perm(13,1);
	for(int i=0;i<6;++i) perm[i]=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<13;++j) 
			if(perm[j]) q[j].push_back(i);
		next_permutation(all(perm)); // why??
	}
	for(int i=0;i<13;++i){
		if(q[i].empty()) continue;
		cout<<"? "<<(int)q[i].size()<<' ';
		for(int j:q[i]) cout<<j+1<<' ';
		cout<<endl;
		ll x;
		cin>>x;
		if(x==-1) return 0;
		for(int j=0;j<n;++j) 
			if(!binary_search(all(q[i]),j)) res[j]|=x;
	}
	cout<<"! ";
	for(ll i:res) cout<<i<<' ';
	cout<<endl;
}