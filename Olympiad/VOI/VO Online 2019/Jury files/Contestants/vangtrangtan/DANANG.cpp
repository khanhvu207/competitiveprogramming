#include<bits/stdc++.h>				//Written by ThiDaiLoc
using namespace std;				//Team Three Wolves
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> triple;

#define fu(i,a,b)   for(ll i=a;i<=b;i++)
#define fd(i,b,a)   for(ll i=b;i>=a;i--)
#define fuv(i,a)    for(ll i=0;i<a.size();i++)
#define fdv(i,a)    for(ll i=(ll)a.size()-1;i>=0;i--)
#define ms(a,x)     memset(a, x, sizeof a)
#define prec(n)     fixed<<setprecision(n)
#define uni(a)      (a).erase(unique(all(a)), (a).end())
#define pb(i)       push_back(i)
#define popb()      pop_back()
#define sc(a)       cin>>a
#define sc2(a,b)    cin>>a>>b
#define pr(a)       cout<<a<<endl
#define pr2(a)      cout<<a<<" "
#define bit(n,i)    (((n)>>(i))&1)
#define lowb(a,n,x) lower_bound(a,a+n,x) -a
#define lowb2(a,x)  lower_bound(all(a),x) -a.begin()
#define all(x)      (x).begin(), (x).end()
#define sz(a)       (ll)a.size()
#define le(s)       (ll)s.length()		
#define ast(x,a,b)  assert(x>=a and x<=b)				
#define re          return 	
#define	mp(a,b)     make_pair(a,b)
#define se          second
#define fi          first 
#define debug(x)    cerr << #x << " = " << x << endl
#define INPUT       freopen("DANANG.INP", "r", stdin)
#define OUTPUT      freopen("DANANG.OUT", "w", stdout)
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline ll minize(ll& a,ll b){return a=(a>b?b:a);}
inline ll maxize(ll& a,ll b){return a=(a<b?b:a);}
inline string toString(ll n) {stringstream ss; ss << n;return ss.str();}
double const eps = 1e-6;
ll const Base=1e9+7,oo=1e17,MAXN=1e6;


triple A[MAXN+5];
vi dske[MAXN+5];
bool cmp(ll a,ll b){
	re A[a].fi<A[b].fi;
}
class cmppq{	// x sumw,prevlen
	public: bool operator()(triple a, triple b){
		re a.se.fi>b.se.fi;
	}
};
pll W[MAXN+5];
ll Solves(){
	
	ll n,m,k,cnt=0,ans=0,x,y,q,c,sum=0,v,t,d;
	// PROCESS IN HERE
	cin>>n>>m>>d;
	fu(i,1,m){
		cin>>A[i].se.fi>>A[i].se.se>>A[i].fi;
		dske[A[i].se.fi].pb(i);
		dske[A[i].se.se].pb(i);
	}
	
	fu(i,1,n)sort(all(dske[i]),cmp);
	
	priority_queue<triple,vector<triple>,cmppq> pq;
	
	pq.push(mp(1,mp(0,-oo)));
	fu(i,1,n)W[i]=mp(oo,oo);
	while(sz(pq)){
		triple x=pq.top(); pq.pop();
		if(x.se.se>=W[x.fi].se)continue;
		minize(W[x.fi].fi,x.se.fi);
		minize(W[x.fi].se,x.se.se);
		if(x.fi==n)re pr(W[x.fi].fi),0;
		
		while(sz(dske[x.fi])){
			if(x.se.se+d>A[dske[x.fi].back()].fi)break;
			y=A[dske[x.fi].back()].se.fi;
			if(y==x.fi)y=A[dske[x.fi].back()].se.se;
			c=A[dske[x.fi].back()].fi;
			pq.push(mp(y,mp(x.se.fi+c,c)));
			dske[x.fi].pop_back();
		}		
	}
	
	re pr(-1),0;
	
	re 0;
	// Hack it if you can :)
}

int main(){
	INPUT;
	OUTPUT;
	ll JUDGE_ONLINE = 1;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll test=1;
//	sc(test);
	fu(T,1,test){
//		cout<<"Case #"<<T<<": ";
		Solves();
	}
	if (!JUDGE_ONLINE) cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";  
		
}
