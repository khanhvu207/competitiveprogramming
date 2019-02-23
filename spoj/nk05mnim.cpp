#include <iostream>
using namespace std;

int n;

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		int sumxor = 0;
		bool allOne = true;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			sumxor ^= x;
			allOne &= (x == 1);
		}
		if (allOne)
			cout << ((n & 1) ? -1 : 1) << '\n';
		else
			cout << (sumxor > 0 ? 1 : -1) << '\n';
	}
}