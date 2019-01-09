#include <bits/stdc++.h>
using namespace std;
const int N = 1000015;

string t, p;
int backup[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t >> p;
	int i = 0;
	int j = backup[0] = -1;
	while (i < (int)p.size()) {
		while (j >= 0 && p[i] != p[j])
			j = backup[j];
		++i, ++j;
		backup[i] = j;
	}
	i = j = 0;
	while (i < (int)t.size()) {
		while (j >= 0 && t[i] != p[j])
			j = backup[j];
		++i, ++j;
		if (j == (int)p.size()) {
			cout << i - j + 1 << ' ';
			j = backup[j];
		}
	}
}