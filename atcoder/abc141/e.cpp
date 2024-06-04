#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "../../debug.h"
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
bool chMax(T& target, const T& value) {
    if (value > target) {
        target = value;
        return true;
    }
    return false;
}

template <typename T>
bool chMin(T& target, const T& value) {
    if (value < target) {
        target = value;
        return true;
    }
    return false;
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';
const bool is_multitest = false;

namespace stringAlgo {
const int N = 1e6 + 5;
const ll MOD = 1e9 + 9;
const ll MOD2 = 998244353;

class DoubleRollingHash {
   private:
    int sz;
    vector<ll> pref[2], suff[2];

    static ll base;
    static ll base2;
    static vector<ll> pb;
    static vector<ll> pb2;
    static bool initialized;

    static void init_powers() {
        if (initialized) return;
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        base = 311;
        base2 = rng() % 300;
        pb.resize(N, 1LL);
        pb2.resize(N, 1LL);
        for (int i = 1; i < N; ++i) {
            pb[i] = pb[i - 1] * base % MOD;
            pb2[i] = pb2[i - 1] * base2 % MOD2;
        }
        initialized = true;
    }

   public:
    DoubleRollingHash(const string& s) {
        init_powers();
        sz = (int)s.size();
        for (int i = 0; i < 2; ++i) {
            pref[i].resize(sz + 5, 0);
            suff[i].resize(sz + 5, 0);
        }
        init(s);
    }

    void init(const string& s) {
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        pref[0][0] = pref[1][0] = s[0] - 'a' + 1LL;
        suff[0][0] = suff[1][0] = reversed_s[0] - 'a' + 1LL;
        for (int i = 1; i < sz; ++i) {
            pref[0][i] = (pref[0][i - 1] * base % MOD + (s[i] - 'a' + 1LL)) % MOD;
            pref[1][i] = (pref[1][i - 1] * base2 % MOD2 + (s[i] - 'a' + 1LL)) % MOD2;
            suff[0][i] = (suff[0][i - 1] * base % MOD + (reversed_s[i] - 'a' + 1LL)) % MOD;
            suff[1][i] = (suff[1][i - 1] * base2 % MOD2 + (reversed_s[i] - 'a' + 1LL)) % MOD2;
        }
    }

    pair<ll, ll> hashPrefix(int l, int r) {
        ll val = (pref[0][r] - (l ? pref[0][l - 1] * pb[r - l + 1] % MOD : 0LL) + MOD) % MOD;
        ll val2 = (pref[1][r] - (l ? pref[1][l - 1] * pb2[r - l + 1] % MOD2 : 0LL) + MOD2) % MOD2;
        return {val, val2};
    }

    pair<ll, ll> hashSuffix(int l, int r) {
        l = sz - l - 1;
        r = sz - r - 1;
        swap(l, r);
        ll val = (suff[0][r] - (l ? suff[0][l - 1] * pb[r - l + 1] % MOD : 0LL) + MOD) % MOD;
        ll val2 = (suff[1][r] - (l ? suff[1][l - 1] * pb2[r - l + 1] % MOD2 : 0LL) + MOD2) % MOD2;
        return {val, val2};
    }
};

ll DoubleRollingHash::base;
ll DoubleRollingHash::base2;
vector<ll> DoubleRollingHash::pb;
vector<ll> DoubleRollingHash::pb2;
bool DoubleRollingHash::initialized = false;
}  // namespace stringAlgo

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stringAlgo::DoubleRollingHash dh(s);

    int res = 0;
    const pair<ll, ll> nil = {-1, -1};
    for (int len = 1; len * 2 <= n; ++len) {
        vector<pair<ll, ll>> h(n, nil);
        for (int i = 0; i + len - 1 < n; ++i) {
            h[i] = dh.hashPrefix(i, i + len - 1);
        }

        set<pair<ll, ll>> s;
        for (int i = n - len; i >= 0; --i) {
            if (h[i + len] != nil) {
                s.emplace(h[i + len]);
            }

            if (s.find(h[i]) != s.end()) {
                chMax(res, len);
                break;
            }
        }
    }

    cout << res << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
