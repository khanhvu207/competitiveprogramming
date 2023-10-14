#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int mod(int x,int MOD){
	if(x>0) return x%MOD;
	x+=(-x/MOD)*MOD+MOD;
	return x%MOD;
}

const int MX=2e5+5;
bool used[MX];

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
		bool ok=true;
		for(int i=0;i<n;++i) used[i]=false;
		for(int i=0;i<n;++i){
			int x;
			cin>>x;
			x=mod(x+i,n);
			if(used[x]) ok=false;
			used[x]=true;
		}
		cout<<(!ok?"NO\n":"YES\n");
	}
}