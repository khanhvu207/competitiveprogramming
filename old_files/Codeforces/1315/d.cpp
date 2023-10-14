#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n;
pair<ll,ll> C[N];
map<int,int> cnt;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i) cin>>C[i].fi;
	for(int i=0;i<n;++i) cin>>C[i].se;
	sort(C,C+n,[](const pair<ll,ll>& L,const pair<ll,ll>& R){
		if(L.fi==R.fi) return L.se>R.se;
		return L.fi<R.fi;
	});
	ll res=0;
	cnt[C[0].fi]++;
	priority_queue<pair<ll,ll>> heap;
	for(int i=1;i<n;++i){
		int p=C[i-1].fi;
		while(p+1!=C[i].fi&&cnt[C[i].fi]==0&&!heap.empty()){
			++p;
			res+=(p-heap.top().se)*heap.top().fi;
			heap.pop();
		}
		// cerr<<res<<'\n';
		if(cnt[C[i].fi]>0) heap.push(make_pair(C[i].se,C[i].fi));
		else{
			cnt[C[i].fi]=1;
			if(!heap.empty()&&heap.top().fi>C[i].se){
				res+=(C[i].fi-heap.top().se)*heap.top().fi;
				heap.pop();
				heap.push(make_pair(C[i].se,C[i].fi));
			}
		}
	}
	int p=C[n-1].fi;
	while(!heap.empty()){
		++p;
		res+=(p-heap.top().se)*heap.top().fi;
		heap.pop();
	}
	cout<<res<<'\n';
}