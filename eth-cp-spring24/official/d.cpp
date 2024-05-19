#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
template <typename T, typename... Args>
void setValues(const T& value, T& first, Args&... args) {
    first = value;
    if constexpr (sizeof...(args) > 0) {
        setValues(value, args...);
    }
}

template <typename T>
void setMax(T& target, const T& value) {
    if (value > target) {
        target = value;
    }
}

template <typename T>
void setMin(T& target, const T& value) {
    if (value < target) {
        target = value;
    }
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';
const bool is_multitest = false;

int n, m, k;
vector<pair<double, double>> fv;


void solve() {
    cin >> n >> m >> k;
    fv.resize(m, {0, 0});

    double mu = 0;
    for (int i = 0; i < m; ++i) {
        cin >> fv[i].first;
        mu += fv[i].first;
    }
    mu /= m;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        ++fv[v].second;
    }
    sort(fv.begin(), fv.end());
    int a = m;  // [f0 .. f(a-1)] < mu <= [fa .. f(m-1)]
    for (int i = 0; i < m; ++i) {
        if (fv[i].first > mu) {
            a = i;
            break;
        }
    }
    int b = m - a;
    double fa = 0, fb = 0, va = 0, vb = 0;
    double fdotv = 0;
    for (int i = 0; i < a; ++i) {
        fa += fv[i].first;
        va += fv[i].second;
        fdotv += fv[i].first * fv[i].second;
    }
    for (int i = a; i < m; ++i) {
        fb += fv[i].first;
        vb += fv[i].second;
        fdotv += fv[i].first * fv[i].second;
    }

    double ans = 0;
    
    if (k == 1) {
        cout << 1.0/m * fa * va + 1.0/m * fb * va + fdotv;
        return;
    }

    double k1 = (double)(m + b) / (m*m), k2 = 1.0/m, k3 = (double) b/(m*m), k4 = 1.0/m;

    for (int i = 2; i < k; ++i) {
        double p1, p2, p3, p4;
        if (i & 1) {  // bob
            p1 = k1 + 1.0/m * k3 * b;
            p2 = k2 + 1.0/m * k4 * b;
            p3 = 1.0/m * k3;
            p4 = 1.0/m * k4;
        } else { // alice
            p1 = 1.0/m * k1 * a;
            p2 = 1.0/m * k2 * a;
            p3 = 1.0/m * k1 * a + k3;
            p4 = 1.0/m * k2 * a + k4;
        }
        k1 = p1;
        k2 = p2;
        k3 = p3;
        k4 = p4;
    }

    cout << fixed << setprecision(10) << k1 * fa * va + k2 * fa * vb + k3 * fb * va + k4 * fb * vb << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
