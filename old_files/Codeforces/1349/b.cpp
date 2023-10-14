/*
	...
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
int n,k;

void solve(){
	cin>>n>>k;
	int cnt=0;
	vector<int> a(n);
	for(int& x:a){
		cin>>x;
		cnt+=x==k;
	}
	if(cnt==0){
		cout<<"no\n";
		return;
	}
	if(cnt==n){
		cout<<"yes\n";
		return;
	}
	bool ok=false;
	for(int i=0;i<n-1;++i) ok|=a[i]>=k&&a[i+1]>=k;
	for(int i=0;i<n-2;++i) ok|=a[i]>=k&&a[i+2]>=k;
	cout<<(!ok?"no\n":"yes\n");
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
	while(t--){
		solve();
	}
}