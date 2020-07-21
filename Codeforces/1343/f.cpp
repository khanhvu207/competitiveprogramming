#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=222;
using Bitset=bitset<N>;

int n,res[N];
vector<int> seg[N];
Bitset suffix[N],sets[N];

bool solve(int x,int y){
	for(int i=1;i<=n;++i) suffix[i].reset();
	memset(res,-1,sizeof res);
	res[1]=x,res[2]=y;
	suffix[1].set(x),suffix[1].set(y);
	suffix[2].set(y);
	for(int i=3;i<=n;++i){
		for(int j=1;j<=n-1;++j){
			Bitset merge=suffix[1]&sets[j];
			Bitset unused=sets[j]&~merge;
			if(unused.count()!=1) continue;
			if(merge!=suffix[i-merge.count()]) return false;
			for(int k=1;k<=n;++k) if(unused[k]){
				if(res[i]!=-1&&res[i]!=k) return false;
				res[i]=k;
			}
		}
		if(res[i]==-1) return false;
		for(int j=1;j<=i;++j) suffix[j].set(res[i]);
	}
	return true;
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
		cin>>n;
		for(int i=1;i<=n-1;++i){
			seg[i].clear();
			sets[i].reset();
			int k;cin>>k;
			for(int j=0;j<k;++j){
				int x;cin>>x;
				seg[i].push_back(x);
				sets[i].set(x);
			}
		}
		for(int i=1;i<=n-1;++i) if((int)seg[i].size()==2){
			if(solve(seg[i][0],seg[i][1])) break;
			if(solve(seg[i][1],seg[i][0])) break;
		}
		for(int i=1;i<=n;++i) cout<<res[i]<<' ';
		cout<<'\n';
	}
}