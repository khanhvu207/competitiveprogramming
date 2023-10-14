#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

int k, MOD, p[N], a[N], b[N], num;

void sub1() {
    cout << "YES\n";
    cout << 1 << " " << 1 << "\n";
    cout << k << " ";
    for(int i = 0; i < k; ++i) cout << p[i] << " ";
}

int pw(int a, int b, int p) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * r * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return r;
}
int inv(int a, int p) {
    return pw(a, p - 2, p);
}

void sub2() {
    for(int m = 1; m <= k; ++m) {
        int n = k / m;
        int pos = -1;
        for(int i = 0; i < k; ++i) if (p[i] != 0) {
            pos = i;
            break;
        }
        for(int gt = 1; gt < MOD; ++gt) {
            for(int i = 0; i < m; ++i) a[i] = -1;
            for(int j = 0; j < n; ++j) b[j] = -1;
            a[pos / n] = gt;
            b[pos % n] = (p[pos] * inv(gt, MOD)) % MOD;
            for(int j = 0; j < n; ++j) b[j] = (p[(pos / n) * n + j] * inv(a[pos / n], MOD)) % MOD;
            for(int i = 0; i < m; ++i) a[i] = (p[i * n + pos % n] * inv(b[pos % n], MOD)) % MOD;
            bool ok = true;
            for(int i = 0; i < m; ++i)
                for(int j = 0; j < n; ++j)
                    if ((a[i] * b[j] - p[i * n + j] + MOD) % MOD != 0) {
                        ok = false;
                    }
            if (ok) {
                cout << "YES\n";
                cout << m << " ";
                for(int i = 0; i < m; ++i) cout << a[i] << " ";cout << "\n";
                cout << n << " ";
                for(int j = 0; j < n; ++j) cout << b[j] << " ";
                return;
            }
        }
    }
    cout << "NO";
}
int main()
{
    #define file "WEDDING"
    freopen(file".INP", "r", stdin); freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> k >> MOD;
    for(int i = 0; i < k; ++i) {
        cin >> p[i];
        if (p[i] == 0) num++;
    }
    if (MOD == 2 || num == k) sub1();
    else
        if (k <= 12) sub2();
    return 0;
}
