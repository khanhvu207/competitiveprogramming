// Compress nodes + BIT with respect to input stream positions.
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m, u[N], v[N], c[N];
vector<int> A[N], ft[N];

void upd(int id, int x, int val) {
    for(; x < (int)ft[id].size(); x += x & (-x))
        ft[id][x] = max(ft[id][x], val);
}

int get(int id, int x) {
    int res = 0;
    for(; x > 0; x -= x & (-x))
        res = max(res, ft[id][x]);
    return res;
}

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> c[i];
        A[v[i]].push_back(c[i]);
    }
    for (int i = 1; i <= 1e5; ++i) {
        sort(A[i].begin(), A[i].end());
        ft[i].resize(A[i].size() + 5, 0);
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int pos = upper_bound(A[u[i]].begin(), A[u[i]].end(), c[i]) - A[u[i]].begin() + 1;
        int len = 1 + get(u[i], pos - 1);
        res = max(res, len);
        pos = lower_bound(A[v[i]].begin(), A[v[i]].end(), c[i]) - A[v[i]].begin() + 1;
        upd(v[i], pos, len);
    }
    cout << res;
}