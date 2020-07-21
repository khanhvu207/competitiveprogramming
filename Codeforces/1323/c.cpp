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
	int total=0,res=0;
	bool bad=false;
	stack<char> s;
	cin>>n;
	for(int i=0;i<n;++i){
		char x;
		cin>>x;
		if(s.empty()){
			s.push(x);
			total+=x=='('?1:-1;
			bad|=total<0;
			continue;
		}
		if(!s.empty()&&!bad&&x==')'&&s.top()=='('){
			s.pop();
			--total;
			continue;
		}
		s.push(x);
		total+=x=='('?1:-1;
		bad|=total<0;
		if(total==0&&!s.empty()){
			res+=s.size();
			while(!s.empty()) s.pop();
			bad=false;
		}
	}
	if(total==0&&!s.empty()) res+=s.size();
	if(total!=0) cout<<-1;
	else cout<<res;
}