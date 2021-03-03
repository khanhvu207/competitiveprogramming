#include <iostream>
#include <stack>
using namespace std;

int main() {
	freopen("514.inp", "r", stdin);
	freopen("514.out", "w", stdout);
	int n;
	cin >> n;
	while (n) {
		int a[1000];
		cin >> a[0];
		while (a[0]) {
			for (int i = 1; i < n; i++)
				cin >> a[i];

			stack<int> s;
			int right = 1;
			bool no = false;
			for (int i = 0; i < n; i++) {
				if (a[i] >= right) {
					for (int j = right; j <= a[i]; j++)
						s.push(j);
					s.pop();
					right = a[i] + 1;
				} else {
					if (!s.empty() && s.top() == a[i])
						s.pop();
					else {
						no = true;
						break;
					}
				}
			}
			cout << (no ? "No" : "Yes") << endl;

			cin >> a[0];
		}
		cout << endl;

		cin >> n;
	}
	return 0;
}