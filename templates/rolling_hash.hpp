const int N = 1e6 + 5;
const ll MOD = 1e9 + 9;
const ll MOD2 = 998244353;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base = 311;
ll base2 = rng() % 300;
ll pb[N], pb2[N];
struct double_hash {
  int sz;
  vector<ll> pref[2], suff[2];
  double_hash(string s) {
    sz = s.size();
    for (int i = 0; i < 2; ++i)
      pref[i].resize(sz + 5, 0), suff[i].resize(sz + 5, 0);
    pref[0][0] = pref[1][0] = s[0] - 'a' + 1LL;
    for (int i = 1; i < sz; ++i) {
      pref[0][i] = (pref[0][i - 1] * base % MOD + (s[i] - 'a' + 1LL)) % MOD;
      pref[1][i] = (pref[1][i - 1] * base2 % MOD2 + (s[i] - 'a' + 1LL)) % MOD2;
    }
    reverse(s.begin(), s.end());
    suff[0][0] = suff[1][0] = s[0] - 'a' + 1LL;
    for (int i = 1; i < sz; ++i) {
      suff[0][i] =
          (suff[0][i - 1] * base % MOD + (s[i] - 'a' + 1LL) % MOD) % MOD;
      suff[1][i] =
          (suff[1][i - 1] * base2 % MOD2 + (s[i] - 'a' + 1LL) % MOD2) % MOD2;
    }
  }
  pair<ll, ll> get_prefix(int l, int r) {
    ll val =
        (pref[0][r] - (l ? pref[0][l - 1] : 0LL) * pb[r - l + 1] + MOD * MOD) %
        MOD;
    ll val2 = (pref[1][r] - (l ? pref[1][l - 1] : 0LL) * pb2[r - l + 1] +
               MOD2 * MOD2) %
              MOD2;
    return pair<ll, ll>(val, val2);
  }
  pair<ll, ll> get_suffix(int l, int r) {
    l = sz - l - 1, r = sz - r - 1;
    swap(l, r);
    ll val =
        (suff[0][r] - (l ? suff[0][l - 1] : 0LL) * pb[r - l + 1] + MOD * MOD) %
        MOD;
    ll val2 = (suff[1][r] - (l ? suff[1][l - 1] : 0LL) * pb2[r - l + 1] +
               MOD2 * MOD2) %
              MOD2;
    return pair<ll, ll>(val, val2);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  pb[0] = pb2[0] = 1LL;
  for (int i = 1; i < N; ++i) {
    pb[i] = pb[i - 1] * base % MOD;
    pb2[i] = pb2[i - 1] * base2 % MOD2;
  }
}