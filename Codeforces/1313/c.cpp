/*
	Maintain a monotonic queue (deque) while iterate from left, and from right
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=5e5+5;
int n;
ll a[MX],prefix[MX],suffix[MX];
deque<pair<ll,int>> dq;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	ll sum=0LL;
	for(int i=0;i<n;++i){
		int cnt=1;
		while(!dq.empty()&&dq.back().fi>a[i]){
			sum-=(dq.back().fi-a[i])*dq.back().se;
			cnt+=dq.back().se;
			dq.pop_back();
		}
		sum+=a[i];
		prefix[i]=sum;
		dq.push_back({a[i],cnt});
	}		
	while(!dq.empty()) dq.pop_back();
	sum=0LL;
	for(int i=n-1;~i;--i){
		int cnt=1;
		while(!dq.empty()&&dq.back().fi>a[i]){
			sum-=(dq.back().fi-a[i])*dq.back().se;
			cnt+=dq.back().se;
			dq.pop_back();
		}
		sum+=a[i];
		suffix[i]=sum;
		dq.push_back({a[i],cnt});
	}
	while(!dq.empty()) dq.pop_back();	
	ll p=n-1,best=prefix[n-1];
	for(int i=0;i<n-1;++i) if(prefix[i]+suffix[i+1]>best){
		best=prefix[i]+suffix[i+1];
		p=i;
	}
	deque<pair<ll,int>> q;
	for(int i=0;i<=p;++i){
		int cnt=1;
		while(!q.empty()&&q.back().fi>a[i]) cnt+=q.back().se,q.pop_back();
		q.push_back({a[i],cnt});
	}
	for(auto it:q) for(int i=0;i<it.se;++i) cout<<it.fi<<' ';
	while(!q.empty()) q.pop_back();
	for(int i=n-1;i>p;--i){
		int cnt=1;
		while(!q.empty()&&q.back().fi>a[i]) cnt+=q.back().se,q.pop_back();
		q.push_back({a[i],cnt});
	}
	reverse(q.begin(),q.end());
	for(auto it:q) for(int i=0;i<it.se;++i) cout<<it.fi<<' ';
}