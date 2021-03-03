#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	while (cin >> n) {
		int x; 
		cin >> x;
		for (int i = 0; i < n - 1; ++i) {
			int y;
			cin >> y;
			x ^= y;
		}
		cout << (!x ? "No\n" : "Yes\n");
	}
}