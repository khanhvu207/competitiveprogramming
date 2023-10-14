#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
#ifdef	kvutxdy
	freopen("C:\\Users\\khanh\\OneDrive\\RoadtoPurple\\Code\\Codeforces\\input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool flag = false;
		for (int a = 2; a <= sqrt(n) && !flag; ++a) {
			if (n % a != 0) continue;
			int m = n / a;
			for (int b = 2; b <= sqrt(m) && !flag; ++b) {
				if (m % b != 0) continue;
				if (m != b * b && b != a && m != a * b) {
					cout << "YES\n" << a << ' ' << b << ' ' << m / b << '\n';
					flag = true;
					break;
				}
			}
		}
		if (!flag) cout << "NO\n";
	}
}