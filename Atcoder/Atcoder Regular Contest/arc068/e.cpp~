#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=3e5+5;
const int M=1e5+5;
int n,m,bit[M];

void upd(int x,int val){
	for(;x<M;x=x|(x+1))
		bit[x]+=val;
}

int get(int x){
	int cnt=0;
	for(;x>=0;x=(x&(x+1))-1)
		cnt+=bit[x];
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	vector<tuple<int,int,int>> seg;
	for(int i=0;i<n;++i){
		int l,r;
		cin>>l>>r;
		seg.emplace_back(r-l+1,l,r);
	}
	sort(seg.begin(),seg.end());
	reverse(seg.begin(),seg.end());
	for(int i=1;i<=m;++i){
		while(!seg.empty()&&get<0>(seg.back())<i){
			int len,l,r;
			tie(len,l,r)=seg.back();
			seg.pop_back();
			upd(l,1);
			upd(r+1,-1);
		}
		int res=int(seg.size());
		for(int j=0;j<=m;j+=i)
			res+=get(j);
		cout<<res<<'\n';
	}
}

