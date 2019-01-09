#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;

int n;
vector<pair<pair<long long, long long>, pair<long long, long long> > > s;

long long calcx(long long X) {
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		if (s[i].first.first > X)
			sum += s[i].first.first - X;
		else if (s[i].second.first < X)
			sum += X - s[i].second.first;
	return sum;
}

long long calcy(long long Y) {
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		if (s[i].first.second > Y)
			sum += s[i].first.second - Y;
		else if (s[i].second.second < Y)
			sum += Y - s[i].second.second;
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("tigersugar.inp", "r", stdin);
	freopen("tigersugar.out", "w", stdout);
	cin >> n;
	long long left, down, up, right, l = 0, r = 0, resx = 0, resy = 0;
	left = down = inf;
	right = up = 0ll;
	for (int i = 0; i < n; ++i) {
		long long xl, yl, xr, yr;
		cin >> xl >> yl >> xr >> yr;
		if (xl > xr)
			swap(xl, xr);
		if (yl > yr)
			swap(yl, yr);
		s.push_back({{xl, yl}, {xr, yr}});
		left = min(left, xl);
		right = max(right, xr);
		down = min(down, yl);
		up = max(up, yr);
	}
	l = left, r = right;
	while (r - l > 2ll) {
		long long ml = l + (r - l) / 3ll;
		long long mr = r - (r - l) / 3ll;
		if (calcx(ml) < calcx(mr)) 
			r = mr;
		else
			l = ml;
	}
	long long bestx = 1e18;
	for (long long i = l; i <= r; ++i) {
		long long x = calcx(i);
		if (x < bestx) {
			bestx = x;
			resx = i;
		}
	}
	l = down, r = up;
	while (r - l > 2ll) {
		long long ml = l + (r - l) / 3ll;
		long long mr = r - (r - l) / 3ll;
		if (calcy(ml) < calcy(mr)) 
			r = mr;
		else
			l = ml;
	}
	long long besty = 1e18;
	for (long long i = l; i <= r; ++i) {
		long long y = calcy(i);
		if (y < besty) {
			besty = y;
			resy = i;
		}
	}
	long long res = bestx + besty;
	cout << res << '\n';
	cout << resx << ' ' << resy << '\n';
	vector<long long> ansx;
	vector<long long> ansy;
	for (int i = 0; i < n; ++i)
		if (s[i].first.first > resx)
			ansx.push_back(s[i].first.first);
		else if (s[i].second.first < resx)
			ansx.push_back(s[i].second.first);
		else
			ansx.push_back(resx);
	for (int i = 0; i < n; ++i)
		if (s[i].first.second > resy)
			ansy.push_back(s[i].first.second);
		else if (s[i].second.second < resy)
			ansy.push_back(s[i].second.second);
		else
			ansy.push_back(resy);
	for (int i = 0; i < n; ++i) 
		cout << ansx[i] << ' ' << ansy[i] << '\n';
}