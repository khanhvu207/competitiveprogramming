#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1005;
int n, choose[N];
string a[N][2];
bool vst[N];

void dfs(int u){
	vst[u]=true;
	for(int i=0; i<n; ++i) 
		if(!vst[i]&&a[u][1]==a[i][0]){
			choose[i]=1;
			dfs(i);
		}
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0; i<n; ++i){
		string s, t;
		cin>>s>>t;
		a[i][0]=s.substr(0, 3);
		a[i][1]=s.substr(0, 2)+t[0];
	}
	for(int i=0; i<n-1; ++i)
		for(int j=i+1; j<n; ++j)
			if(a[i][0]==a[j][0]) choose[i]=choose[j]=1;
	for(int i=0; i<n; ++i)
		if(choose[i]&&!vst[i]) dfs(i);
	for(int i=0; i<n-1; ++i)
		for(int j=i+1; j<n; ++j)
			if(a[i][choose[i]]==a[j][choose[j]]){
				cout<<"NO\n";
				return 0;
			}
	cout<<"YES\n";
	for(int i=0; i<n; ++i) cout<<a[i][choose[i]]<<'\n';
}