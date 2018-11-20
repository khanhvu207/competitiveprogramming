#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, cnt[1000000], k;
pair <int, int> a[1000];

bool check(int k) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
        int x;
        for (x = a[i].first; x <= a[i].second; ++x)
            if (cnt[x] < k) {++cnt[x]; break;}
        if (x > a[i].second) return false;
    }
    return true;
}

int main() {
    freopen("start.inp", "r", stdin);
    freopen("start.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second,
        a[i].first = a[i].second - a[i].first;
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        a[i].first = a[i].second - a[i].first;
    for (int l = 1, r = n; l <= r;) {
        int m = (l + r) / 2;
        if (!check(m)) l = m + 1;
        else k = m, r = m - 1;
    }
    cout << k;
}
