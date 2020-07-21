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
	int n,s;
	cin>>n>>s;
	if(n==1&&s==1){
		cout<<"NO\n";
		return 0;
	}
	if(s-(n-1)<=n){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i=0;i<n-1;++i) cout<<1<<' ';
	cout<<s-(n-1)<<'\n';
	cout<<n<<'\n';
}