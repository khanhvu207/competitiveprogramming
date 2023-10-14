#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,k,a[N];
deque<int> dq;
set<int> s;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	k=min(k,n);
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<k;++i) if(s.find(a[i])==s.end()) dq.push_front(a[i]),s.insert(a[i]);
	for(int i=k;i<n;++i){
		if(s.find(a[i])==s.end()){
			if((int)dq.size()==k){
				s.erase(dq.back());
				dq.pop_back();
			}
			s.insert(a[i]);
			dq.push_front(a[i]);
		}
	}
	cout<<(int)dq.size()<<'\n';
	for(int x:dq) cout<<x<<' ';
}