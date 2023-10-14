#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int r = n, l = -1;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		for (int i = 0; i < n; ++i) 
			if (a[i] - i < 0) {
				r = i;
				break;
			}
		for (int i = n - 1; i >= 0; --i) 
			if (a[i] - (n - i - 1) < 0) {
				l = i;
				break;
			} 
		cout << (l + 1 < r ? "Yes\n" : "No\n");
	}
}