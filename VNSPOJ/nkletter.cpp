#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < (int)a.size(); ++i) {
		string t = a.substr(i);
		if (b.find(t) == 0) {
			cout << (int)b.size() + i;
			break;
		}
	}
	return 0;
}
