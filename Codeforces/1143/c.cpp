#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
int n, cnt[MAXN], numChild[MAXN];
bool mark[MAXN];

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int p, x;
        cin >> p >> x;
        if (p == -1) continue;
        mark[i] = x;
        cnt[p] += x;
        numChild[p] += 1;
    }
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
        if (!mark[i] || cnt[i] != numChild[i]) continue;
        cout << i << ' ';
        ok = true;
    }
    if (!ok) cout << -1;
}