#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define TLE() cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms.\n";
const ll MOD = 1E9+7;
const ll IINF = 1E18;
const int INF = 1e9;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

const int N=55;
int n;
using Point=pair<double,double>; //x,y
using Circle=pair<Point,double>; //O,r
vector<Point> points;

double dist(const Point &A,const Point &B){
	return sqrt((A.fi-B.fi)*(A.fi-B.fi)+(A.se-B.se)*(A.se-B.se));
}

bool isInside(const Point &x,const Circle &c){
	return dist(x,c.fi)-c.se<=EPS;
}

Point get_center(double bx,double by,double cx,double cy){
	double B=bx*bx+by*by; 
    double C=cx*cx+cy*cy; 
    double D=bx*cy-by*cx; 
    return Point((cy*B-by*C)/(2*D),(bx*C-cx*B)/(2*D)); 
}

Circle make_circle(Point A,Point B,Point C){
	Point center=get_center(B.fi-A.fi,B.se-A.se,C.fi-A.fi,C.se-A.se);
	center.fi+=A.fi;
	center.se+=A.se;
	return Circle(center,dist(center,A));
}

Circle trivial(const vector<Point> &R){
	if(R.empty()) return Circle(Point(0,0),0);
	if(sz(R)==1) return Circle(R[0],0);
	if(sz(R)==2){
		Point midpoint=Point((R[0].fi+R[1].fi)/2.0,(R[0].se+R[1].se)/2.0);
		return Circle(midpoint,dist(midpoint,R[0]));
	}
	REP(i,3)
		FOR(j,i+1,2){
			Point midpoint=Point((R[i].fi+R[j].fi)/2.0,(R[i].se+R[j].se)/2.0);
			Circle tmp=Circle(midpoint,dist(midpoint,R[i]));
			bool ok=true;
			REP(z,3) ok&=isInside(R[z],tmp);
			if(ok) return tmp;
		}
	return make_circle(R[0],R[1],R[2]);
}

Circle welzl(int i,const vector<Point> &P,vector<Point> R){
	if(i==n||sz(R)==3) return trivial(R);
	Circle d=welzl(i+1,P,R);
	if(isInside(P[i],d)) 
		return d;
	R.pb(P[i]);
	return welzl(i+1,P,R);
}

Circle solve(const vector<Point> &P){
	vector<Point> R={};
	vector<Point> tmp=P;
	return welzl(0,tmp,R);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	REP(i,n){
		int x,y;
		cin>>x>>y;
		points.eb(x,y);
	}
	shuffle(all(points),rng);
	Circle res=solve(points);
	cout<<fixed<<setprecision(10)<<res.se<<'\n';
}

