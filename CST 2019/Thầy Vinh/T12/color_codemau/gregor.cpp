// 
// 
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <climits>
#include <numeric>
#include <iomanip>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const double PI = 2.0 * acos(0.0);


typedef __int128_t ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MOD 1000000007

ll powabn(ll a, ll b,ll n) {
	ll r=1;
	while(b) {
		if(b%2) r=(r*a)%n;
		a=(a*a)%n;
		b/=2;
	}
	return r;
}

ll extGcd(ll a, ll b, ll& x, ll& y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return (b);
	}
	ll x1, y1, rst;
	rst = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return rst;
}


ll inverse(ll n){
	ll x,y;
	extGcd(n,MOD,x,y);
	while (x < 0) x+= MOD;
	return x;
}


int main(){
	int in,im,ic; cin >> in >> im >> ic;
	ll n = in, m = im, c = ic;
	c = powabn(c,n*n,MOD);
	
	ll s = 0;
	// sum up over all symmetries
	FOR(i,0,m){
		// rotate by m, i.e., every gcd(m,i)th side must be identical
		ll _x,_y;
		ll num = powabn(c,extGcd(i,m,_x,_y),MOD);
		s = (s + num) % MOD;
	}

	cout << int((inverse(m) * s) % MOD) << endl;

}
