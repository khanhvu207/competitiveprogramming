#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 55;

int n, k, m;
long long f[N][N][N][2], id;

long long dp(int i, int K, int M, bool zero) {
	if (f[i][K][M][zero] != -1ll) 
		return f[i][K][M][zero];
	if (i == n) 
		return (K == k) * 1ll;
	long long cnt = 0ll;
	//try 0
	if (!zero)
		cnt += dp(i + 1, K + 1, 1, true);
	else if (zero && M + 1 <= m)
		cnt += dp(i + 1, K, M + 1, true);
	//try 1
	if (zero)
		cnt += dp(i + 1, K + 1, 1, false);
	else if (!zero && M + 1 <= m)
		cnt += dp(i + 1, K, M + 1, false);
	f[i][K][M][zero] = cnt;
	return cnt;
}

void trace(int i, int K, int M, bool zero) {
	if (i == n) {
		cout << '\n';
		return;
	}
	if (!zero) {
		if (id <= dp(i + 1, K + 1, 1, true)) {
			cout << '0';
			trace(i + 1, K + 1, 1, true);
			return;
		} else
			id -= dp(i + 1, K + 1, 1, true);
	} else if (zero && M + 1 <= m) {
		if (id <= dp(i + 1, K, M + 1, true)) {
			cout << '0';
			trace(i + 1, K, M + 1, true);
			return;
		} else
			id -= dp(i + 1, K, M + 1, true);
	}
	if (zero) {
		cout << '1';
		trace(i + 1, K + 1, 1, false);
		return;
	} else if (!zero && M + 1 <= m) {
		cout << '1';
		trace(i + 1, K, M + 1, false);
		return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	freopen("mv.inp", "r", stdin);
	freopen("mv.out", "w", stdout);
	cin >> n >> k >> m;
	memset(f, -1, sizeof f);
	cout << dp(1, 1, 1, 0) << '\n';
	int s;
	cin >> s;
	while (s--) {
		string str;
		cin >> str;
		int K = 1, M = 1;
		bool zero = false;
		long long res = 0ll;
		for (int i = 1; i < n; ++i) {
			int x = str[i] - 48;
			if (x) {
				if (!zero)
					res += dp(i + 1, K + 1, 1, true);
				else if (zero && M + 1 <= m)
					res += dp(i + 1, K, M + 1, true);
			}
			K += str[i] != str[i - 1];
			M = (str[i] == str[i - 1] ? M + 1 : 1);
			zero = str[i] == '0';
		}
		cout << res + 1 << '\n'; 
	}
	int t; 
	cin >> t;
	while (t--) {
		cin >> id;
		cout << '1';
		trace(1, 1, 1, 0);
	}
}