#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+5;
int n,bit[N];
string s;
vector<int> pos[26];

void upd(int x){
	for(;x<N;x=x|(x+1))
		bit[x]++;
}

int get(int l,int r){
	int res=0;
	for(int x=r;x>=0;x=(x&(x+1))-1)
		res+=bit[x];
	for(int x=l-1;x>=0;x=(x&(x+1))-1)
		res-=bit[x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i)
		pos[s[i]-'a'].push_back(i);
	int odd=0;
	for(int i=0;i<26;++i)
		if(int(pos[i].size())&1) odd++;
	if((n%2==0&&odd>0)||(n%2==1&&odd!=1)) exit(puts("-1")*0);
	vector<pair<int,int>> p;
	ll res=0;
	for(int i=0;i<26;++i){
		if(pos[i].empty()) continue;
		if(int(pos[i].size())%2==1){
			int mid=pos[i][int(pos[i].size())/2];
			for(int j=0;j<26;++j)
				for(int k=0;k<int(pos[j].size())/2;++k){
					if(pos[j][k]>mid) ++res;
					if(pos[j][int(pos[j].size())-1-k]<mid) ++res;
				}
		}
		int l=0,r=pos[i].size()-1;
		while(l<r){
			p.emplace_back(pos[i][l],pos[i][r]);
			++l,--r;
		}
	}
	sort(p.begin(),p.end());
	//count number of inversions
	for(int i=0;i<int(p.size());++i){
		int l=p[i].first;
		int r=p[i].second;
		res+=2*get(0,l); //case ...A..A..B..B.
		res+=get(l,r); //case ...A..B..A..B..
		upd(r);
	}
	cout<<res<<'\n';
}


