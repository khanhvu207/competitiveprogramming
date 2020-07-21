// let left[i] be the position which we stop after listening to song ai.
// construct the answer using binary search + sparse table.
// i wonder are there better alternatives? since this is dumb :/
// O(N*log(N)^2) 
//
// UPD1: 
//	since the left[i] is monotonic, we could maintain a set and run two pointer
//	hence the overall time complexity is O(n*logn).

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
int n,a[N*3],res[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		a[i+n+n]=a[i+n]=a[i];
	}
	set<pair<int,int>> s;
	for(int i=0,j=0;i<n;++i){
		while(j<i+2*n&&(s.empty()||a[j]*2+1>(*s.rbegin()).fi)){
			s.emplace(a[j],j);
			++j;
		}
		res[i]=j-i;
		if(res[i]==2*n) res[i]=-1;
		s.erase({a[i],i});
	}
	for(int i=0;i<n;++i) cout<<res[i]<<' ';
}