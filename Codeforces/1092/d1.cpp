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
	stack<int> s;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		x&=1;
		if(!s.empty()&&s.top()==x) s.pop();
		else s.push(x);
	}
	cout<<((int)s.size()<=1?"YES\n":"NO\n");
}