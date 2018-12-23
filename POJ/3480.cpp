#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int sumxor = 0;
		bool allone = true;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			sumxor ^= x;
			allone &= (x == 1);
		}
		if (allone) {
			cout << (n & 1 ? "Brother\n" : "John\n");
		} else 
			cout << (sumxor ? "John\n" : "Brother\n");
	}
}