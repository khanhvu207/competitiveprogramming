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

int q;
ll summax,summin,b;
priority_queue<ll> heapmax;
priority_queue<ll, vector<ll>, greater<ll>> heapmin;
 
void clearHeaps() {
    summax = summin = 0LL;
    while (!heapmax.empty()) heapmax.pop();
    while (!heapmin.empty()) heapmin.pop();
}
 
int getMedian(ll x) {
    if (heapmax.empty() && heapmin.empty()) {
        heapmax.push(x);
        summax += x;
        return x;
    }
    ll median = heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
    if (x < median) heapmax.push(x), summax += x;
    else heapmin.push(x), summin += x;
    if (heapmax.size() > heapmin.size() + 1) {
        heapmin.push(heapmax.top());
        summin += heapmax.top();
        summax -= heapmax.top();
        heapmax.pop();
    } else if (heapmin.size() > heapmax.size() + 1) {
        heapmax.push(heapmin.top());
        summax += heapmin.top();
        summin -= heapmin.top();
        heapmin.pop();
    }
    return heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>q;
	ll median,fx;
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			ll a,yb;
			cin>>a>>yb;
			median=getMedian(a);
			b+=yb;
			fx=median*sz(heapmax)-summax+summin-median*sz(heapmin)+b;
		} else cout<<median<<' '<<fx<<'\n';
	}	

}

