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
	int n;
	cin >> n;
	set<int> t;
	int res = 0;
	for (int i = 0; i < n * 2; ++i) {
		int x;
		cin >> x;
		if (t.find(x) == t.end()) {
			t.insert(x);
			res = max(res, (int)t.size());
		} else t.erase(x);
	}
	cout << res;
}