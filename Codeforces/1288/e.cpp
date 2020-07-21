#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 1e6;
int n, m, prevv[N], ft[N], low[N], high[N];

void upd(int x, int v) {
    for (; x < N; x += x & (-x)) 
        ft[x] += v;
}

int get(int x) {
    int sum = 0;
    for (; x >= 1; x -= x & (-x))
        sum += ft[x];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        low[i] = high[i] = i;
        upd(i, 1);
        prevv[n - i + 1] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        low[x] = 1;
        upd(prevv[x], -1);
        upd(i + n, 1);
        int distincts = get(i + n - 1) - get(prevv[x] - 1);
        high[x] = max(high[x], distincts + 1);
        prevv[x] = i + n;
    }
    for (int i = 1; i <= n; ++i) {
        high[i] = max(high[i], n - get(prevv[i] - 1));
        cout << low[i] << ' ' << high[i] << '\n';
    }
}