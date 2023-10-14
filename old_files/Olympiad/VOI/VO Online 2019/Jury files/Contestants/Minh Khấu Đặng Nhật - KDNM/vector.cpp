#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int power(int a, int b) {
    if (!b) return 1;
    int res = power(a, b >> 1);
    res *= res;
    if (b & 1) res *= a;
    return res;
}

int main() {
    freopen("vector.inp", "r", stdin);
    freopen("vector.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <int> f, a, b;
    for (int x; n--;) {
        cin >> x;
        for (int i = 2; i * i <= x; ++i)
            if (x % i == 0) {
                f.push_back(i);
                while (x % i == 0)
                    a.push_back(i), x /= i;
            }
        if (x > 1) f.push_back(x), a.push_back(x);
    }
    cin >> n;
    for (int x; n--;) {
        cin >> x;
        for (int i = 2; i * i <= x; ++i)
            if (x % i == 0) {
                f.push_back(i);
                while (x % i == 0)
                    b.push_back(i), x /= i;
            }
        if (x > 1) f.push_back(x), b.push_back(x);
    }
    sort(f.begin(), f.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector <pair <int, char>> cmd;
    for (int i = 0, x, y, k, m; i < f.size(); ++i)
        if (!i || f[i - 1] < f[i]) {
            x = upper_bound(a.begin(), a.end(), f[i]) - lower_bound(a.begin(), a.end(), f[i]);
            y = upper_bound(b.begin(), b.end(), f[i]) - lower_bound(b.begin(), b.end(), f[i]);
            for (k = 0; (y + k) % 2 == 1 || ((y + k) / 2 + x) % 2 == 1; ++k);
            m = 1; for (long long tmp = f[i]; tmp <= 1e7; tmp *= f[i], ++m);
            y += k; x += y / 2; x >>= 1; y >>= 1;
            while (k) cmd.push_back({power(f[i], min(k, m)), 'D'}), k -= min(m, k);
            while (y) cmd.push_back({power(f[i], min(y, m)), 'W'}), y -= min(m, y);
            while (x) cmd.push_back({power(f[i], min(x, m)), 'L'}), x -= min(m, x);
        }
    cout << cmd.size() << '\n';
    for (auto data: cmd) cout << data.first << ' ' << data.second << '\n';
}
