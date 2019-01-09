/*input
17 3 11
3333 1419 1097 765402162

3 2 0 5

5 2 1 2
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 6425;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}

int n, len, need;
int dp[N][N];
int sla[N][N], seq[N][N];
const int mod = 998244353;

void norm(int &X) {
	X %= mod; if (X < 0) X += mod;
}

signed main() {
#ifdef THEMIS
    freopen("SINGER.INP", "r", stdin);
    freopen("SINGER.OUT", "w", stdout);
#endif // THEMIS

#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n >> len >> need; len--;
	dp[0][0] = 1;
	sla[0][0] = 0; seq[0][0] = 0;
	loop(i, 1, n) {
		loop(j, 0, need) {
			int X = seq[i - 1][j] - (i - len >= 0 ? seq[i - len][j] : 0); norm(X);
			dp[i][j] += X % mod;
			if (i < len && j == 0) dp[i][j] += 2;
			norm(dp[i][j]);
			if (j >= 1) {
				X = (i - len >= 0 ? sla[i - len][j - 1] : 0);
				dp[i][j] += X % mod;
				if (j == i - len + 1) dp[i][j] += 2;
			}
			norm(dp[i][j]);
		}
		loop(j, 0, need) {
			sla[i][j] = (j >= 0 ? sla[i - 1][j - 1] : 0) + dp[i][j]; norm(sla[i][j]);
			seq[i][j] = seq[i - 1][j] + dp[i][j]; norm(seq[i][j]);
		}

	}
	cout << dp[n][need] << endl;
}
