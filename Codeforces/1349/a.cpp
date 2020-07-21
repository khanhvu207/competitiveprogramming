#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n;
vector<int> x[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i){
		int a;
		cin>>a;
		int b=a;
		for(int j=2;j*j<=b;++j) if(a%j==0){
			int tmp=1;
			while(a%j==0) a/=j,tmp*=j;
			x[j].push_back(tmp);
		}
		if(a>1) x[a].push_back(a);
	}
	ll res=1;
	for(int i=2;i<N;++i){
		if(x[i].empty()) continue;
		sort(x[i].begin(),x[i].end());
		// for(int y:x[i]) cout<<y<<' ';cout<<'\n';
		if((int)x[i].size()==n-1) res*=x[i][0];
		else if((int)x[i].size()==n) res*=x[i][1];
	}
	cout<<res;
}