#include <bits/stdc++.h>
#include <ranges>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(2 * m, vector<int>(2 * n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i + m][j] = a[i][j];
            a[i][j + n] = a[i][j];
            a[i + m][j + n] = a[i][j]; // Cost me the third prize :(
        }
    }

    for (int i = 0; i < 2 * m; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            int v = 0;
            if (i - 1 >= 0) v += a[i - 1][j];
            if (j - 1 >= 0) v += a[i][j - 1];
            if (i - 1 >= 0 and j - 1 >= 0) v -= a[i - 1][j - 1];
            a[i][j] += v;
        } 
    }

    int q;
    cin >> q;
    int cnt_r = 0, cnt_d = 0;
    for (int _ = 0; _ < q; ++_) {
        int f;
        cin >> f;
        if (f == 0) {
            int r, d;
            cin >> r >> d;
            cnt_r = (cnt_r + r) % n;
            cnt_d = (cnt_d + d) % m;
        }
        else {
            int u, v, s, t;
            cin >> u >> v >> s >> t;
            --u, --v, --s, --t;
            u += cnt_d;
            v += cnt_r;
            s += cnt_d;
            t += cnt_r;
            if (u >= m) u -= m, s -= m;
            if (v >= n) v -= n, t -= n;
            int res = a[s][t];
            if (u - 1 >= 0) res -= a[u - 1][t];
            if (v - 1 >= 0) res -= a[s][v - 1];
            if (u - 1 >= 0 and v - 1 >= 0) res += a[u - 1][v - 1];
            cout << res << '\n';
        }
    }
}

// Verdict: 7.0/7.0