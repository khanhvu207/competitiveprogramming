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
#define INPUT       freopen("TIGERSUGAR.INP", "r", stdin)
#define OUTPUT      freopen("TIGERSUGAR.OUT ", "w", stdout)
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline ll minize(ll& a,ll b){return a=(a>b?b:a);}
inline ll maxize(ll& a,ll b){return a=(a<b?b:a);}
inline string toString(ll n) {stringstream ss; ss << n;return ss.str();}
double const eps = 1e-6;
ll const Base=1e9+7,oo=1e17,MAXN=1e6;



class X{
	public: ll xy1[2],xy2[2];	//xy1[0] =x1, xy1[1]= y1
};
class cmp{
	public: bool operator()(ll a,ll b){
		return a>b;
	}
};
bool cmpx(X a,X b){
	return a.xy1[0]<b.xy1[0];
}
bool cmpy(X a,X b){
	return a.xy1[1]<b.xy1[1];
}
X A[MAXN+5];
ll Solves(){
	
	ll n,m,cnt=0,ans[2]={oo,oo},ansc[2]={oo,oo},x,y,q,c,sum=0,v,t,p,l=0,r;
	// PROCESS IN HERE
	sc(n);
	fu(i,1,n){
		cin>>A[i].xy1[0]>>A[i].xy1[1]>>A[i].xy2[0]>>A[i].xy2[1];
		if(A[i].xy1[0]>A[i].xy2[0])swap(A[i].xy1[0],A[i].xy2[0]);
		if(A[i].xy1[1]>A[i].xy2[1])swap(A[i].xy1[1],A[i].xy2[1]);
	}
	
	fu(k,0,1){
		vi vec;
		fu(i,1,n)vec.pb(A[i].xy1[k]),vec.pb(A[i].xy2[k]);
		sort(A+1,A+1+n,(k?cmpy:cmpx));
		sort(all(vec));
		uni(vec);
		priority_queue<ll,vi,cmp> pq;
		p=1;
		ll sumdisl=0,sumdisr=0; l=0;
		fu(i,1,n)sumdisr+=A[i].xy1[k];
		fuv(i,vec){
			while(sz(pq) and pq.top()<vec[i])sumdisl+=pq.top(),pq.pop(),l++;
			while(p<=n and A[p].xy1[k]<=vec[i])sumdisr-=A[p].xy1[k],pq.push(A[p++].xy2[k]);
			if(vec[i]*l-sumdisl+sumdisr-vec[i]*(n-l-sz(pq))<ansc[k]){
				assert(vec[i]*l-sumdisl+sumdisr-vec[i]*(n-l-sz(pq))>=0);
				ansc[k]=vec[i]*l-sumdisl+sumdisr-vec[i]*(n-l-sz(pq));
				ans[k]=vec[i];
			}
			
		}				
	}
	
	cout<<ansc[0]+ansc[1]<<endl;
	cout<<ans[0]<<" "<<ans[1]<<endl;
	fu(i,1,n){
		if(A[i].xy1[0]>ans[0])pr2(A[i].xy1[0]);
		else if(A[i].xy2[0]<ans[0])pr2(A[i].xy2[0]);
		else pr2(ans[0]);
		
		if(A[i].xy1[1]>ans[1])pr(A[i].xy1[1]);
		else if(A[i].xy2[1]<ans[1])pr2(A[i].xy2[1]);
		else pr(ans[1]);
	}
	
	

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
