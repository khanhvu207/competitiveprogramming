#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll A, B;
        cin >> A >> B;
        ll res = 0;
        ll x = 10;
        while (x - 1 <= B) {
            res += A;
            x *= 10;
        }
        cout << res << '\n';
    }
}