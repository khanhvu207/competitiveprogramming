#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll la, ra, lb, rb, k, ans = 0;
    cin >> la >> ra >> lb >> rb >> k;
    if (lb < la) swap(la, lb), swap(ra, rb);
    ll L = max(la, lb), R = min(ra, rb);
    if (lb <= ra) {
        ans = R - L + 1;
        if (L <= k && k <= R) --ans;
    }
    cout << ans;
}