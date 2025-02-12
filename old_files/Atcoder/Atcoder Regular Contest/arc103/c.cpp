#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
int n,cnt[2][N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		cnt[i&1][x]++;
	}
	vector<tuple<int,int,int>> v;
	for(int i=1;i<=100000;++i){
		if(cnt[0][i]) v.emplace_back(cnt[0][i],i,0);
		if(cnt[1][i]) v.emplace_back(cnt[1][i],i,1);
	}
	sort(v.begin(),v.end(),greater<tuple<int,int,int>>());
	int c=get<1>(v[0]);
	int t=get<2>(v[0]);
	int res=n/2-get<0>(v[0]);
	bool found=false;
	for(int i=0;i<int(v.size());++i)
		if(get<1>(v[i])!=c&&get<2>(v[i])!=t){
			res+=n/2-get<0>(v[i]);
			found=true;
			break;
		}
		if(!found) res+=n/2;
	cout<<res<<'\n';
}


