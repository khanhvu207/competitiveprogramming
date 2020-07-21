// dumb problem :p

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
		vector<int> a(n),pos(n+1);
		vector<bool> used(n,false);
		for(int i=0;i<n;++i){
			cin>>a[i];
			pos[a[i]]=i;
		}
		bool ok=true;
		for(int i=1,j;i<n&&ok;++i){
			j=pos[i];
			used[j]=true;
			if(j+1==n||used[j+1]) continue;
			if(!used[j+1]&&a[j+1]!=i+1) ok=false;
		}
		cout<<(!ok?"No\n":"Yes\n");
	}
}