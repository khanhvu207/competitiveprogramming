#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 4e5 + 5;
int q, x, b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q >> x;
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        ++b[n % x];
        while (ans <= i && b[ans % x] * x >= ans + 1) ++ans;
        cout << ans << '\n';
    }
}