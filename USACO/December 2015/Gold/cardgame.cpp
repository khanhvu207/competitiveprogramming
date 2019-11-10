#include <bits/stdc++.h>
using namespace std;

const int maxn = 50005;
bool used[maxn * 2];
int n, a[maxn * 2], res;
vector<int> b;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		used[a[i]] = true;
	}
	for (int i = 1; i <= 2 * n; ++i) if (!used[i]) {
		b.push_back(i);
	}
	
	sort(a, a + n / 2);
	sort(a + n / 2, a + n);
	rotate(a, a + n / 2, a + n);
	
	int j = n / 2;
	for (int i = n / 2; i < n; ++i) {
		while (j < n && b[j] < a[i]) ++j;
		if (j == n) break;
		++res;
		++j;
	}
	
	j = n / 2 - 1;
	for (int i = n / 2 - 1; i >= 0; --i) {
		while (j >= 0 && b[j] > a[i]) --j;
		if (j == -1) break;
		++res;
		--j;
	}
	
	cout << res;
	
	return 0;
}
