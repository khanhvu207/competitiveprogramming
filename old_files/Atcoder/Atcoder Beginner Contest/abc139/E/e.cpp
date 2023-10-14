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

const int N=1005;
int n;
bool used[N];
queue<int> q[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	FOR(i,1,n)
		FOR(j,1,n-1){
			int x;
			cin>>x;
			q[i].push(x);
		}
	int days=0;
	set<int> avai;
	FOR(i,1,n) avai.insert(i);
	while(true){
		bool isEmpty=true;
		FOR(i,1,n){
			isEmpty&=q[i].empty();
			if(q[i].empty()) 
				avai.erase(i);
		} 
		if(isEmpty) break;
		bool found=false;
		vector<int> chosen;
		for(int i:avai){
			if(used[i]) continue;
			int op=q[i].front();
			if(!q[op].empty()&&q[op].front()==i){
				found=true;
				chosen.pb(i);
				chosen.pb(op);
				used[i]=true;
				used[op]=true;
			}
		}
		if(!found) exit(puts("-1\n")*0);
		for(int x:chosen){
			q[x].pop();
			used[x]=false;
		}
		++days;
	}
	cout<<days<<'\n';
}

