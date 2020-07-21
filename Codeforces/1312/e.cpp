/*
	Wait, is this stack O(n)?
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	vector<int> a(n+1),dp(n+1,1111);
	for(int i=1;i<=n;++i) cin>>a[i];
	dp[0]=0;
	for(int i=1;i<=n;++i){
		stack<int> s;
		for(int j=i;j>=1;--j){
			int x=a[j];
			while(!s.empty()&&s.top()==x){
				s.pop();
				++x;
			}
			s.push(x);
			dp[i]=min(dp[i],dp[j-1]+(int)s.size());
		}
	}
	cout<<dp[n];
}