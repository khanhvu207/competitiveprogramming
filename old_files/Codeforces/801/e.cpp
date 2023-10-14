// Prefix products could start with numbers which is coprime to m.
// After that, we choose one best divisors of m, and the following numbers will grow from that number.
// Calculate results using Linear Diophantine Equation?

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m,dp[N],trace[N];
bool vst[N];
set<int> s[N];

ll gcd(ll a,ll b,ll &x,ll &y){
	if(!a){
		x=0,y=1;
		return b;
	}
	ll x1,y1;
	ll d=gcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return d;
}

bool diophantine(ll a,ll b,ll c,ll &x0,ll &y0,ll &g){
	g=gcd(abs(a),abs(b),x0,y0);
	if(c%g) return false;
	x0*=c/g;
	y0*=c/g;
	if(a<0) x0=-x0;
	if(b<0) y0=-y0;
	return true;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<m;++i) s[__gcd(i,m)].insert(i);
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vst[x]=true;
		s[__gcd(x,m)].erase(x);
	}
	vector<int> prefix;
	for(int i:s[1]) prefix.push_back(i);

	int best=0,id=-1;
	for(int i=m-1;i>=2;--i){
		trace[i]=-1;
		dp[i]=(int)s[i].size();
		for(int j=2*i;j<m;j+=i)
			if(dp[j]+(int)s[i].size()>dp[i]){
				dp[i]=dp[j]+(int)s[i].size();
				trace[i]=j;
			}
		if(dp[i]>best){
			best=dp[i];
			id=i;
		}
	}
	while(id!=-1){
		for(int i:s[id]) prefix.push_back(i);
		id=trace[id];
	}
	vector<ll> res;
	if(!prefix.empty()) res.push_back(prefix[0]);
	for(int i=0;i<(int)prefix.size()-1;++i){
		ll a=prefix[i],b=-m,c=prefix[i+1],x,y,g;
		diophantine(a,b,c,x,y,g);
		ll k=(ll)floor(-x*g*1.0/b*1.0);
		res.push_back(k*b/g+x);
	}
	if(!vst[0]) res.push_back(0);
	cout<<(int)res.size()<<'\n';
	for(ll i:res) cout<<i<<' ';
}