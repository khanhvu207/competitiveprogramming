#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 5e6 + 5;
bool vst[maxn][2];
int t, a, b, res;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	
	cin >> t >> a >> b;
	
	if (t % a == 0 || t % b == 0) {
		cout << t;
		return 0;
	}
	
	queue<pair<int, bool>> q;
	q.push({0, 0});
	
	while (!q.empty()) {
		int cur = q.front().first;
		bool water = q.front().second;
		res = max(res, cur);
		q.pop();
		if (res == t) break;
		vst[cur][water] = true;
		if (cur + a <= t && !vst[cur + a][water]) q.push({cur + a, water});
		if (cur + b <= t && !vst[cur + b][water]) q.push({cur + b, water});
		if (!water && !vst[cur / 2][true]) q.push({cur / 2, true});
	}
	
	cout << res;
	
	return 0;
}
