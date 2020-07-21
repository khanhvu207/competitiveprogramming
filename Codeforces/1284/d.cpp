// Sweep line & check...

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, xa[N], ya[N], xb[N], yb[N];
vector<pair<int, int>> ev;
multiset<int> L, R;

bool cmp(const pair<int, int>& l, const pair<int, int>& r) {
    if (l.fi == r.fi) return l.se > r.se;
    return l.fi < r.fi;
}

void solve() {
    L.clear(), R.clear();
    for (auto i : ev) {
        if (i.se > 0) {
            bool bad = false;
            bad |= !R.empty() && xb[i.se] > *R.begin();
            bad |= !L.empty() && yb[i.se] < *L.rbegin();
            if (bad) {
                cout << "NO\n";
                exit(0);
            }
            R.insert(yb[i.se]);
            L.insert(xb[i.se]);
        }
        else {
            R.erase(R.lower_bound(yb[-i.se]));
            L.erase(L.lower_bound(xb[-i.se]));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
    }
    for (int i = 1; i <= n; ++i) {
        ev.push_back(pair<int, int>(xa[i], i));
        ev.push_back(pair<int, int>(ya[i], -i));
    }
    sort(ev.begin(), ev.end(), cmp);
    solve();
    ev.clear();
    for (int i = 1; i <= n; ++i) {
        swap(xa[i], xb[i]);
        swap(ya[i], yb[i]);
        ev.push_back(pair<int, int>(xa[i], i));
        ev.push_back(pair<int, int>(ya[i], -i));
    }
    sort(ev.begin(), ev.end(), cmp);
    solve();
    cout << "YES\n";
}