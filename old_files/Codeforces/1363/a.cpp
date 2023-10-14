#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

void solve(){
	int n,x;
	cin>>n>>x;
	int odd=0,even=0;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		odd+=x&1;
		even+=!(x&1);
	}
	bool ok=false;
	for(int i=1;i<=x;i+=2) 
		if(i<=odd&&x-i<=even){
			ok=true;
			break;
		}
	cout<<(ok?"Yes\n":"No\n");
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