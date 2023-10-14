#include <bits/stdc++.h>
using namespace std;

int n, m, best, lowPrice;
vector<int> p;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		p.push_back(x);
	}
	sort(p.rbegin(), p.rend());
	for (int i = 0; i < min((int)p.size(), n); ++i) {
		int profit = (i + 1) * p[i];
		if (profit > best) {
			best = profit;
			lowPrice = p[i];
		}
	}
	cout << lowPrice << ' ' << best << '\n';
}
