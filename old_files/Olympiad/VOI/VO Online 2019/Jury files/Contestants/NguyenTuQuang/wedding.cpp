#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

typedef long long ll;
typedef pair<int, int> ii;

#define X first
#define Y second

int k;
long long MOD;
long long rev[N];
long long a[N];
void prepare() {
    cin >> k >> MOD;
    for(int i = 0; i < k; i++) cin >> a[i];
    rev[1] = 1;
    for(int i = 2; i < MOD; i++) rev[i] = MOD - (MOD / i) * rev[MOD % i] % MOD;
}

bool BFS(vector<vector<ll>> &ans, ii st) {
    
    if (ans[st.X][st.Y] == 0) return 1;
    int n = ans[0].size(), m = ans[1].size();
    queue<ii> q; 
    q.push(st);

    while (!q.empty()) {
        ii cur = q.front(); q.pop();
        if (cur.X == 0) {
            int i = cur.Y;
            for(int j = 0; j < m; j++) {
                if (a[i * m + j] == 0 && ans[0][i] == 0) continue;
                if (ans[1][j] == -1) {
                    ans[1][j] = a[i * m + j] * rev[ans[0][i]] % MOD;
                    q.push(ii(1, j));
                }
                if (ans[0][i] * ans[1][j] % MOD != a[i * m + j]) 
                    return 0;
            }
        } else {
            int j = cur.Y;
            for(int i = 0; i < n; i++) {
                if (a[i * m + j] == 0 && ans[1][j] == 0) continue;
                if (ans[0][i] == -1) {
                    ans[0][i] = a[i * m + j] * rev[ans[1][j]] % MOD;
                    q.push(ii(0, i));
                }
                if (ans[0][i] * ans[1][j] % MOD != a[i * m + j]) 
                    return 0;
            }
        }
    }
    return 1;
}
bool check(int n) {
    int m = k / n;
    vector<vector<ll>> ans = {vector<ll>(n, -1), vector<ll>(m, -1)};
    for(int i = 0; i < n; i++) if (ans[0][i] == -1) {
        ans[0][i] = 0;
        for(int j = 0; j < m; j++) if (a[i * m + j] != 0) {
            ans[0][i] = 1;
        }
        if (!BFS(ans, ii(0, i))) return 0;
    }
    for(int j = 0; j < m; j++) if (ans[1][j] == -1) {
        ans[1][j] = 0;
        for(int i = 0; i < n; i++) if (a[i * m + j] != 0) {
            ans[1][j] = 1;
        }
        if (!BFS(ans, ii(1, j))) return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            assert(ans[0][i] * ans[1][j] % MOD == a[i * m + j]);
    cout << "YES\n";
    for(int i = 0; i <= 1; i++) {
        cout << ans[i].size() << " ";
        for(auto j : ans[i]) cout << j << " ";
        cout << '\n';
    }
    return 1;
}
void solve() {
    for(int n = 2; n < k; n++) if (k % n == 0) {
        if (check(n)) return;
    }
    cout << "NO\n";
}
int main() {
    freopen("wedding.inp", "r", stdin);
    freopen("wedding.out", "w", stdout);
    prepare();
    solve();
}
