#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int inf=1e9;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll k;
	cin>>k;
	vector<int> d(k,inf);
	vector<bool> vst(k,false);
	deque<pair<int,int>> dq;
	d[1]=1;
	dq.emplace_back(1,d[1]);
	while(!dq.empty()){
		int u=dq.front().first;
		int cost=dq.front().second;
		dq.pop_front();
		if(cost>d[u]) continue;
		vst[u]=true;
		int nxt=(u+1)%k;
		if(!vst[nxt]&&cost+1<d[nxt]){
			d[nxt]=cost+1;
			dq.emplace_back(nxt,d[nxt]);
		}
		nxt=(u*10)%k;
		if(!vst[nxt]&&cost<d[nxt]){
			d[nxt]=cost;
			dq.emplace_front(nxt,d[nxt]);
		}
	}
	cout<<d[0]<<'\n';
}


