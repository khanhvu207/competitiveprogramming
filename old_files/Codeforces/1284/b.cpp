#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const int N = 1e6 + 5;
ll n, a[N], b[N];
ll ans, aux;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);  
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        int l, mn = 1e6 + 1, mx = -1;
        std::cin >> l;
        for (int j = 0; j < l; ++j) {
            int x;
            std::cin >> x;
            ++x;
            if (x > mn) flag = true;
            mn = std::min(mn, x);
            mx = std::max(mx, x);
        }
        if (flag) b[i] = 1000004, ++a[0];
        else b[i] = mx, ++a[mn];
    }
    for (int i = 1; i <= 1000004; ++i) a[i] += a[i - 1];
    for (int i = 0; i < n; ++i) {
        ans += a[b[i] - 1];
    }
    std::cout << ans << '\n';
}