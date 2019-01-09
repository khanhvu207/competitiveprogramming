#include <bits/stdc++.h>

using namespace std;

const int hash_mod = 1007050321;
int n, mod;
vector <int> p;
vector <int> zero_pos_hash;
vector <int> ratio_hash;
vector <int> base;
vector <int> invert;

void print(vector <int> x) {
    cout << x.size();
    for (auto y: x) cout << ' ' << y;
    cout << endl;
}

int get_hash(vector <int> &h, int l, int r) { //[l..r)
    return ((h[r] - 1LL * h[l] * base[r-l]) % hash_mod + hash_mod) % hash_mod;
}

void prepare(void) {
    invert.resize(mod);
    invert[1] = 1;
    for (int i = 2; i < mod; ++i) invert[i] = mod - 1LL * (mod / i) * invert[mod % i] % mod;

    zero_pos_hash.resize(n + 1);
    zero_pos_hash[0] = 0;
    for (int i = 1; i <= n; ++i) zero_pos_hash[i] = (1LL * zero_pos_hash[i-1] * mod + (p[i-1] != 0)) % hash_mod;

    ratio_hash.resize(n + 1);
    ratio_hash[0] = 0;
    int last = 0;
    for (int i = 1; i <= n; ++i) {
        int val = 1LL * p[i-1] * last % mod;
        ratio_hash[i] = (1LL * ratio_hash[i-1] * mod + val) % hash_mod;
        if (p[i-1]) last = invert[p[i-1]];
    }

    base.resize(n + 1);
    base[0] = 1;
    for (int i = 1; i <= n; ++i) base[i] = 1LL * base[i-1] * mod % hash_mod;
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
    prepare();

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
            int valid = 1;
            int zero_pos_key = get_hash(zero_pos_hash, first_non_zero_block_start, first_non_zero_block_start + a);
            int ratio_key = get_hash(ratio_hash, first_non_zero + 1, first_non_zero_block_start + a);
            for (int i = 0; i < n / a; ++i) {
                int zero_pos_value = get_hash(zero_pos_hash, i * a, i * a + a);
                if (zero_pos_value == 0) continue; //all 0
                if (zero_pos_value != zero_pos_key) {
                    valid = 0;
                    break;
                }
                int ratio_value = get_hash(ratio_hash, i * a + first_non_zero_id + 1, i * a + a);
                if (ratio_value != ratio_key) {
                    valid = 0;
                    break;
                }
            }
            if (valid) { //potential answer, needs further checking
                int scale = invert[p[first_non_zero]];
                vector <int> s, t;
                s.resize(n / a);
                for (int i = 0; i < n / a; ++i) s[i] = 1LL * p[i * a + first_non_zero_id] * scale % mod;
                t.resize(a);
                for (int i = 0; i < a; ++i) t[i] = p[first_non_zero_block_start + i];
                int flag = 1;
                for (int i = 0; i < n; ++i) if (p[i] != 1LL * s[i / a] * t[i % a] % mod) {
                    flag = 0;
                    break;
                }
                if (flag) {
		    cout << "YES" << endl;
                    print(s);
                    print(t);
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
