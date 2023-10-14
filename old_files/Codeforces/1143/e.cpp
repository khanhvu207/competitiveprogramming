#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, q;
int a[N], b[N], prevv[N], last[N], p[30][N];
vector<pair<int, int>> Left[N];
bool res[N];

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        Left[r].push_back(make_pair(l, i));
    }
    prevv[a[0]] = a[n - 1];
    for (int i = 1; i < n; ++i) prevv[a[i]] = a[i - 1];
    memset(p, -1, sizeof p);
    memset(last, -1, sizeof last);
    for (int i = 0; i < m; ++i) {
        p[0][i] = last[prevv[b[i]]];
        last[b[i]] = i;
    }
    for (int i = 1; (1 << i) <= m; ++i) 
        for (int j = 0; j < m; ++j)
            if (p[i - 1][j] != -1) p[i][j] = p[i - 1][p[i - 1][j]];
    int low = -1;
    for (int i = 0; i < m; ++i) {
        int L = -1, t = n - 1;
        for (int j = 0; (1 << j) <= t; ++j)
            if ((t >> j) & 1) {
                if (L == -1) L = p[j][i];
                else L = p[j][L];
            }
        if (t == 0) L = b[i] == a[0] ? i : -1;
        low = max(low, L);
        for (auto it : Left[i]) 
            res[it.se] = low >= it.fi;
    }
    for (int i = 0; i < q; ++i) cout << res[i];
}