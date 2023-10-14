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
		vector<int> v(n),res(n);
		for(int& i:v) cin>>i;
		bool same=v[0]==v[n-1],chk=v[0]==v[n-1];
		for(int i=1;i<n;++i) same&=v[i]==v[i-1],chk|=v[i]==v[i-1];
		if(n%2==0||same){
			if(same){
				cout<<1<<'\n';
				for(int i=0;i<n;++i) cout<<1<<' ';
			}
			else{
				cout<<2<<'\n';
				for(int i=0;i<n;++i) cout<<(i&1?2:1)<<' ';
			}
		}
		else{
			if(chk){
				cout<<2<<'\n';
				res[0]=0;
				for(int i=1;i<n;++i) if(v[i]==v[i-1]&&chk){
					res[i]=res[i-1];
					chk=false;
				}
				else res[i]=res[i-1]^1;
			}	
			else{
				cout<<3<<'\n';
				for(int i=0;i<n-1;++i) res[i]=i&1;
				res[n-1]=2;
			}
			for(int i=0;i<n;++i) cout<<res[i]+1<<' ';
		}
		cout<<'\n';
	}
}