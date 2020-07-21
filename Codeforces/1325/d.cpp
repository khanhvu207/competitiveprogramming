// a+b=a^b+2*(a&b)
// unproven...

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
	ll u,v;
	cin>>u>>v;
	if(u>v||(v-u)&1){
		cout<<-1;
		return 0;
	}
	if(u==v){
		if(!u) cout<<0;
		else cout<<1<<'\n'<<u;
		return 0;
	}
	ll t=(v-u)/2;
	bool flag=false;
	vector<ll> res(4,0);
	for(ll i=0;i<60;++i){
		bool XOR=u>>i&1,AND=t>>i&1;
		if(!XOR&&!AND) continue;
		if(!AND&&XOR) res[0]|=(1LL<<i);
		if(AND&&!XOR){
			for(int j=0;j<2;++j) res[j]|=(1LL<<i);
		}
		if(AND&&XOR){
			for(int j=0;j<3;++j) res[j]|=(1LL<<i);
			flag=true;
		}
	}
	cout<<(!flag?2:3)<<'\n';
	ll xx=0LL;
	for(ll i:res) if(i>0) cout<<i<<' ';
}