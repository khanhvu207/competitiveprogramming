#include <bits/stdc++.h>
using namespace std;

int n;
long long h[300015];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		sum += h[i];
	}
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		sum -= h[i];
		res += sum * h[i];
	}
	cout << res;
}