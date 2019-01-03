#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1015;

int fenwick[N];
vector<pair<int, int> > a;

void update(int x, int v) {
    for (; x; x -= x & (-x))
        fenwick[x] = max(fenwick[x], v);
}

int get(int x) {
    int ans = 0;
    for (; x <= 1000; x += x & (-x))
        ans = max(ans, fenwick[x]);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("pick.inp", "r", stdin);
    freopen("pick.out", "w", stdout);
    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == -1 && y == -1)
            return 0;
        a.clear();
        a.push_back({x, y});
        memset(fenwick, 0, sizeof fenwick);
        while (true) {
            cin >> x >> y;
            if (!x && !y) break;
            a.push_back({x, y});
        }
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            int x = get(a[i].second + 1) + 1;
            res = max(res, x);
            update(a[i].second, x);
        }
        cout << res << '\n';
    }
}
