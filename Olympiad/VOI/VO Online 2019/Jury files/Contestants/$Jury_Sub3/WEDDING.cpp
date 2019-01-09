#include <bits/stdc++.h>

using namespace std;

int n, mod;
vector <int> p;

void print(vector <int> x) {
    cout << x.size();
    for (auto y: x) cout << ' ' << y;
    cout << endl;
}

int invert(int x) {
    if (x == 0) return 0;
    int y = mod - 2, r = 1;
    while (y) {
        if (y & 1) r = 1ll * r * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return r;
}

int main(void) {
#ifdef THEMIS
    freopen("WEDDING.INP", "r", stdin);
    freopen("WEDDING.OUT", "w", stdout);
#endif // THEMIS

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> mod;
    p.resize(n);
    int first_non_zero = -1;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] && first_non_zero == -1) first_non_zero = i;
    }
    for (int a = 2; a < n; ++a) if (n % a == 0) {
        if (first_non_zero == -1) {
            cout << "YES" << endl;
            print(vector <int>(n / a, 0));
            print(vector <int>(a, 0));
            return 0;
        }
        else {
            int first_non_zero_block_start = first_non_zero / a * a;
            int first_non_zero_id = first_non_zero % a;
            int valid = 1, block_start = 0, id = -1;
            for (int i = 0; i < n; ++i) {
                ++id;
                if (id == a) id = 0, block_start += a;
                int lhs = 1LL * p[i] * p[first_non_zero] % mod;
                int rhs = 1LL * p[first_non_zero_block_start + id] * p[block_start + first_non_zero_id] % mod;
                if (lhs != rhs) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                cout << "YES" << endl;
                int scale = invert(p[first_non_zero]);
                vector <int> s, t;
                s.resize(n / a);
                for (int i = 0; i < n / a; ++i) s[i] = 1LL * p[i * a + first_non_zero_id] * scale % mod;
                t.resize(a);
                for (int i = 0; i < a; ++i) t[i] = p[first_non_zero_block_start + i];
                print(s);
                print(t);
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
