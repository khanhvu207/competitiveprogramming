#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007;

ll is_valid(int k, int state) {
    int r = k % 4;
    if (r == 0) {
        return state == 0;
    }

    int c[4] = {0, 0, 0, 0};
    for (int i = 0; i < 10; ++i) {
        ++c[state % 4];
        state >>= 2;
    }

    if (r == 1) {
        return c[1] == 1 and c[0] == 9;
    } else if (r == 2) {
        return c[2] == 1 and c[0] == 9;
    } else {
        return (c[1] == 1 and c[2] == 1 and c[0] == 8) or (c[3] == 1 and c[0] == 9);
    }
}

int update_state(int state, int d) {
    int count = (state >> (d * 2)) & 3;
    state ^= count << (d * 2);
    count = (count + 1) % 4;
    state ^= (count << (d * 2));
    return state;
}

ll memo[18][(1 << 21) + 5];

ll dp(int r, int k, int state) {
    if (r == 0) {
        return is_valid(k, state);
    }

    ll &res = memo[r][state];
    if (res != -1) return res;
    res = 0;

    for (int d = 0; d < 10; ++d) {
        res = (res + dp(r - 1, k, update_state(state, d))) % MOD;
    }

    return res;
}

ll solve(string s) {
    if (s == "0") {
        return 0;
    }

    ll res = 0LL;
    int k = (int)s.size();

    for (int i = 1; i < k; ++i) {
        for (int d = 1; d < 10; ++d) {
            res = (res + dp(k - i - 1, k - i, update_state(0, d))) % MOD;
        }
    }

    int cur_state = 0;
    for (int i = 0; i < k; ++i) {
        int cur_d = s[i] - '0';

        for (int d = 0; d < cur_d; ++d) {
            if (i == 0 and d == 0) {
                continue;
            }

            res = (res + dp(k - i - 1, k, update_state(cur_state, d))) % MOD;
        }

        cur_state = update_state(cur_state, cur_d);
    }

    res = (res + is_valid(k, cur_state)) % MOD;
    return res;
}

string dec1(string t) {
    int i = t.size() - 1;
    while (i >= 0 && t[i] == '0') t[i--] = '9';
    if (i >= 0) --t[i];
    if (t.size() > 1 && t[0] == '0') t.erase(t.begin());
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(memo, -1, sizeof memo);

    string p, q;
    while (cin >> p >> q) {
        ll res = solve(q) - solve(dec1(p));
        if (res < 0) res += MOD;
        cout << res << "\n";
    }
    return 0;
}
