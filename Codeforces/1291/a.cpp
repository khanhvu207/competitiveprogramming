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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s;
		for (int i = 0; i < (int)s.size(); ++i) 
			if ((s[i] - 48) & 1) t += s[i];
		if ((int)t.size() <= 1) cout << "-1\n";
		else {
			if ((int)t.size() & 1) t = t.substr(0, (int)t.size() - 1);
			cout << t << '\n';
		}
	}
}