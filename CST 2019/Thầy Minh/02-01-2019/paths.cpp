#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 25;

int n, s, a[2 * N][N];
long long f[2 * N][N][555];

long long dp(int i, int j, int sum) {
    //cerr << i << ' ' << j << ' ' << sum << '\n';
    if (sum < 0) return 0;
    if (f[i][j][sum] != -1) return f[i][j][sum];
    if (i == 2 * n - 1)
        return (sum == 0) * 1ll;
    f[i][j][sum] = 0;
    if (i < n) {
        if (j > 1)
            f[i][j][sum] += dp(i + 1, j - 1, sum - a[i + 1][j - 1]);
        if (j < n - i + 1)
            f[i][j][sum] += dp(i + 1, j, sum - a[i + 1][j]);
    } else {
        f[i][j][sum] += dp(i + 1, j, sum - a[i + 1][j]);
        f[i][j][sum] += dp(i + 1, j + 1, sum - a[i + 1][j + 1]);
    }
    return f[i][j][sum];
}

void trace(int i, int j, int sum) {
    if (i == 2 * n - 1) {
        cout << '\n';
        return;
    }
    if (i < n) {
        if (j > 1 && dp(i + 1, j - 1, sum - a[i + 1][j - 1]) > 0) {
            cout << 'L';
            trace(i + 1, j - 1, sum - a[i + 1][j - 1]);
            return;
        } else if (j < n - i + 1 && dp(i + 1, j, sum - a[i + 1][j]) > 0) {
            cout << 'R';
            trace(i + 1, j, sum - a[i + 1][j]);
            return;
        }
    } else {
        if (dp(i + 1, j, sum - a[i + 1][j]) > 0) {
            cout << 'L';
            trace(i + 1, j, sum - a[i + 1][j]);
            return;
        } else if (dp(i + 1, j + 1, sum - a[i + 1][j + 1]) > 0) {
            cout << 'R';
            trace(i + 1, j + 1, sum - a[i + 1][j + 1]);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("paths.inp", "r", stdin);
    freopen("paths.out", "w", stdout);
    while (cin >> n >> s) {
        if (!n && !s) return 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n - i + 1; ++j)
                cin >> a[i][j];
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                cin >> a[i + n - 1][j];
        int paths = 0;
        int start = -1;
        memset(f, -1, sizeof f);
        for (int i = 1; i <= n; ++i) {
            paths += dp(1, i, s - a[1][i]);
            if (start == -1 && dp(1, i, s - a[1][i]) > 0)
                start = i;
        }
        cout << paths << '\n';
        if (start == -1)
            continue;
        else {
            cout << start - 1 << ' ';
            trace(1, start, s - a[1][start]);
        }
    }
}
