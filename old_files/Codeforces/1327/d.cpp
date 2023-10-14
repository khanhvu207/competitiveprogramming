#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,p[N],c[N];
bool vst[N];

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
		cin>>n;
		int res=1e9;
		for(int i=1;i<=n;++i) cin>>p[i];
		for(int i=1;i<=n;++i) cin>>c[i];
		for(int i=1;i<=n;++i) vst[i]=false;
		for(int u=1;u<=n;++u) if(!vst[u]){
			int st=u;
			vector<int> cycle;
			while(!vst[st]){
				vst[st]=true;
				cycle.push_back(st);
				st=p[st];
			}
			int sz=cycle.size();
			// for(int x:cycle) cerr<<x<<' '; cerr<<'\n';
			for(int k=1;k<=sz;++k) if(sz%k==0){
				for(st=0;st<k;++st){
					bool ok=true;
					for(int pos=st;pos+k<sz;pos+=k) ok&=c[cycle[pos]]==c[cycle[pos+k]];
					if(ok){
						res=min(res,k);
						break;
					}
				}
			}
		}
		cout<<res<<'\n';
	}
}